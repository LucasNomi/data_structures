#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QUEUE_MAX 32

struct queue {
  int front;
  int data[QUEUE_MAX];
};

void
show(struct queue *q)
{
  if (q->front == -1)
    return;
  for (int i = 0; i < q->front; i++)
    printf("%d ", q->data[i]);
}

void
pushRandom(struct queue *q)
{
  if (q->front == QUEUE_MAX-1)
    return;
  q->front++;
  for (int i = q->front; i > 0; i--)
    q->data[i] = q->data[i-1];
  q->data[0] = rand() % 100;
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

  show(&q);
  return 0;
}
