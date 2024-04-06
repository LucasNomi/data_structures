#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct stack {
  int top;
  unsigned size;
  int *arr;
};

struct queue {
  int front;
  unsigned size;
  int *arr;
};

// Stack operations
struct stack*
initStack(unsigned n)
{
  struct stack *newstack = (struct stack*)malloc(sizeof(struct stack));
  if (newstack == NULL) {
    fprintf(stderr, "Unable to allocate memory...\n");
    exit(1);
  }

  newstack->top = -1;
  newstack->size = n;
  newstack->arr = (int*)malloc(sizeof(int)*n);

  return newstack; 
}

int
s_isEmpty(struct stack *s) { return s->top == -1; }

int
s_isFull(struct stack *s) { return s->top == s->size-1; }

void
s_pushRandom(struct stack *s)
{
  if (s_isFull(s)) {
    printf("Updating stack size from: %d to: %d\n", s->size, s->size * 2);
    int *temp = (int*)malloc(sizeof(int) * (s->size*=2));
    for (int i = 0; i <= s->top; i++)
      temp[i] = s->arr[i];
    free(s->arr);
    s->arr = temp;
  }

  s->arr[++s->top] = rand() % 1000;
}

void
s_show(struct stack *s)
{
  if (s_isEmpty(s))
    return;
  for (int i = s->top; i >= 0; i--)
    printf("%d = %d\n", i+1, s->arr[i]);
}

// queue operations
struct queue *
initQueue(unsigned n)
{
  struct queue *newqueue = (struct queue*)malloc(sizeof(struct queue));
  if (newqueue == NULL) {
    fprintf(stderr, "Unable to allocate memory...\n");
    exit(1);
  }

  newqueue->front = -1;
  newqueue->size = n;
  newqueue->arr = (int*)malloc(sizeof(int)*n);

  return newqueue; 
}

int
q_isEmpty(struct queue *q) { return q->front == -1; }

int
q_isFull(struct queue *q) { return q->front == q->size-1; }

void
q_show(struct queue *q)
{
  if (q_isEmpty(q))
    return;
  for (int i = 0; i < q->front; i++)
    printf("%d ", q->arr[i]);
  printf("\n");
}

void
q_pushRandom(struct queue *q)
{
  if (q_isFull(q)) {
    printf("Updating queue size from: %d to: %d\n", q->size, q->size * 2);
    int *temp = (int*)malloc(sizeof(int) * (q->size*=2));
    for (int i = 0; i <= q->front; i++)
      temp[i] = q->arr[i];
    free(q->arr);
    q->arr = temp;
  }

  for (int i = ++q->front; i > 0; i--)
    q->arr[i] = q->arr[i-1];
  q->arr[0] = rand() % 100;
}

// Any operations
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

  struct stack *st1 = initStack(10);

  for (int i = 0; i < 10; i++)
    s_pushRandom(st1);

  s_show(st1);

  for (int i = 0; i < 5; i++)
    s_pushRandom(st1);

  printf("Disorganized stack:\n");
  s_show(st1);

  printf("Organized stack:\n");
  bubbleSort(st1->arr, st1->top+1);
  s_show(st1);

  free(st1->arr);

  printf("\n");

  struct queue *qe1 = initQueue(10);

  for (int i = 0; i < 10; i++)
    q_pushRandom(qe1); 

  q_show(qe1);

  for (int i = 0; i < 10; i++)
    q_pushRandom(qe1); 

  q_show(qe1);

  free(qe1->arr);
  return 0;
}
