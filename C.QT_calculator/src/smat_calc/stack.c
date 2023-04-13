#include "stack.h"

#include "calc_core.h"
int Push(stack **head, char val, double num) {
  int status = OK;
  stack *tmp = (stack *)malloc(sizeof(stack));
  if (!tmp) {
    status = MEM_ERROR;
  } else {
    tmp->s = val;
    tmp->value = num;
    if (!(*head)) {
      tmp->next = NULL;
    } else {
      tmp->next = *head;
    }
    *head = tmp;
  }
  return status;
}
int Pop(stack **head, char *val, double *num) {
  int status = OK;
  if (!(*head)) {
    status = MEM_ERROR;
  } else {
    *val = (*head)->s;
    *num = (*head)->value;
    stack *tmp = *head;
    *head = (*head)->next;
    free(tmp);
  }
  return status;
}
