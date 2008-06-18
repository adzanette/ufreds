
/* Size of a memory page */
#define PAGE_SIZE 4096

/* Uthread structure contains just stack base and top */
typedef struct __UTHREAD {
  void * top;
  void * base;
} UThread;

/* createUfred.c */
void criaUthread(UThread * new, void (*thread_function)(void));

/* changeUfred.c */
void mudaUthread(UThread * previous, UThread * next);
