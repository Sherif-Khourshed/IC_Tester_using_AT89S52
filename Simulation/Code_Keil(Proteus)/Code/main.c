/*
 * IC_Tester.c
 *
 *  Created on : May 1, 2020
 *      Author : Sherif_Khourshed
 *
 *  Description: This test according to IC_Pascal
 */


#include <reg51.h>
#include "lcd.h"
#include "delay.h"

/* Port Declaration */
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


void IC_74265();	/* 74265 IC Test Function */
void IC_4098();		/* 4098 IC Test Function */
void IC_74206();	/* 742206 IC Test Function */

void (*fun_ptr_arr[3])() = {IC_74265, IC_4098, IC_74206};
unsigned char Flag = 0;

void main (void)                  //main function
{
	Data_lines=LOW;			      //Pulling PORT1 LOW
	PORT2=LOW;			          //Pulling PORT2 LOW
	LCD_Init();

	LCD_displayStringRowColumn(0, 7, "Welcome", 7);
	LCD_displayStringRowColumn(1, 2, "IC Tester Project", 17);
	//LCD_displayStringRowColumn(2, 5, "Project", 7);
	delay_time(2000);

	while(1)
	{
		IC_4098();
	}
}


void IC_4098()
{
	pin9 = 1;
	pin11 = 1;
	pin13 = 1;

	pin6 = 1; // Q_the output of first IC
	pin14 = 1; // Q_the output of second IC
	pin4 = 1; // +ve trigger of fist IC
	if((pin6 == 1) && (Flag == 0))
	{
		pin12 = 1; // +ve trigger of second IC
		if((pin14 == 1))
		{
			LCD_Clear();
			LCD_displayStringRowColumn(0, 7, "Found IC", 8);
			LCD_displayStringRowColumn(1, 5, "It's 4098 IC", 12);
			delay_time(1000);
			Flag = 1;
		}
		else
		{
			LCD_Clear();
			LCD_displayStringRowColumn(0, 6, "Unknown IC", 10);
		}

	}
	else if(Flag == 1)
	{
		LCD_Clear();
		LCD_displayStringRowColumn(0, 6, "Unknown IC", 10);
		delay_time(2000);
	}

	pin4 = 0;
	pin12 = 0;
}


void IC_74265()
{

}


void IC_74206()
{

}
