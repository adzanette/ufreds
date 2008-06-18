#include "../include/ufred.h"
#include <stdio.h>
#include <stdlib.h>

void sair() {
  exit(0);
};

/* This function creates a new thread */
void criaUthread(UThread * new, void (*thread_function)(void)) {
  void * stack_space;
  void * new_base;
  void * new_top;

  /* To allocate the stack and find base and top pointers */
  stack_space = (void *) malloc(PAGE_SIZE);
  if (stack_space) {

    /* Base and top of the new thread stack */
    new_base = stack_space + PAGE_SIZE;
    new_top  = new_base;

    /* Saves end function */
    new_top -= 4;
    *((void **) new_top) = sair;

    /* Saves thread_function */
    new_top -= 4;
    *((void **) new_top) = thread_function;

    /* New base */
    new->base = new_top;
    new->top = new->base;
    new->top -= 4;
    *((void **) new->top) = new_base;

    /* Saves thread_function */
    new->top -= 4;
    *((long int *) new->top) = 0;
    new->top -= 4;
    *((long int *) new->top) = 0;
       
    /* Push EAX */
    new->top -= sizeof(long int);
    *((long int *) new->top) = 0;

    /* Push ECX */
    new->top -= sizeof(long int);
    *((long int *) new->top) = 0;

    /* Push EDX */
    new->top -= sizeof(long int);
    *((long int *) new->top) = 0;

    /* Push EBX */
    new->top -= sizeof(long int);
    *((long int *) new->top) = 0;

    /* Push ESI */
    new->top -= sizeof(long int);
    *((long int *) new->top) = 0;

    /* Push EDI */
    new->top -= sizeof(long int);
    *((long int *) new->top) = 0;
       
  } else {

    printf("Error creating thread: No enough memory\n");

  };

  return;
  //  __asm__("leave");
  //  __asm__("ret");
  
};
