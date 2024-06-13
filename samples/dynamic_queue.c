#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 1024

int G_pos = -1;

struct node
{
  int data;
  int pos;
  struct node *next;
};

struct queue
{
  struct node *front;
  struct node *rear;
};

struct queue *initializeQueue();
int isEmpty(struct queue *);
int isFull();
void printQueue(struct queue *);
void freeQueue(struct queue *);
void enqueue(struct queue *, int);
int dequeue(struct queue *);

int main(int argc, char **argv)
{
  struct queue *new_queue = initializeQueue();

  enqueue(new_queue, 10);
  enqueue(new_queue, 20);
  enqueue(new_queue, 30);
  enqueue(new_queue, 40);
  enqueue(new_queue, 50);

  printQueue(new_queue);

  printf("%d dequeued\n", dequeue(new_queue));

  printQueue(new_queue);

  freeQueue(new_queue);
  return 0;
}

struct queue *initializeQueue()
{
  struct queue *q = (struct queue *)malloc(sizeof(struct queue));
  if (!q)
  {
    fprintf(stderr, "Memory allocation failed\n");
    exit(9);
  }
  q->front = q->rear = NULL;
  return q;
}

int isEmpty(struct queue *q) { return q->front == NULL; }

int isFull() { return G_pos == MAX_SIZE-1; }

void printQueue(struct queue *q)
{
  if (isEmpty(q))
  {
    printf("Queue is empty\n");
    return;
  }

  struct node *current = q->front;
  while (current != NULL)
  {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

void freeQueue(struct queue *q)
{
  struct node *current = q->front;
  struct node *next;

  while (current != NULL)
  {
    next = current->next;
    free(current);
    current = next;
  }
  free(q);
}

void enqueue(struct queue *q, int data)
{
  if (isFull()) {
    printf("Stack overflow\n");
    return;
  }

  struct node *n = (struct node *)malloc(sizeof(struct node));
  if (!n)
  {
    printf("Memory allocation failed\n");
    return;
  }

  n->data = data;
  n->next = NULL;
  G_pos++;
  n->pos = G_pos;

  if (q->rear == NULL)
  {
    q->front = q->rear = n;
  }
  else
  {
    q->rear->next = n;
    q->rear = n;
  }
  printf("%d enqueued to queue\n", data);
}

int dequeue(struct queue *q)
{
  if (isEmpty(q))
  {
    printf("Queue underflow\n");
    return INT_MIN;
  }

  struct node *temp = q->front;
  int dequeued = temp->data;
  G_pos--;
  q->front = q->front->next;

  if (isEmpty(q))
    q->rear = NULL;
  free(temp);
  return dequeued;
}
