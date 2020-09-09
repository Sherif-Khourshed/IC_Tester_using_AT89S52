/*
 * Delay.c
 *
 *  Created on : May 1, 2020
 *      Author : Sherif_Khourshed
 */


/* Function for generating 1 msec delay */
void delay_time (unsigned int time)
{
  unsigned int i,j;
   for(i=0;i<time;i++)
     for(j=0;j<112;j++);
}
