/* Estrutura de dados 
 * Exemplo de uma estrutura de pilha
 * Sem alocamento dinâmico 
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define STACK_MAX 256

struct stack {
  int top;
  int arr[STACK_MAX];
};

int isEmpty(struct stack *sp);
int isFull(struct stack *sp);
void push(struct stack *sp, int data);
int pop(struct stack *sp);
void show(struct stack *sp);
void peep(struct stack *sp);

int
main(int argc, char **argv)
{
  return 0;
}

int
isEmpty(struct stack *sp) { return sp->top == -1; }

int
isFull(struct stack *sp) { return sp->top == STACK_MAX-1; }

void
push(struct stack *sp, int data)
{
  if (isFull(sp))
    return;
  sp->arr[++sp->top] = data;
}

int
pop(struct stack *sp)
{
  if (isEmpty(sp))
    return INT_MIN;
  return sp->arr[sp->top--];
}

void
show(struct stack *sp)
{
  if (isEmpty(sp))
    return;
  for (int i = sp->top; i >= 0; i--)
    printf("%d\n", sp->arr[i]);
}

void
peep(struct stack *sp)
{
  if (isEmpty(sp))
    return;
  printf("%d\n", sp->arr[sp->top]); 
}
