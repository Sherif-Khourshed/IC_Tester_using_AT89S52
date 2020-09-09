// Checks status of push button connected to P2.0  (active low)
// When pushed, LED connected to P1.0 flashes five times
#include "ATSTAMP.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>

void IC_74265();
void IC_4098();
int flag = 0; // if == 1 74265 If == 2 4098 if == 2 74206 if == 0 is a defect ic
int main()
{
	if(!OpenCom(1, 115200))
	{
		exit(0);
	}
	   void (*fun_ptr_arr[])() =  {IC_74265, IC_4098};
	   printf("IC Tester Project\n");



		  while(1)
		  {


			  while(1)
			  {


				(*fun_ptr_arr[0])();
				 if(flag == 1)
				 {

					printf("it's 74265 IC\n");
					break;

				 }

				(*fun_ptr_arr[1])();
				if(flag == 2)
				{

					printf("it's 4098 IC\n");
					break;


				}
				else if(flag == 0)
				{

					printf("it's a defect IC\n");
					 break;

				}




             }

		 }
	Sleep(2000);
	return 0;
}

  void IC_74265()
  {

	  clr(P0,0);
	  clr(P2,6);

	  if( ( GetBit(P0,1) != 0 ) || ( (!GetBit(P0,2)) != 0 ) )
	  {

		flag = 0;


	  }
	  else

	  {

			if( ( GetBit(P2,5) != 0 ) || ( (!GetBit(P2,4)) != 0 ) )
			{


				flag = 0;

			}
			else

			{

				setb(P0,0);
				setb(P2,6);

				if( ( GetBit(P0,1) != 1 ) || ( (!GetBit(P0,2)) != 1 ) )
				{


					flag = 0;

				}
				else
				{

					if( ( GetBit(P2,5) != 1 ) || ( (!GetBit(P2,4)) != 1 ) )
					{


						flag = 0;

					}
					else
					{


						clr(P0,3);
						clr(P0,4);
						clr(P2,2);
						clr(P2,3);
						if( ( GetBit(P0,5) != ( GetBit(P0,3) && GetBit (P0,4) ) ) || ( GetBit(P0,6) !=  !( GetBit(P0,3) && GetBit (P0,4) ) ) )
						{

							flag = 0;

						}
						else
						{

							if( ( GetBit(P2,1) != ( GetBit(P2,2) && GetBit (P2,3) ) ) || ( GetBit(P2,0) !=  !( GetBit(P2,2) && GetBit (P2,3) ) ) )
							{

								flag = 0;


							}
							else
							{

								clr(P0,3);
								setb(P0,4);
								clr(P2,2);
								setb(P2,3);
								if( ( GetBit(P0,5) != ( GetBit(P0,3) && GetBit (P0,4) ) ) || ( GetBit(P0,6) !=  !( GetBit(P0,3) && GetBit (P0,4) ) ) )
								{

									flag = 0;


								}
								else
								{

									if( ( GetBit(P2,1) != ( GetBit(P2,2) && GetBit (P2,3) ) ) || ( GetBit(P2,0) !=  !( GetBit(P2,2) && GetBit (P2,3) ) ) )
									{

										flag = 0;


									}
									else
									{

										setb(P0,3);
										clr(P0,4);
										setb(P2,2);
										clr(P2,3);
										if( ( GetBit(P0,5) != ( GetBit(P0,3) && GetBit (P0,4) ) ) || ( GetBit(P0,6) !=  !( GetBit(P0,3) && GetBit (P0,4) ) ) )
										{

											flag = 0;


										}
										else
										{

											if( ( GetBit(P2,1) != ( GetBit(P2,2) && GetBit (P2,3) ) ) || ( GetBit(P2,0) !=  !( GetBit(P2,2) && GetBit (P2,3) ) ) )
											{

												flag = 0;


											}
											else
											{

												setb(P0,3);
												setb(P0,4);
												setb(P2,2);
												setb(P2,3);
												if( ( GetBit(P0,5) != ( GetBit(P0,3) && GetBit (P0,4) ) ) || ( GetBit(P0,6) !=  !( GetBit(P0,3) && GetBit (P0,4) ) ) )
												{

													flag = 0;


												}
												else
												{

													if( ( GetBit(P2,1) != ( GetBit(P2,2) && GetBit (P2,3) ) ) || ( GetBit(P2,0) !=  !( GetBit(P2,2) && GetBit (P2,3) ) ) )
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

		setb(P0,0);
		setb(P0,1);
		setb(P0,2);
		setb(P0,3);
		setb(P0,4);
		setb(P0,5);
		setb(P0,6);
		setb(P2,0);
		setb(P2,1);
		setb(P2,2);
		setb(P2,3);
		setb(P2,4);
		setb(P2,5);
		setb(P2,6);

  }

  void IC_4098()
  {
	   clr(P0,3);
	   setb(P0,0);
	   setb(P0,4);
	   setb(P0,2);
	   //monostable 1

	   setb(P0,3);//+ve trigger
	   Sleep(100);
	   if( GetBit(P0,5) == 1 )
	   {
			clr(P2,3);
            Sleep(100);
			// monostable 2
			setb(P2,2);//pin 11 -ve trigger
			setb(P2,4);//pin 13 reset
			setb(P2,6);//pin 15

			setb(P2,3);//+ve trigger
			Sleep(100);
			if( GetBit(P2,1) == 1 )
			{

				flag = 2;

			}
			else
			{

				flag = 0;

			}
			//flag = 2;
	   }
	   else
	   {

			flag = 0;

	   }
	   /*
	   setb(P0,3);
	   setb(P2,3);
	   setb(P0,5);
	   setb(P2,1);*/
	   clr(P0,3);
	   clr(P2,3);

  }
