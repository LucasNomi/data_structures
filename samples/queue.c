/* Estrutura de dados
 * Exemplo de uma estrutura de fila
 * Sem alocamento dinâmico
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define QUEUE_MAX 1024

struct queue {
  int front;
  int arr[QUEUE_MAX];
};

int isEmpty(struct queue *qp);
int isFull(struct queue *qp);
void push(struct queue *qp, int data);
int pop(struct queue *qp);
void show(struct queue *qp);

int
main(int argc, char **argv)
{
  return 0;
}

int
isEmpty(struct queue *qp) { return qp->front == -1; }

int
isFull(struct queue *qp) { return qp->front == QUEUE_MAX-1; }

void
push(struct queue *qp, int data)
{
  if (isFull(qp))
    return;
  for (int i = ++qp->front; i > 0; i--)
    qp->arr[i] = qp->arr[i-1];
  qp->arr[0] = data;
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
  if (isEmpty(qp))
    return;
  for (int i = 0; i < qp->front; i++)
    printf("%d ", qp->arr[i]);
  printf("\n");
}
