/*
 * stm32f446xx_gpio_driver.h
 *
 *  Created on: JUN 6, 2026
 *      Author: SRIRAM
 */

#ifndef INC_STM32F446XX_GPIO_DRIVER_H_
#define INC_STM32F446XX_GPIO_DRIVER_H_



#include "stm32f446xx.h"



/**< PIN CONFIGURATION STRUCTURE */
typedef struct{
	uint8_t GPIO_PinNumber;                             /**< GPIO PORT PIN NUMBER */
	uint8_t GPIO_PinMode;                              /**<   POSSIBLE VALUE FROM @GPIO_PIN_MODES   >*/
	uint8_t GPIO_PinSpeed;                            /**<POSSIBLE VALUE FROM @GPIO_SPEED_MODES */
	uint8_t GPIO_PinPUPDcontrol;                     /**< POSSIBLE VALUE FOR PULL UP AND PULL DOWN @GPIO_PIN_PULLUP_AND_PULLDOWN */
	uint8_t GPIO_PinOPType;                         /**< POSSIBLE VALUE FOR PUSH PULL AND OPEN DRAIN @GPIO_PIN_OUTPUT_TYPE  */
	uint8_t GPIO_PinALTfunMode;                     /**<GPIO PORT PIN ALTERNATE FUNCTION */
}GPIO_PConfig;



/**< GPIO HANDLER STRUCTURE  */
typedef struct{
	GPIO_REGdef *pGPIOx;
	GPIO_PConfig GPIO_PinConfig;

}GPIO_handler;



/**< GPIO PORT PIN NUMBERS */
#define GPIO_PNUM0        0                                                        /**<  GPIO PIN NUMBER 0 */
#define GPIO_PNUM1        1                                                       /**<  GPIO PIN NUMBER 1 */
#define GPIO_PNUM2        2                                                      /**<  GPIO PIN NUMBER 2 */
#define GPIO_PNUM3        3                                                     /**< GPIO PIN NUMBER 3 */
#define GPIO_PNUM4        4                                                    /**<  GPIO PIN NUMBER 4 */
#define GPIO_PNUM5        5                                                   /**<  GPIO PIN NUMBER 5 */
#define GPIO_PNUM6        6                                                  /**<  GPIO PIN NUMBER 6 */
#define GPIO_PNUM7        7                                                 /**<  GPIO PIN NUMBER 7 */
#define GPIO_PNUM8        8                                                /**<  GPIO PIN NUMBER 8 */
#define GPIO_PNUM9        9                                               /**<  GPIO PIN NUMBER 9 */
#define GPIO_PNUM10       10                                             /**<  GPIO PIN NUMBER 10 */
#define GPIO_PNUM11       11                                            /**<  GPIO PIN NUMBER 11 */
#define GPIO_PNUM12       12                                           /**< GPIO PIN NUMBER 12 */
#define GPIO_PNUM13       13                                          /**<  GPIO PIN NUMBER 13 */
#define GPIO_PNUM14       14                                         /**<  GPIO PIN NUMBER 14 */
#define GPIO_PNUM15       15                                        /**< GPIO PIN NUMBER 15 */



/**< @GPIO_PIN_MODES */
#define GPIO_MODE_IN       0                                        /**< INPUT MODE */
#define GPIO_MODE_OUT      1                                       /**<  OUTPUT MODE  */
#define GPIO_MODE_ALTFN    2                                      /**<  ALTERNATE FUNCTION MODE ( UART,SPI,I2C )*/
#define GPIO_MODE_ANALOG   3                                     /**<  ANALOG MODE  */
#define GPIO_MODE_IT_FT    4                                    /**< INTERRUPT FALLING EDGE  */
#define GPIO_MODE_IT_RT    5                                   /**< INTERRUPT RISING EDGE */
#define GPIO_MODE_IT_RFT   6                                  /**< INTERRUPT FALLING EDGE AND RISING EDGE TRIGGER PIN */



/**<  @GPIO_PIN_OUTPUT_TYPE */
#define GPIO_OP_TYPE_PP    0                                  /**< GPIO OUTPUT PIN PUSH PULL */
#define GPIO_OP_TYPE_OD    1                                /**< GPIO OUTPUT PIN OPEN DRAIN */



/**< @GPIO_SPEED_MODES */
#define GPIO_SPEED_LOW     0
#define GPIO_SPEED_MEDIUM  1
#define GPIO_SPEED_FAST    2
#define GPIO_SPEED_HIGH    3



/* @GPIO_PIN_PULLUP_AND_PULLDOWN */
#define GPIO_NO_PUPD       0      /**< NO PULL UP AND PULL DOWN */
#define GPIO_PIN_PU        1      /**< PULL UP */
#define GPIO_PIN_PD        2      /**< PULL DOWN  */



/**
 * @brief   peripheral clock control for GPIO port.
 * @param pGPIOHandle Pointer to GPIO handle structure , Enable and disable.
 * @return None.
 */
void GPIO_PeriClkcontrol(GPIO_REGdef *pGPIOx,uint8_t ENABLEorDISABLE);




/**
 * @brief Initialize a GPIO pin.
 * @param pGPIOHandle Pointer to GPIO handle structure.
 * @return None.
 */
void GPIO_Init(GPIO_handler *pGPIOHandle );




/**
 * @brief deInitialize a GPIO port.
 * @param GPIO_REGdef Pointer to GPIO register structure.
 * @return None.
 */
void GPIO_DeInit(GPIO_REGdef *pGPIOx);



/**
 * @brief Read data from GPIO input port pin .
 * @param GPIO_REGdef Pointer to GPIO register structure and pin number.
 * @return INPUT PIN VALUE.
 */
uint8_t GPIO_ReadfromInputPin(GPIO_REGdef *pGPIOx ,uint8_t GPIO_PinNumber );



/**
 * @brief Read data from GPIO input port .
 * @param GPIO_REGdef Pointer to GPIO register structure.
 * @return INPUT port VALUE.
 */
uint16_t GPIO_ReadfromInputPort(GPIO_REGdef *pGPIOx);



/**
 * @brief write value to GPIO output port pin .
 * @param GPIO_REGdef Pointer to GPIO register structure ,pin number and set or reset value.
 * @return None.
 */
void GPIO_WriteToOutputPin(GPIO_REGdef *pGPIOx ,uint8_t GPIO_PinNumber,uint8_t value);



/**
 * @brief write value to GPIO output port .
 * @param GPIO_REGdef Pointer to GPIO register structure and set or reset value.
 * @return None.
 */
void GPIO_WriteToOutputPort(GPIO_REGdef *pGPIOx,uint16_t value);


/**
 * @brief Toggle the output pin .
 * @param GPIO_REGdef Pointer to GPIO register structure and pin number .
 * @return None.
 */
void GPIO_ToggleOutputPin(GPIO_REGdef *pGPIOx ,uint8_t GPIO_PinNumber);



/**
 * @brief time delay .
 * @param delay value .
 * @return None.
 */
void Delay(uint32_t number);



//void GPIO_IRQConfig(uint8_t IRQNumber,uint8_t IRQPriority,uint8_t ENABLEorDISABLE);
//void GPIO_IRQHandling(void);





#endif /* INC_STM32F446XX_GPIO_DRIVER_H_ */
