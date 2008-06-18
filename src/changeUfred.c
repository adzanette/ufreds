#include "../include/ufred.h"
#include <stdio.h>

void mudaUthread(UThread * previous, UThread * next) {
  
  /* Save registers context */
  __asm__("pushal");
  
  /* Save esp register to the previous UThread */
  __asm__("movl %%esp,%0"
	  : "=r" (previous->top)
	  :
	  : "%esp");

  /* Save ebp register to the next UThread */
  __asm__("movl %%ebp,%0"
	  : "=r" (previous->base)
	  :
	  : "%ebp");

  /* Change to next thread by: */
  /* placing esp register saved in next->top */
  __asm__("movl %0,%%esp"
	  :
	  : "r" (next->top)
	  : "%esp");

  /* placing ebp register saved in next->base */
  __asm__("movl %0,%%ebp"
	  :
	  : "r" (next->base)
	  : "%ebp");

  /* Load saved registers from stack */
  __asm__("popal");
  
  return;
};

