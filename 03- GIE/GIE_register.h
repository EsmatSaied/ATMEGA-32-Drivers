/**************************************************/
/**************************************************/
/*************  Author: Esmat Saied    ************/
/*************   Component: GIE       ************/
/*************   Layer: MCAL           ************/
/*************   Version: 1.00         ************/
/**************************************************/
/**************************************************/


#ifndef GIE_REGISTER_H_
#define GIE_REGISTER_H_

#define SREG		*((volatile u8*)0x5F) //Add from data sheet
#define SREG_I		7 //this pin is responsible for handling interrupts


#endif