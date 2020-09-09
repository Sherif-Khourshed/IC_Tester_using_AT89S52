/*
 * LCD.c
 *
 *  Created on : May 1, 2020
 *      Author : Sherif_Khourshed
 */


#include <REGX51.H>
#include "delay.h"
#include "lcd.h"

void LCD_Init(void)
{
 LCD_write_command(0x02);		  //to reset  
 LCD_write_command(0x28);	      //2 lines and 5x7 matrix
 LCD_write_command(0x0c);	      //Display ON,cursor OFF
 LCD_write_command(0x01);         //Clear Screen 
 LCD_write_command(0x06);	      //Increment cursor
}

void LCD_Clear(void)
{
	LCD_write_command(0x01);         //Clear Screen 
}

/* Function to write 8-bit data on LCD */ 
void LCD_write_data(unsigned char value)
 {
   RS=1;				       		 //selecting data register
   Data_lines &= 0x0F;         		 //put zero on data lines 
   Data_lines |=(value&0xF0);  		 //Write higher 4- bit of data
   EN=1;
   delay_time(1);
   EN=0;

   Data_lines &= 0x0F;          	//again put zero on data lines 
   Data_lines |=((value<<4)&0xF0);  // Write lower 4- bit of data
   EN=1;
   delay_time(1);
   EN=0;
 }

 /* Function to write command on LCD */
void LCD_write_command(unsigned char value)
 {
   RS=0;				        //selecting command register
   Data_lines &= 0x0F;          //put zero on data lines 
   Data_lines |=(value&0xF0);  // Write higher 4- bit of data
   EN=1;
   delay_time(1);
   EN=0;

   Data_lines &= 0x0F;          //again put zero on data lines 
   Data_lines |=((value<<4)&0xF0);  // Write lower 4- bit of data
   EN=1;
   delay_time(1);
   EN=0;
 }

 /* Function to write string on LCD */
void LCD_Send_String(unsigned char *s,int sLen)
 {
  while(sLen>0)
    {
     LCD_write_data(*s++);	//sending string on LCD
     sLen--;
    }
 }
 
 void LCD_goToRowColumn(unsigned char row, unsigned char col)
 {
	unsigned char address;
	 switch(row)
	 {
		case 0: /* Line one */
		address = col + 0x00;
		break;
		case 1:	/* Line two */
		address = col + 0x40;
		break;
		case 2:	/* Line three */
		address = col + 0x10;
		break;
		case 3:	/* Line four */
		address = col + 0x50;
	 }
	 LCD_write_command(address | 0x80);
 }
 
 void LCD_displayStringRowColumn(unsigned char row, unsigned char col, unsigned char *s,int sLen)
{
	LCD_goToRowColumn(row, col);	/* Go to the required address */
	LCD_Send_String(s, sLen);			/* Display the string */
}

 