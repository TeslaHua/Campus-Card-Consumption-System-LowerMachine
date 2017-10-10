
#ifndef __DEF_H
#define __DEF_H

/*
 * GPIOÄ£¿é
 *
 */
typedef enum Px
{
  P1,
  P2,
  P3,
  P4,
  P5,
  P6
}Px;


/*
 * CLKÄ£¿é
 *
 */
typedef enum CLKx
{
	ACLK=1,
  	MCLK=0,
  	SMCLK=2
}CLKx;


#define W_CRYSTAL       32768 
#define CRYSTAL         8000000 

#define NULL (uint16*)(0)


/*
 * UARTÄ£¿é
 *
 */
typedef enum UARTx
{
  UART0,
  UART1,
}UARTx;












#endif

