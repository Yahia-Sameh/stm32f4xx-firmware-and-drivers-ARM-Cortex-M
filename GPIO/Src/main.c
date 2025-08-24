#include "GPIO_private.h"


/* Array of GPIO ports */
static GPIO_TypeDef * const GPIO_PORT[] = {
    GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, GPIOH
};

/* AHB1ENR register for clock control (assuming RCC base address is 0x40023800) */
#define RCC_AHB1ENR    (*((volatile uint32_t *)0x40023830))

/*===========================================================================*/
void GPIO_EnableClock(GPIO_Port port)
{
    if (port <= GPIO_PORTH) {
        RCC_AHB1ENR |= (1 << port);
    }
}

/*===========================================================================*/
void GPIO_DisableClock(GPIO_Port port)
{
    if (port <= GPIO_PORTH) {
        RCC_AHB1ENR &= ~(1 << port);
    }
}

/*===========================================================================*/
void GPIO_ConfigurePinMode(GPIO_Port port, GPIO_Pin pin, GPIO_Mode mode)
{
    GPIO_PORT[port]->MODER &= ~(MODE_MASK << (pin * 2));
    GPIO_PORT[port]->MODER |= (mode << (pin * 2));
}

/*===========================================================================*/
void GPIO_ConfigurePull(GPIO_Port port, GPIO_Pin pin, GPIO_Pull pull)
{
    GPIO_PORT[port]->PUPDR &= ~(PULL_MASK << (pin * 2));
    GPIO_PORT[port]->PUPDR |= (pull << (pin * 2));
}

/*===========================================================================*/
void GPIO_ConfigureOutputType(GPIO_Port port, GPIO_Pin pin, GPIO_OType otype)
{
    GPIO_PORT[port]->OTYPER &= ~(OTYPE_MASK << pin);
    GPIO_PORT[port]->OTYPER |= (otype << pin);
}

/*===========================================================================*/
void GPIO_ConfigureOutputSpeed(GPIO_Port port, GPIO_Pin pin, GPIO_Speed speed)
{
    GPIO_PORT[port]->OSPEEDR &= ~(SPEED_MASK << (pin * 2));
    GPIO_PORT[port]->OSPEEDR |= (speed << (pin * 2));
}

/*===========================================================================*/
void GPIO_ConfigureAlternateFunction(GPIO_Port port, GPIO_Pin pin, uint8_t alternate)
{
    uint8_t afr_reg = pin / 8;
    uint8_t afr_pos = (pin % 8) * 4;
    GPIO_PORT[port]->AFR[afr_reg] &= ~(AFR_MASK << afr_pos);
    GPIO_PORT[port]->AFR[afr_reg] |= (alternate << afr_pos);
}

/*===========================================================================*/
void GPIO_Pin_Write(GPIO_Port port, GPIO_Pin pin, GPIO_State state)
{
    if (state == GPIO_HIGH)
        GPIO_PORT[port]->BSRR = (1 << pin);
    else
        GPIO_PORT[port]->BSRR = (1 << (pin + 16));
}

/*===========================================================================*/
GPIO_State GPIO_Pin_Read(GPIO_Port port, GPIO_Pin pin)
{
    return (GPIO_PORT[port]->IDR & (1 << pin)) ? GPIO_HIGH : GPIO_LOW;
}

/*===========================================================================*/
void GPIO_Pin_Toggle(GPIO_Port port, GPIO_Pin pin)
{
    GPIO_PORT[port]->ODR ^= (1 << pin);
}

/*===========================================================================*/
void GPIO_Port_Write(GPIO_Port port, uint16_t value)
{
    GPIO_PORT[port]->ODR = value;
}

/*===========================================================================*/
uint16_t GPIO_Port_Read(GPIO_Port port)
{
    return GPIO_PORT[port]->IDR;
}

/*===========================================================================*/
void GPIO_InitDefaultOutput(GPIO_Port port, GPIO_Pin pin)
{
    GPIO_EnableClock(port);
    GPIO_ConfigurePinMode(port, pin, GPIO_MODE_OUTPUT);
    GPIO_ConfigureOutputType(port, pin, GPIO_OTYPE_PP);
    GPIO_ConfigureOutputSpeed(port, pin, GPIO_SPEED_MEDIUM);
    GPIO_ConfigurePull(port, pin, GPIO_PULL_NONE);
}

int main()
{
    // Initialize PA5 as a default output (LED)
    GPIO_InitDefaultOutput(GPIO_PORTA, GPIO_PIN5);

    // Turn on the LED
    GPIO_Pin_Write(GPIO_PORTA, GPIO_PIN5, GPIO_HIGH);

    while(1) {
        // Toggle the LED
        GPIO_Pin_Toggle(GPIO_PORTA, GPIO_PIN5);

        // Add some delay here in a real application
    }
}
