
# ARM Cortex-M Bare-Metal Drivers

![ARM Cortex-M](https://img.shields.io/badge/ARM-Cortex--M-0091BD.svg)
![STM32](https://img.shields.io/badge/STM32F401-Bare--Metal-03234B.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)

A collection of bare-metal drivers and firmware for ARM Cortex-M microcontrollers, written from scratch without HAL libraries. This repository serves as both a production-ready codebase and educational resource for understanding low-level microcontroller programming.

## Features

- **Bare-Metal Implementation**: All drivers written from scratch using register-level programming
- **Comprehensive Peripheral Support**: GPIO, USART, DMA, NVIC, RCC, SYSTICK, SYSCFG
- **Hardware Abstraction**: Clean separation between hardware and application layers
- **Display Drivers**: Support for TFT displays and LED matrices
- **Assembly Optimizations**: Critical routines written in ARM assembly for maximum performance
- **Test Suites**: Comprehensive testing for each peripheral driver

## Supported Microcontrollers

- STM32F401RE (Primary target)
- Other STM32F4xx series devices
- ARM Cortex-M3/M4 based microcontrollers with minor adaptations

## Project Structure


STM32_BareMetal_Drivers/
│
├── Assembler/          # ARM assembly routines and startup code
├── DMA/               # Direct Memory Access controller driver
├── GPIO/              # General Purpose Input/Output driver
├── HTFT/              # TFT display driver and interface
├── LED_Matrix/        # LED matrix control library
├── NVIC/              # Nested Vectored Interrupt Controller driver
├── RCC/               # Reset and Clock Control driver
├── RCC_test/          # RCC configuration test suite
├── SYSCFG/            # System Configuration Controller driver
├── SYSTICK/           # System Timer driver
├── USART/             # Universal Synchronous/Asynchronous Receiver/Transmitter driver
├── Documentation/     # Datasheets, reference manuals, and guides
├── Applications/      # Example applications using the drivers
├── Libraries/         # Hardware abstraction and utility libraries
└── Tests/             # Unit tests and verification code


## Importing into STM32CubeIDE

### Prerequisites
- STM32CubeIDE installed on your system
- STM32F4xx_DFP package installed (or appropriate for your target)
- ARM GCC toolchain

### Import Steps

1. **Clone the repository**

   git clone https://github.com/Yahia-Sameh/stm32f4xx-firmware-and-drivers-ARM-Cortex-M/tree/main.git
 

2. **Open STM32CubeIDE**
   - Select your workspace directory

3. **Import existing project**
   - Go to `File > Import`
   - Expand `C/C++` and select `Existing Code as Makefile Project`
   - Click `Next`

4. **Configure project settings**
   - Name: `STM32_BareMetal_Drivers`
   - Existing Code Location: Browse to the cloned repository directory
   - Toolchain: `ARM Cross GCC`
   - Click `Finish`

5. **Configure target device**
   - Right-click on the project in Project Explorer
   - Select `Properties`
   - Navigate to `C/C++ Build > Environment`
   - Set `DEVICE` variable to your target (e.g., `STM32F401RE`)

6. **Build the project**
   - Right-click on the project and select `Build Project`


## Documentation

resources include:

- [STM32F401 Reference Manual](https://www.st.com/content/ccc/resource/technical/document/reference_manual/5d/b1/ef/b2/a1/66/40/80/DM00096844.pdf/files/DM00096844.pdf/jcr:content/translations/en.DM00096844.pdf)
- [Cortex-M4 Technical Reference Manual](https://www.st.com/resource/en/programming_manual/dm00046982-stm32-cortexm4-mcus-and-mpus-programming-manual-stmicroelectronics.pdf)


## Contributing

Contributions are welcome! Please feel free to submit pull requests or open issues for bugs and feature requests.

## License

This project is licensed under the MIT License 

## Acknowledgments

This project was developed with support from the Information Technology Institute (ITI), which provided:

- **Technical Infrastructure**: Access to specialized laboratory equipment and development tools
- **Expert Guidance**: Instruction from experienced embedded systems faculty and technical assistants
- **Educational Framework**: Comprehensive curriculum that enabled the development of these low-level drivers

Special recognition to the ITI instructional team for their:
- Technical mentorship throughout the development process
- Code reviews and architecture guidance
- Debugging assistance and performance optimization suggestions

I also extend gratitude to the broader embedded systems community for:
- Open-source resources and reference implementations
- Technical forums and knowledge sharing platforms
- Best practices in embedded software development and documentation

