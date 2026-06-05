/*
 * STM32f446xx.H
 *
 *  CREATED ON: JUN 5, 2026
 *      AUTHOR: SRIRAM
 */



#ifndef INC_STM32F446XX_H_
#define INC_STM32F446XX_H_
#include <stdint.h>



/* MEMOERY BASE ADDRESS */
#define FLASH_BADDRESS                0X08000000UL
#define SRAM1_BADDRESS                0X20000000UL
#define SRAM                          SRAM1_BADDRESS
#define SRAM2_BADDRESS                0x2001C000UL
#define ROM_BADDRESS                  0x1FFF0000UL
#define OTP_BADDRESS                  0x1FFF7800UL



/* BUS BASE ADDRESS */
#define APB1PRPHL_BADDRESS           0X40000000UL
#define APB2PRPHL_BADDRESS           0x40010000UL
#define AHB1PRPHL_BADDRESS           0x40020000UL
#define AHB2PRPHL_BADDRESS           0x50000000UL



/* RCC BASE ADDDESS */
#define RCC_BADDRESS                 0x40023800UL



/* BASE ADDRESS OF GPIO PORT A TO H ,WHICH ARE HANGING ON AHB1*/
#define PORTA_GPIO_BADDRESS          0x40020000UL
#define PORTB_GPIO_BADDRESS          0x40020400UL
#define PORTC_GPIO_BADDRESS          0x40020800UL
#define PORTD_GPIO_BADDRESS          0x40020C00UL
#define PORTE_GPIO_BADDRESS          0x40021000UL
#define PORTF_GPIO_BADDRESS          0x40021400UL
#define PORTG_GPIO_BADDRESS          0x40021800UL
#define PORTH_GPIO_BADDRESS          0x40021C00UL



/* INITIALIZE BASE ADDRESS OF APB1 PERIPHERALS ,THESE ARE THE PERIPHERALS  I2C3,I2C2, I2C1,UART5,UART4, USART3 , USART2, SPI3 , SPI2 .*/
#define BADDRESS_OF_SPI2_PRPHL       0x40003800UL
#define BADDRESS_OF_SPI3_PRPHL       0x40003C00UL
#define BADDRESS_OF_USART2_PRPHL     0x40004400UL
#define BADDRESS_OF_USART3_PRPHL     0x40004800UL
#define BADDRESS_OF_UART4_PRPHL      0x40004C00UL
#define BADDRESS_OF_UART5_PRPHL      0x40005000UL
#define BADDRESS_OF_I2C1_PRPHL       0x40005400UL
#define BADDRESS_OF_I2C2_PRPHL       0x40005800UL
#define BADDRESS_OF_I2C3_PRPHL       0x40005C00UL



/* INITIALIZE BASE ADDRESS OF APB2 PERIPHERALS,THESE ARE THE PERIPHERAL USART1,USART6, SPI1,SPI4, SYSCFG,EXTI. */
#define BADDRESS_USART1_PRPHL       0x40011000UL
#define BADDRESS_USART6_PRPHL       0x40011400UL
#define BADDRESS_SPI1_PRPHL         0x40013000UL
#define BADDRESS_SPI4_PRPHL         0x40013400UL
#define BADDRESS_SYSCFG_PRPHL       0x40013800UL
#define BADDRESS_EXTI_PRPHL         0x40013C00UL



typedef struct{
	volatile uint32_t MODER;                     /* GPIO port mode register offset: 0x00 */
	volatile uint32_t OTYPER;                   /* GPIO port output type register offset: 0x04 */
	volatile uint32_t OSPEEDER;                /* GPIO port output speed register offset: 0x08 */
	volatile uint32_t PUPDR;                  /*GPIO port pull-up/pull-down register  offset: 0x0C */
	volatile uint32_t IDR;                   /* GPIO port input data register offset: 0x10*/
	volatile uint32_t ODR;                  /* GPIO port output data register offset: 0x14*/
	volatile uint32_t BSRR;                /* GPIO port bit set/reset register offset: 0x18*/
	volatile uint32_t LCKR;               /* GPIO port configuration lock register  offset: 0x1C */
	volatile uint32_t AFR[2];            /* AFR[0]=GPIO alternate function low register offset: 0x20 ,AFR[1]=GPIO alternate function high register offset: 0x24 */
}GPIO_REGdef;



#define GPIOA                            ((GPIO_REGdef *)PORTA_GPIO_BADDRESS)
#define GPIOB                            ((GPIO_REGdef *)PORTB_GPIO_BADDRESS)
#define GPIOC                            ((GPIO_REGdef *)PORTC_GPIO_BADDRESS)
#define GPIOD                            ((GPIO_REGdef *)PORTD_GPIO_BADDRESS)
#define GPIOE                            ((GPIO_REGdef *)PORTE_GPIO_BADDRESS)
#define GPIOF                            ((GPIO_REGdef *)PORTF_GPIO_BADDRESS)
#define GPIOG                            ((GPIO_REGdef *)PORTG_GPIO_BADDRESS)
#define GPIOH                            ((GPIO_REGdef *)PORTH_GPIO_BADDRESS)



