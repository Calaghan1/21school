#ifndef SRC_STACK_H_
#define SRC_STACK_H_

typedef struct stack {
  char s;
  double value;
  struct stack *next;
} stack;

int Push(stack **head, char val, double num);
int Pop(stack **head, char *val, double *num);

#endif  //  SRC_STACK_H_
