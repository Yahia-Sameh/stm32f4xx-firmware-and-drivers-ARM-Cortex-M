#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

/* Instruction type definitions */
typedef enum {
    TYPE_MOV_IMM,              // MOV Rd, #imm
    TYPE_MOV_REG,              // MOV Rd, Rm
    TYPE_DATA_PROCESSING_REG,  // Rd, Rn, Rm
    TYPE_DATA_PROCESSING_IMM,  // Rd, Rn, #imm
    TYPE_CMP_REG,              // Rn, Rm
    TYPE_CMP_IMM,              // Rn, #imm
    TYPE_MUL,                  // Rd, Rm, Rs
    TYPE_BRANCH,               // label
    TYPE_SWI,                  // #imm
    TYPE_SHIFT_IMM             // Rd, Rm, #imm (LSL/LSR)
} InstructionType;

/* Instruction structure */
typedef struct {
    const char *mnemonic;
    unsigned int opcode_base;
    InstructionType type;
} Instruction;

/* ARM instruction set */
static const Instruction instructions[] = {
    {"MOV", 0xE3A00000, TYPE_MOV_IMM},
    {"MOV", 0xE1A00000, TYPE_MOV_REG},
    {"ADD", 0xE0800000, TYPE_DATA_PROCESSING_REG},
    {"ADD", 0xE2800000, TYPE_DATA_PROCESSING_IMM},
    {"SUB", 0xE0400000, TYPE_DATA_PROCESSING_REG},
    {"SUB", 0xE2400000, TYPE_DATA_PROCESSING_IMM},
    {"CMP", 0xE1500000, TYPE_CMP_REG},
    {"CMP", 0xE3500000, TYPE_CMP_IMM},
    {"AND", 0xE0000000, TYPE_DATA_PROCESSING_REG},
    {"AND", 0xE2000000, TYPE_DATA_PROCESSING_IMM},
    {"ORR", 0xE1800000, TYPE_DATA_PROCESSING_REG},
    {"ORR", 0xE3800000, TYPE_DATA_PROCESSING_IMM},
    {"EOR", 0xE0200000, TYPE_DATA_PROCESSING_REG},
    {"EOR", 0xE2200000, TYPE_DATA_PROCESSING_IMM},
    {"LSL", 0xE1A00000, TYPE_SHIFT_IMM},
    {"LSR", 0xE1A00000, TYPE_SHIFT_IMM},
    {"MUL", 0xE0000090, TYPE_MUL},
    {"BGE", 0xDA000000, TYPE_BRANCH},
    {"BLT", 0xBA000000, TYPE_BRANCH},
    {"B",   0xEA000000, TYPE_BRANCH},
    {"SWI", 0xEF000000, TYPE_SWI},
    {NULL, 0, 0}  // Sentinel
};

/* Symbol table implementation */
#define MAX_SYMBOLS 100

typedef struct {
    char *label;
    int address;
} Symbol;

static Symbol symbol_table[MAX_SYMBOLS];
static int symbol_count = 0;

void add_symbol(const char *label, int address) {
    if (symbol_count < MAX_SYMBOLS) {
        symbol_table[symbol_count].label = strdup(label);
        symbol_table[symbol_count].address = address;
        symbol_count++;
    }
}

int get_symbol_address(const char *label) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i].label, label) == 0) {
            return symbol_table[i].address;
        }
    }
    return -1;  // Not found
}

/* Helper functions */
int get_register_num(const char *reg_str) {
    if (reg_str != NULL && (reg_str[0] == 'R' || reg_str[0] == 'r')) {
        return atoi(reg_str + 1);
    }
    return -1;  // Invalid register
}

int parse_immediate(const char *imm_str) {
    if (imm_str != NULL && imm_str[0] == '#') {
        return atoi(imm_str + 1);
    }
    return -1;  // Not an immediate value
}

