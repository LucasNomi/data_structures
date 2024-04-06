#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define QUEUE_MAX 32

struct queue {
  int front;
  int arr[QUEUE_MAX];
};

int
isEmpty(struct queue *qp) { return qp->front == -1; }

int
isFull(struct queue *qp) { return qp->front == QUEUE_MAX - 1; }

void
push(struct queue *qp, int value)
{
  if (isFull(qp))
    return;
  for (int i = ++qp->front; i > 0; i--)
    qp->arr[i] = qp->arr[i-1];
  qp->arr[0] = value;
}

void
pushRandom(struct queue *qp)
{
  if (isFull(qp))
    return;
  for (int i = ++qp->front; i > 0; i--)
    qp->arr[i] = qp->arr[i-1];
  qp->arr[0] = rand() % 100;
}

int
pop(struct queue *qp)
{
  if (isEmpty(qp))
    return INT_MIN;
  return qp->arr[qp->front--];
}

void
show(struct queue *qp)
{
  if(isEmpty(qp))
    return;
  for (int i = 0; i < qp->front; i++)
    printf("%d ", qp->arr[i]);
  printf("\n");
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

  struct queue q;
  q.front = -1;

  for (int i = 0; i < QUEUE_MAX; i++) {
    pushRandom(&q);
  }  

  printf("Queue desorganizado:\n");
  show(&q);

  printf("\n");

  printf("Queue organizado:\n");
  bubbleSort(q.arr, q.front+1);
  show(&q);

  return 0;
}
