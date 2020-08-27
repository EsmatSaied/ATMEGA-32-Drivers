#include "Std_Types.h"
#include "BIT_MATH.h"
#include "EXTI_config.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_register.h"

/*INT0 call back ISR function*/
static void (*EXTI_pvINT0CallBackFunc)(void)= NULL;
/*INT1 call back ISR function*/
static void (*EXTI_pvINT1CallBackFunc)(void)= NULL;
/*INT2 call back ISR function*/
static void (*EXTI_pvINT2CallBackFunc)(void)= NULL;

void EXTI_voidINT0Init(void)
{
	#if INT0_SENSE_CTRL== FALLING_EDGE_

	/*set sense ctrl of INT0 to falling edge*/
	SET_BIT(MCUCR, MCUCR_ISC01);
	CLR_BIT(MCUCR, MCUCR_ISC00);

	#elif INT0_SENSE_CTRL== RISING_EDGE_

		/*set sense ctrl of INT0 to rising edge*/
		SET_BIT(MCUCR, MCUCR_ISC01);
		SET_BIT(MCUCR, MCUCR_ISC00);

	#elif INT0_SENSE_CTRL== LOW_LEVEL

		/*set sense ctrl of INT0 to falling edge*/
		CLR_BIT(MCUCR, MCUCR_ISC01);
		CLR_BIT(MCUCR, MCUCR_ISC00);

	#elif INT0_SENSE_CTRL== ON_CHANGE

		/*set sense ctrl of INT0 to falling edge*/
		CLR_BIT(MCUCR, MCUCR_ISC01);
		SET_BIT(MCUCR, MCUCR_ISC00);
	#else
	#error "Wrong Configuration Option of INT0_SENSE_CTRL"
	#endif

	#if INT0_INITIAL_STATE== ENABLED
		/*INT0 PIE Enable*/
		SET_BIT(GICR, GICR_INT0);
#endif
}
void EXTI_voidINT1Init(void)
{
	#if INT1_SENSE_CTRL== FALLING_EDGE_

	/*set sense ctrl of INT1 to falling edge*/
	SET_BIT(MCUCR, MCUCR_ISC11);
	CLR_BIT(MCUCR, MCUCR_ISC10);

	#elif INT1_SENSE_CTRL== RISING_EDGE_

	/*set sense ctrl of INT1 to rising edge*/
	SET_BIT(MCUCR, MCUCR_ISC11);
	SET_BIT(MCUCR, MCUCR_ISC10);

	#elif INT1_SENSE_CTRL== LOW_LEVEL

	/*set sense ctrl of INT1 to falling edge*/
	CLR_BIT(MCUCR, MCUCR_ISC11);
	CLR_BIT(MCUCR, MCUCR_ISC10);

	#elif(INT1_SENSE_CTRL== ON_CHANGE

	/*set sense ctrl of INT0 to falling edge*/
	CLR_BIT(MCUCR, MCUCR_ISC11);
	SET_BIT(MCUCR, MCUCR_ISC10);

	#else
	#error "Wrong Configuration Option of INT1_SENSE_CTRL"
	#endif

	#if INT1_INITIAL_STATE== ENABLED
		/*INT1 PIE Enable*/
		SET_BIT(GICR, GICR_INT1);
#endif
}
void EXTI_voidINT2Init(void)
{
	#if INT2_SENSE_CTRL== FALLING_EDGE_

	/*set sense ctrl of INT2 to falling edge*/
	CLR_BIT(MCUCSR, MCUCSR_ISC2);


	#elif INT2_SENSE_CTRL== RISING_EDGE_

	/*set sense ctrl of INT2 to rising edge*/
	SET_BIT(MCUCSR, MCUCSR_ISC2);

	#else
	#error "Wrong Configuration Option of INT2_SENSE_CTRL"
	#endif

	#if INT2_INITIAL_STATE== ENABLED
		/*INT2 PIE Enable*/
		SET_BIT(GICR, GICR_INT2);
#endif
}

