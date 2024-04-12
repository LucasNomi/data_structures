#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_MAX 256
#define QUEUE_MAX 1024

struct doc {
  char nome[STR_MAX];
  int qty;
};

struct queue {
  int front;
  struct doc documentos[QUEUE_MAX];
  
};

void push(struct queue *qp, struct doc *d);
struct doc* pop(struct queue *qp);

int
main(int argc, char **argv)
{
  return 0;
}

void
push(struct queue *qp, struct doc *d)
{
  if (qp->front == QUEUE_MAX-1)
    return;
  for (int i = ++qp->front; i > 0; i--)
    qp->documentos[i] = qp->documentos[i-1];
  qp->documentos[0] = *d;
}

struct doc*
pop(struct queue *qp)
{
  if (qp->front == -1)
    return NULL;
  return &qp->documentos[qp->front--];
}