bool is_register(const char *str) {
    if (str == NULL || strlen(str) < 2 || (str[0] != 'R' && str[0] != 'r')) {
        return false;
    }

    for (int i = 1; i < (int)strlen(str); i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }

    int reg_num = atoi(str + 1);
    return reg_num >= 0 && reg_num <= 15;
}

void preprocess_line(char *line) {
    // Remove comments
    char *comment_start = strchr(line, '@');
    if (comment_start != NULL) {
        *comment_start = '\0';
    }

    // Trim trailing whitespace
    int len = strlen(line);
    while (len > 0 && isspace(line[len - 1])) {
        line[--len] = '\0';
    }
}

/* Main assembler functions */
void first_pass(FILE *input_file) {
    char line[256];
    int current_address = 0;

    while (fgets(line, sizeof(line), input_file) != NULL) {
        preprocess_line(line);
        if (strlen(line) == 0) continue;

        char *temp = strdup(line);
        char *token = strtok(temp, " \t");

        if (token != NULL && token[strlen(token) - 1] == ':') {
            // Found a label
            token[strlen(token) - 1] = '\0';
            add_symbol(token, current_address);
        } else {
            // Instruction - increment address
            current_address += 4;
        }

        free(temp);
    }
}

void assemble_instruction(const char *mnemonic, char **args, int arg_count,
                         int current_address, FILE *output_file) {
    unsigned int machine_code = 0;
    bool instruction_found = false;

    for (int i = 0; instructions[i].mnemonic != NULL; i++) {
        if (strcmp(instructions[i].mnemonic, mnemonic) == 0) {
            InstructionType type = instructions[i].type;
            machine_code = instructions[i].opcode_base;

            switch (type) {
                case TYPE_MOV_IMM:
                    if (arg_count >= 2 && parse_immediate(args[1]) != -1) {
                        int rd = get_register_num(args[0]);
                        int imm = parse_immediate(args[1]);
                        machine_code |= (rd << 12) | (imm & 0xFF);
                        instruction_found = true;
                    }
                    break;

                case TYPE_MOV_REG:
                    if (arg_count >= 2 && is_register(args[1])) {
                        int rd = get_register_num(args[0]);
                        int rm = get_register_num(args[1]);
                        machine_code |= (rd << 12) | (rm & 0xF);
                        instruction_found = true;
                    }
                    break;

                // ... other instruction type cases ...
                // (Similar structure for other instruction types)

                default:
                    break;
            }

            if (instruction_found) break;
        }
    }

    if (instruction_found) {
        fprintf(output_file, "%08X\n", machine_code);
    } else {
        fprintf(stderr, "Error: Unknown instruction or syntax error for '%s'\n", mnemonic);
    }
}

void second_pass(FILE *input_file, FILE *output_file) {
    char line[256];
    int current_address = 0;

    while (fgets(line, sizeof(line), input_file) != NULL) {
        preprocess_line(line);
        if (strlen(line) == 0) continue;

        char *temp = strdup(line);
        char *token = strtok(temp, " \t");

        // Skip labels (already processed in first pass)
        if (token[strlen(token) - 1] == ':') {
            free(temp);
            continue;
        }

        // Parse instruction and arguments
        char *mnemonic = token;
        char *args[4] = {0};
        int arg_count = 0;

        token = strtok(NULL, " \t,");
        while (token != NULL && arg_count < 4) {
            args[arg_count++] = token;
            token = strtok(NULL, " \t,");
        }

        assemble_instruction(mnemonic, args, arg_count, current_address, output_file);
        current_address += 4;
        free(temp);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file.text> <output_file.text>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        return 1;
    }

    // First pass - build symbol table
    first_pass(input_file);
    rewind(input_file);

    // Second pass - generate machine code
    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        perror("Error opening output file");
        fclose(input_file);
        return 1;
    }

    second_pass(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    printf("Assembly completed successfully!\n");
    return 0;
}
