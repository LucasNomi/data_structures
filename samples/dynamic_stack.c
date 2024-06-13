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

struct stack
{
  struct node *top;
};

struct stack *initializeStack();
int isEmpty(struct stack *);
int isFull();
void freeStack(struct stack *);
void printStack(struct stack *);
void push(struct stack *, int);
int pop(struct stack *);

int main(int argc, char **argv)
{
  struct stack *new_stack = initializeStack();

  push(new_stack, 10);
  push(new_stack, 20);
  push(new_stack, 30);

  printStack(new_stack);

  printf("%d popped from stack\n", pop(new_stack));

  printStack(new_stack);

  freeStack(new_stack);
  return 0;
}

struct stack *initializeStack()
{
  struct stack *s = (struct stack *)malloc(sizeof(struct stack));

  if (!s)
  {
    fprintf(stderr, "Memory allocation failed\n");
    exit(9);
  }

  s->top = NULL;
  return s;
}

int isEmpty(struct stack *s) { return s->top == NULL; }

int isFull() { return G_pos == MAX_SIZE-1;}

void printStack(struct stack *s)
{
  if (isEmpty(s))
  {
    printf("Stack is empty\n");
    return;
  }

  struct node *current = s->top;
  while (current != NULL)
  {
    printf("%d\n", current->data);
    current = current->next;
  }
}

void freeStack(struct stack *s)
{
  struct node *current = s->top;
  struct node *next;

  while (current != NULL)
  {
    next = current->next;
    free(current);
    current = next;
  }
  free(s);
}

void push(struct stack *s, int data)
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
  n->next = s->top;
  G_pos++;
  n->pos = G_pos;
  s->top = n;
  printf("%d pushed onto stack\n", data);
}

int pop(struct stack *s)
{
  if (isEmpty(s))
  {
    printf("Stack underflow\n");
    exit(INT_MIN);
  }
  struct node *temp = s->top;
  int popped = temp->data;
  s->top = s->top->next;
  G_pos--;
  free(temp);
  return popped;
}
