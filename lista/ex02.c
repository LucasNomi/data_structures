#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define STACK_MAX 128

struct stack {
  int top;
  int arr[STACK_MAX];
};

int
isEmpty(struct stack *sp) { return sp->top == -1; }

int
isFull(struct stack *sp) { return sp->top == STACK_MAX - 1; }

void
push(struct stack *sp, int value)
{
  if (isFull(sp))
    return;
  sp->arr[++sp->top] = value;
}

void
pushRandom(struct stack *sp)
{
  if (isFull(sp))
    return;
  sp->arr[++sp->top] = rand() % 1000;
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
  if(isEmpty(sp))
    return;
  for (int i = sp->top; i >= 0; i--)
    printf("%d = %d\n", i+1, sp->arr[i]);
}

void
swap(int *arr, int i, int j)
{
  int aux = arr[i];
  arr[i] = arr[j];
  arr[j] = aux;
}

void
bubbleSort(int *arr, int n)
{
  for (int i = 0; i < n-1; i++)
    for (int j = 0; j < n-i-1; j++)
      if (arr[j] < arr[j+1])
        swap(arr,j,j+1);
}

int
main()
{
  srand(time(NULL));

  struct stack s;
  s.top = -1;

  for (int i = 0; i < STACK_MAX; i++) {
    pushRandom(&s);
  }  

  printf("Stack desorganizado:\n");
  show(&s);

  printf("\n");

  printf("Stack organizado:\n");
  bubbleSort(s.arr, s.top+1);
  show(&s);

  return 0;
}
