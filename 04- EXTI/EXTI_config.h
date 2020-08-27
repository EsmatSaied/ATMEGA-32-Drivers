/**************************************************/
/**************************************************/
/*************  Author: Esmat Saied    ************/
/*************   Component: EXTI       ************/
/*************   Layer: MCAL           ************/
/*************   Version: 1.00         ************/
/**************************************************/
/**************************************************/

#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

/*CHOOSE WHICH SENSE CTRL MODE IS APPROPRIATE FOR THE APPLICATION
 * Options For INT0: 1- FALLING_EDGE
 * 		   			 2- RISING_EDGE
 * 		   			 3- LOW_LEVEL
 * 		             4- ON_CHANGE*/
#define INT0_SENSE_CTRL			RISING_EDGE_
#define INT0_INITIAL_STATE		DISABLED

 /*Options For INT1: 1- FALLING_EDGE
 * 		   			 2- RISING_EDGE
 * 		   			 3- LOW_LEVEL
 * 		             4- ON_CHANGE*/
#define INT1_SENSE_CTRL			FALLING_EDGE_
#define INT1_INITIAL_STATE		ENABLED

 /*Options For INT2: 1- FALLING_EDGE
 * 		   			 2- RISING_EDGE*/
#define INT2_SENSE_CTRL			FALLING_EDGE_
#define INT2_INITIAL_STATE		ENABLED


#endif