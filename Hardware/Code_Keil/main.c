/*
 * IC_Tester.c
 *
 *  Created on : May 1, 2020
 *      Author : Sherif_Khourshed
 *
 *  Description: This test according to IC_Pascal
 */

#include <Reg52.H>
#include <stdio.h>

/* Port 0 */
sbit pin1 = P0^0;
sbit pin2 = P0^1;
sbit pin3= P0^2;
sbit pin4 = P0^3;
sbit pin5 = P0^4;
sbit pin6 = P0^5;
sbit pin7 = P0^6;
//sbitpin8 = P0^7; GND

/* Port 2 */
sbit pin9 = P2^0;
sbit pin10 = P2^1;
sbit pin11 = P2^2;
sbit pin12 = P2^3;
sbit pin13 = P2^4;
sbit pin14 = P2^5;
sbit pin15 = P2^6;
//sbitpin16 = P2^7; VCC

sbit ledred = P1^0; 	// for defect IC
sbit ledyellow = P1^1; 	//for 4098 IC
sbit ledgreen = P1^2; 	//for 74265 IC

int flag; /* 0 for defect ic, 1 for 74265 ic, 2 for 4098 ic */

void IC_74265(void); 	/* 74265 IC Test Function */
void IC_4098(void);		/* 4098 IC Test Function */
void delay(void);		/* Delay Function */

void main (void)
{
	while(1)
	{
		while(1)
		{
			/* 74265 IC Test */
			IC_74265();
			if(flag == 1)
			{
				/* Flashing green led */
				ledgreen = 1;
				delay();
				delay();
				delay();
				ledgreen = 0;
				delay();
				delay();
				delay();
				break;
			}

			/* 4098 IC Test */
			IC_4098();
			if(flag == 2)
			{
				/* Flashing yellow led */
				ledyellow = 1;
				delay();
				delay();
				delay();
				ledyellow = 0;
				delay();
				delay();
				delay();
				break;
			}

			if(flag == 0)
			{
				/* Flashing red led */
				ledred = 1;
				delay();
				delay();
				delay();
				ledred = 0;
				delay();
				delay();
				delay();
				break;
			}
		}
	}
}

void delay(void)
{
	unsigned int x,y ;
	for(x=0 ; x<1000 ; x++)
	{
		for(y=0 ; y<100 ; y++);
	}
}

void IC_74265(void)
{
	/* o/p pins */
	pin2 = pin3 = pin6 = pin7 = pin9 = pin10 = pin13 = pin14 = 1;

	pin1 = 0;
	pin15 = 0;

	if((pin2 != 0) || (!(pin3) != 0))
	{
		flag = 0;
	}
	else
	{
		if((pin14 != 0) || (!(pin13) != 0))
		{
			flag = 0;
		}
		else
		{
			pin1 = 1;
			pin15 = 1;
			if((pin2 != 1) || (!(pin3) != 1))
			{
				flag = 0;
			}
			else
			{
				if((pin14 != 1) || (!(pin13) != 1))
				{
					flag = 0;
				}
				else
				{
					pin4 = 0;
					pin5 = 0;
					pin11 = 0;
					pin12 = 0;

					if((pin6 != (pin4 && pin5)) || (pin7 != !(pin4 && pin5)))
					{
						flag = 0;
					}
					else
					{
						if((pin10 != (pin11 && pin12)) || (pin9 != !(pin11 && pin12)))
						{
							flag = 0;
						}
						else
						{
							pin4 = 0;
							pin5 = 1;
							pin11 = 0;
							pin12 = 1;

							if((pin6 != (pin4 && pin5)) || (pin7 != !(pin4 && pin5)))
							{
								flag = 0;
							}
							else
							{
								if((pin10 != (pin11 && pin12)) || (pin9 != !(pin11 && pin12)))
								{
									flag = 0;
								}
								else
								{
									pin4 = 1;
									pin5 = 0;
									pin11 = 1;
									pin12 = 0;

									if((pin6 != (pin4 && pin5)) || (pin7 != !(pin4 && pin5)))
									{
										flag = 0;
									}
									else
									{
										if((pin10 != (pin11 && pin12)) || (pin9 != !(pin11 && pin12)))
										{
											flag = 0;
										}
										else
										{
											pin4 = 1;
											pin5 = 1;
											pin11 = 1;
											pin12 = 1;

											if((pin6 != (pin4 && pin5)) || (pin7 != !(pin4 && pin5)))
											{
												flag = 0;
											}
											else
											{
												if((pin10 != (pin11 && pin12)) || (pin9 != !(pin11 && pin12)))
												{
													flag = 0;
												}
												else
												{
													flag = 1;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


void IC_4098(void)
{
	pin6 = 1; 	// input Q PIN
	pin10 = 1;	// input Q PIN

	pin1 = 1;
	pin3 = 1;	//reset pin
	pin5 = 1;	//-ve trigger
	pin4 = 1;	//+ve trigger

	if(pin6 == 1)
	{
		pin15 = 1;
		pin13 = 1;	//reset
		pin11= 1; 	//-ve trigger
		pin12 = 1;	//+ve trigger

		if(pin10 == 1)
		{
			flag = 2;
		}
		else
		{
			flag = 0;
		}
	}
	else
	{
		flag = 0;
	}

	pin4 = 0;
	pin12 = 0;
}
