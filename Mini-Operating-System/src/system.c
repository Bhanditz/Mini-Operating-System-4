/* Configuring input ad output ports 
 * Below are the assembly embedded c language codes 
 * inportb - To scan the input from the defined port. Here, stdin
 * outportb - To print the output in console. Here, stdout
 */
#include "../include/system.h"
uint8 inportb (uint16 _port)
{
    	uint8 rv;
    	__asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
    	return rv;
}

void outportb (uint16 _port, uint8 _data)
{
	__asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}