typedef struct{
	volatile uint32_t CR;                                                              /* RCC clock control register offset: 0x00 */
	volatile uint32_t PLLCFGR;                                                        /* RCC PLL configuration register  offset: 0x04  */
	volatile uint32_t CFGR;                                                          /* RCC clock configuration register offset: 0x08  */
	volatile uint32_t CIR;                                                          /* RCC clock interrupt register offset: 0x0C */
	volatile uint32_t AHB1RSTR;                                                    /* RCC AHB1 peripheral reset register offset: 0x10*/
	volatile uint32_t AHB2RSTR;                                                   /* RCC AHB2 peripheral reset register  offset: 0x14*/
	volatile uint32_t AHB3RSTR;                                                  /*  RCC AHB3 peripheral reset register  offset: 0x18*/
	volatile uint32_t RESERVED0;                                                /* offset: 0x1C */
	volatile uint32_t APB1RSTR;                                                /* RCC APB1 peripheral reset register offset: 0x20*/
	volatile uint32_t APB2RSTR;                                               /* RCC APB2 peripheral reset register   offset: 0x24 */
	volatile uint32_t RESERVED1[2];                                          /* offset:0x28 --->  offset:0x2C  */
	volatile uint32_t AHB1ENR;                                              /* RCC AHB1 peripheral clock enable register offset: 0x30 */
	volatile uint32_t AHB2ENR;                                             /* RCC AHB2 peripheral clock enable register  offset: 0x34 */
	volatile uint32_t AHB3ENR;                                            /* RCC AHB3 peripheral clock enable register offset: 0x38 */
	volatile uint32_t RESERVED2;                                         /* offset:0x3C */
	volatile uint32_t APB1ENR;                                          /* RCC APB1 peripheral clock enable register offset: 0x40 */
	volatile uint32_t APB2ENR;                                         /* RCC APB2 peripheral clock enable register offset: 0x44*/
	volatile uint32_t RESERVED3[2];                                   /* offset:0x48 ---> offset:0x4C */
	volatile uint32_t AHB1LPENR;                                     /* RCC AHB1 peripheral clock enable in low power mode register offset: 0x50 */
	volatile uint32_t AHB2LPENR;                                    /* RCC AHB2 peripheral clock enable in low power mode register   offset: 0x54*/
	volatile uint32_t AHB3LPENR;                                   /* RCC AHB3 peripheral clock enable in low power mode register offset: 0x58*/
	volatile uint32_t RESERVED4;                                  /* offset:0x5C */
	volatile uint32_t APB1LPENR;                                 /* RCC APB1 peripheral clock enable in low power mode register offset: 0x60 */
	volatile uint32_t APB2LPENR;                                /* RCC APB2 peripheral clock enabled in low power mode register  offset: 0x64 */
	volatile uint32_t RESERVED5[2];                            /* offset: 0x68 ---> offset: 0x6C */
	volatile uint32_t BDCR;                                   /* RCC Backup domain control register  offset: 0x70 */
	volatile uint32_t CSR;                                   /* RCC clock control and status register  offset: 0x74 */
	volatile uint32_t RESERVED6[2];                         /* offset: 0x78 ---> offset: 0x7C */
	volatile uint32_t SSCGR;                               /* RCC spread spectrum clock generation register  offset: 0x80 */
	volatile uint32_t PLLI2SCFGR;                         /*  RCC PLLI2S configuration register  offset: 0x84 */
	volatile uint32_t PLLSAICFGR;                        /* RCC PLL configuration register offset: 0x88 */
	volatile uint32_t DCKCFGR;                          /* RCC dedicated clock configuration register offset: 0x8C  */
	volatile uint32_t CKGATENR;                        /* RCC clocks gated enable register offset: 0x90  */
	volatile uint32_t DCKCFGR2;                       /* RCC dedicated clocks configuration register 2 offset: 0x94 */
}RCC_REGdef;



#define RCC                ((RCC_REGdef*)RCC_BADDRESS )



/* enable clock for all GPIO port */
#define CLK_EN_GPIOA()  ( RCC->AHB1ENR |=(0X01 << 0))
#define CLK_EN_GPIOB()  ( RCC->AHB1ENR |=(0X01 << 1))
#define CLK_EN_GPIOC()  ( RCC->AHB1ENR |=(0X01 << 2))
#define CLK_EN_GPIOD()  ( RCC->AHB1ENR |=(0X01 << 3))
#define CLK_EN_GPIOE()  ( RCC->AHB1ENR |=(0X01 << 4))
#define CLK_EN_GPIOF()  ( RCC->AHB1ENR |=(0X01 << 5))
#define CLK_EN_GPIOG()  ( RCC->AHB1ENR |=(0X01 << 6))
#define CLK_EN_GPIOH()  ( RCC->AHB1ENR |=(0X01 << 7))



/* disable clock for all GPIO port */
#define CLK_DSEN_GPIOA()  ( RCC->AHB1ENR &=~(0X01 << 0))
#define CLK_DSEN_GPIOB()  ( RCC->AHB1ENR &=~(0X01 << 1))
#define CLK_DSEN_GPIOC()  ( RCC->AHB1ENR &=~(0X01 << 2))
#define CLK_DSEN_GPIOD()  ( RCC->AHB1ENR &=~(0X01 << 3))
#define CLK_DSEN_GPIOE()  ( RCC->AHB1ENR &=~(0X01 << 4))
#define CLK_DSEN_GPIOF()  ( RCC->AHB1ENR &=~(0X01 << 5))
#define CLK_DSEN_GPIOG()  ( RCC->AHB1ENR &=~(0X01 << 6))
#define CLK_DSEN_GPIOH()  ( RCC->AHB1ENR &=~(0X01 << 7))






#endif /* INC_STM32F446XX_H_ */

