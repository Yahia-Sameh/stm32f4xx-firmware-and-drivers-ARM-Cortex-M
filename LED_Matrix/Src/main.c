#include "led_matrix.h"

// Helper macro for GPIO pin operations
#define GPIO_PIN_SET(port, pin)    (port)->BSRR = (1 << (pin))
#define GPIO_PIN_RESET(port, pin)  (port)->BSRR = (1 << ((pin) + 16))
#define GPIO_PIN_READ(port, pin)   (((port)->IDR >> (pin)) & 0x1)

void LEDMX_Init(LED_Matrix* matrix) {
    // Enable GPIO clocks
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOBEN;

    // Initialize all rows as outputs (set to low)
    for (int i = 0; i < MATRIX_ROWS; i++) {
        // Set mode to output
        matrix->row_ports[i]->MODER &= ~(0x3 << (2 * matrix->row_pins[i]));
        matrix->row_ports[i]->MODER |= (GPIO_MODE_OUTPUT << (2 * matrix->row_pins[i]));

        // Set output type to push-pull
        matrix->row_ports[i]->OTYPER &= ~(1 << matrix->row_pins[i]);

        // Set high speed
        matrix->row_ports[i]->OSPEEDR |= (0x3 << (2 * matrix->row_pins[i]));

        // Initially set low
        GPIO_PIN_RESET(matrix->row_ports[i], matrix->row_pins[i]);
    }

    // Initialize all columns as outputs (set to high)
    for (int i = 0; i < MATRIX_COLS; i++) {
        // Set mode to output
        matrix->col_ports[i]->MODER &= ~(0x3 << (2 * matrix->col_pins[i]));
        matrix->col_ports[i]->MODER |= (GPIO_MODE_OUTPUT << (2 * matrix->col_pins[i]));

        // Set output type to push-pull
        matrix->col_ports[i]->OTYPER &= ~(1 << matrix->col_pins[i]);

        // Set high speed
        matrix->col_ports[i]->OSPEEDR |= (0x3 << (2 * matrix->col_pins[i]));

        // Initially set high (active low)
        GPIO_PIN_SET(matrix->col_ports[i], matrix->col_pins[i]);
    }

    // Initialize variables
    matrix->current_row = 0;
    LEDMX_Clear(matrix);
}

void LEDMX_Clear(LED_Matrix* matrix) {
    for (int i = 0; i < MATRIX_ROWS; i++) {
        matrix->buffer[i] = 0x00;
    }
}

void LEDMX_SetPixel(LED_Matrix* matrix, uint8_t x, uint8_t y, uint8_t state) {
    if (x >= MATRIX_COLS || y >= MATRIX_ROWS) return;

    if (state) {
        matrix->buffer[y] |= (1 << x);
    } else {
        matrix->buffer[y] &= ~(1 << x);
    }
}

void LEDMX_Refresh(LED_Matrix* matrix) {
    // Turn off current row
    GPIO_PIN_RESET(matrix->row_ports[matrix->current_row], matrix->row_pins[matrix->current_row]);

    // Move to next row
    matrix->current_row = (matrix->current_row + 1) % MATRIX_ROWS;

    // Set columns for new row
    for (int col = 0; col < MATRIX_COLS; col++) {
        if (matrix->buffer[matrix->current_row] & (1 << col)) {
            GPIO_PIN_RESET(matrix->col_ports[col], matrix->col_pins[col]); // Active low
        } else {
            GPIO_PIN_SET(matrix->col_ports[col], matrix->col_pins[col]);
        }
    }

    // Enable new row
    GPIO_PIN_SET(matrix->row_ports[matrix->current_row], matrix->row_pins[matrix->current_row]);
}

void LEDMX_LoadFrame(LED_Matrix* matrix, const uint8_t frame[MATRIX_ROWS]) {
    for (int i = 0; i < MATRIX_ROWS; i++) {
        matrix->buffer[i] = frame[i];
    }
}
int main(){
	while(1);




}