void EXTI_voidSetSenseControl(u8 Copy_u8Int, u8 Copy_u8Sense)
{
	if(Copy_u8Int== INT0)
	{
		if(Copy_u8Sense== FALLING_EDGE_)
		{
			/*set sense ctrl of INT0 to falling edge*/
			SET_BIT(MCUCR, MCUCR_ISC01);
			CLR_BIT(MCUCR, MCUCR_ISC00);
		}
		else if(Copy_u8Sense== RISING_EDGE_)
		{

			/*set sense ctrl of INT0 to rising edge*/
			SET_BIT(MCUCR, MCUCR_ISC01);
			SET_BIT(MCUCR, MCUCR_ISC00);
		}

		else if(Copy_u8Sense== LOW_LEVEL)
		{
			/*set sense ctrl of INT0 to falling edge*/
			CLR_BIT(MCUCR, MCUCR_ISC01);
			CLR_BIT(MCUCR, MCUCR_ISC00);
		}
		else if(Copy_u8Sense== ON_CHANGE)
		{
			/*set sense ctrl of INT0 to falling edge*/
			CLR_BIT(MCUCR, MCUCR_ISC01);
			SET_BIT(MCUCR, MCUCR_ISC00);
		}
	}

	else if(Copy_u8Int== INT1)
	{
		if(Copy_u8Sense== FALLING_EDGE_)
		{
			/*set sense ctrl of INT1 to falling edge*/
			SET_BIT(MCUCR, MCUCR_ISC11);
			CLR_BIT(MCUCR, MCUCR_ISC10);
		}
		else if(Copy_u8Sense== RISING_EDGE_)
		{
			/*set sense ctrl of INT1 to rising edge*/
			SET_BIT(MCUCR, MCUCR_ISC11);
			SET_BIT(MCUCR, MCUCR_ISC10);
		}
		else if(Copy_u8Sense== LOW_LEVEL)
		{
			/*set sense ctrl of INT1 to low level*/
			CLR_BIT(MCUCR, MCUCR_ISC11);
			CLR_BIT(MCUCR, MCUCR_ISC10);
		}
		else if(Copy_u8Sense== ON_CHANGE)
		{
			/*set sense ctrl of INT1 to logical chnge*/
			CLR_BIT(MCUCR, MCUCR_ISC11);
			SET_BIT(MCUCR, MCUCR_ISC10);
		}
	}
	else if(Copy_u8Int== INT2)
	{
		if(Copy_u8Sense== FALLING_EDGE_)
		{
			/*set sense ctrl of INT2 to falling edge*/
			CLR_BIT(MCUCSR, MCUCSR_ISC2);
		}
		else if(Copy_u8Sense== RISING_EDGE_)
		{
			/*set sense ctrl of INT2 to rising edge*/
			SET_BIT(MCUCSR, MCUCSR_ISC2);
		}
	}
}

void EXTI_voidEnableInterrupt(u8 Copy_u8Int)
{
	if(Copy_u8Int== INT0)
		/*INT0 PIE Enable*/
		SET_BIT(GICR, GICR_INT0);

	else if(Copy_u8Int== INT1)
		/*INT1 PIE Enable*/
		SET_BIT(GICR, GICR_INT1);

	else if(INT2_INITIAL_STATE== INT2)
		/*INT2 PIE Enable*/
		SET_BIT(GICR, GICR_INT2);
}
void EXTI_voidDisableInterrupt(u8 Copy_u8Int)
{
	if(Copy_u8Int== INT0)
		/*INT0 PIE Disable*/
		CLR_BIT(GICR, GICR_INT0);

	else if(Copy_u8Int== INT1)
		/*INT1 PIE Disable*/
		CLR_BIT(GICR, GICR_INT1);

	else if(INT2_INITIAL_STATE== INT2)
		/*INT2 PIE Disable*/
		CLR_BIT(GICR, GICR_INT2);
}

u8 EXTI_u8INT0SetCallBack(void(*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState= OK;
	if(Copy_pvCallBackFunc!= NULL)
	{
		EXTI_pvINT0CallBackFunc= Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorState= NULL_POINTER;
	}
	return Local_u8ErrorState;
}

void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if(EXTI_pvINT0CallBackFunc!= NULL)
	{
		/*Invoke the call back function of the application ISR*/
		EXTI_pvINT0CallBackFunc();
	}
}

u8 EXTI_u8INT1SetCallBack(void(*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState= OK;
	if(Copy_pvCallBackFunc!= NULL)
	{
		EXTI_pvINT1CallBackFunc= Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorState= NULL_POINTER;
	}
	return Local_u8ErrorState;
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if(EXTI_pvINT1CallBackFunc!= NULL)
	{
		/*Invoke the call back function of the application ISR*/
		EXTI_pvINT1CallBackFunc();
	}
}

u8 EXTI_u8INT2SetCallBack(void(*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState= OK;
	if(Copy_pvCallBackFunc!= NULL)
	{
		EXTI_pvINT2CallBackFunc= Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorState= NULL_POINTER;
	}
	return Local_u8ErrorState;
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if(EXTI_pvINT2CallBackFunc!= NULL)
	{
		/*Invoke the call back function of the application ISR*/
		EXTI_pvINT2CallBackFunc();
	}
}
