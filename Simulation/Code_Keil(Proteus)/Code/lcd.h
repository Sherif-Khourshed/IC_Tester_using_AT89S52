/*
 * LCD.h
 *
 *  Created on : May 1, 2020
 *      Author : Sherif_Khourshed
 */

/* Declarations */ 
#define Data_lines P1
#define RS P1_0
#define EN P1_1
#define PORT2 P2
#define LOW 0


/* Function Declarations */
void LCD_Init(void);
void LCD_Clear(void);
void LCD_write_data(unsigned char value);
void LCD_write_command(unsigned char value);
void LCD_Send_String(unsigned char *s,int sLen);
void LCD_goToRowColumn(unsigned char row, unsigned char col);
void LCD_displayStringRowColumn(unsigned char row, unsigned char col, unsigned char *s,int sLen);
