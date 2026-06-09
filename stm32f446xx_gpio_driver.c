/*
 * stm32f446xx_gpio_driver.c
 *
 *  Created on: JUN 6, 2026
 *      Author: SRIRAM
 */


#include "stm32f446xx_gpio_driver.h"



/**
 * @brief Write a logic for enable and disable clock to a GPIOs.
 * @param pGPIOx Pointer to GPIO port registers.
 * @param ENABLEorDISABLE Enable or disable the peripheral clock. .
 * @return None.
 */
void GPIO_PeriClkcontrol(GPIO_REGdef *pGPIOx,uint8_t ENABLEorDISABLE){

	if(ENABLEorDISABLE==ENABLE ){
		if(pGPIOx==GPIOA){

			CLK_EN_GPIOA();

		}else if(pGPIOx==GPIOB){

			CLK_EN_GPIOB();

		}else if(pGPIOx==GPIOC){

			CLK_EN_GPIOC();

	    }else if(pGPIOx==GPIOD){

		    CLK_EN_GPIOD();

        }else if(pGPIOx==GPIOE){

	     	CLK_EN_GPIOE();

        }else if(pGPIOx==GPIOF){
		    CLK_EN_GPIOF();

        }else if(pGPIOx==GPIOG){

		    CLK_EN_GPIOG();

        }else if(pGPIOx==GPIOH){

  	    	CLK_EN_GPIOH();
        }
    }else{
		if(pGPIOx==GPIOA){

			CLK_DSEN_GPIOA();

		}else if(pGPIOx==GPIOB){

			CLK_DSEN_GPIOB();

		}else if(pGPIOx==GPIOC){

			CLK_DSEN_GPIOC();

	    }else if(pGPIOx==GPIOD){

		    CLK_DSEN_GPIOD();

        }else if(pGPIOx==GPIOE){

	     	CLK_DSEN_GPIOE();

        }else if(pGPIOx==GPIOF){
		    CLK_DSEN_GPIOF();

        }else if(pGPIOx==GPIOG){

		    CLK_DSEN_GPIOG();

        }else if(pGPIOx==GPIOH){

  	    	CLK_DSEN_GPIOH();
        }
    }

}



/**
 * @brief Write a logic for configure to GPIO port pin.
 * @param pGPIOHandle Pointer to GPIO_handler structure.
 * @return None.
 */
void GPIO_Init(GPIO_handler *pGPIOHandle ){
	uint32_t temp=0;
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG){
		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->MODER  &=~(0x3 << (2*  pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->MODER |=temp;
	}else{


	}
	temp=0;
	temp=(pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDER  &=~(0x3 << (2*  pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDER |=temp;

	temp=0;
	temp=(pGPIOHandle->GPIO_PinConfig.GPIO_PinPUPDcontrol << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR  &=~(0x3 <<(2*pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR |=temp;


	temp=0;
	temp=(pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType <<  pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OTYPER &=~(0x1 <<  pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OTYPER |=temp;

	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN){
		uint8_t temp1,temp2 ;
		temp1 =  pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;
        temp2 =  pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;
        pGPIOHandle->pGPIOx->AFR[temp1] &=~(0xf<<(4*temp2));
        pGPIOHandle->pGPIOx->AFR[temp1] |=  (pGPIOHandle->GPIO_PinConfig.GPIO_PinALTfunMode << (4* temp2));

}

}



/**
 * @brief Write a logic for deconfigure GPIO port pin.
 * @param pGPIOx Pointer to GPIO port register.
 * @return None.
 */
void GPIO_DeInit(GPIO_REGdef *pGPIOx){

	       if(pGPIOx==GPIOA){

				GPIOA_REG_RST();

			}else if(pGPIOx==GPIOB){

				GPIOB_REG_RST();

			}else if(pGPIOx==GPIOC){

				GPIOC_REG_RST();

		    }else if(pGPIOx==GPIOD){

		    	GPIOD_REG_RST();

	        }else if(pGPIOx==GPIOE){

	        	GPIOE_REG_RST();

	        }else if(pGPIOx==GPIOF){
	        	GPIOF_REG_RST();

	        }else if(pGPIOx==GPIOG){

	        	GPIOG_REG_RST();

	        }else if(pGPIOx==GPIOH){

	        	GPIOH_REG_RST();
	        }
}



/**
 * @brief Write a logic for read value from GPIO port pin.
 * @param pGPIOx Pointer to GPIO port register.
 * @param GPIO_PinNumber pin number to the GPIO port.
 * @return GPIO port pin value .
 */
uint8_t GPIO_ReadfromInputPin(GPIO_REGdef *pGPIOx ,uint8_t GPIO_PinNumber ){
	uint8_t value;
	value = (uint8_t)((pGPIOx->IDR >> GPIO_PinNumber) & 0x00000001);
	return value;
}



/**
 * @brief Write a logic for read value from GPIO port.
 * @param pGPIOx Pointer to GPIO port register.
 * @return GPIO port value.
 */
uint16_t GPIO_ReadfromInputPort(GPIO_REGdef *pGPIOx){
	uint16_t portvalue;
	portvalue=(uint16_t)pGPIOx->IDR;
	return portvalue;
}



/**
 * @brief Write a logic level to a GPIO output port pin.
 * @param pGPIOx Pointer to GPIO port register.
 * @param GPIO_PinNumber pin number to the GPIO port.
 * @param value to set or clear the pin.
 * @return None.
 */
void GPIO_WriteToOutputPin(GPIO_REGdef *pGPIOx ,uint8_t GPIO_PinNumber,uint8_t value){
     if(value == SET){
    	 pGPIOx->ODR |= (0x1<<  GPIO_PinNumber);
     }else{
    	 pGPIOx->ODR &= ~(0x1<<  GPIO_PinNumber);
     }

}



/**
 * @brief Write a logic level to a GPIO output port.
 * @param pGPIOx Pointer to GPIO port register.
 * @param vlaue to set or clear the port.
 * @return None.
 */
void GPIO_WriteToOutputPort(GPIO_REGdef *pGPIOx,uint16_t value){
	pGPIOx->ODR=value;

}




/**
 * @brief Write a logic to toggle the GPIO output port pin.
 * @param pGPIOx Pointer to GPIO port register.
 * @param GPIO_PinNumber pin number to the GPIO port.
 * @return None.
 */
void GPIO_ToggleOutputPin(GPIO_REGdef *pGPIOx ,uint8_t GPIO_PinNumber){
	pGPIOx->ODR ^=(0x1 << GPIO_PinNumber);
}

/**
 * @brief Write a logic to generate time delay.
 * @param number to for loop .
 * @return None.
 */
void Delay(uint32_t number)
{
    for(uint32_t i = 0; i < number; i++);
}




//void GPIO_IRQConfig(uint8_t IRQNumber,uint8_t IRQPriority,uint8_t ENABLEorDISABLE);
//void GPIO_IRQHandling(void);

