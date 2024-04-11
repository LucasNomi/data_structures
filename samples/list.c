#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node {
  int data;
  int pos;
  struct node *next;
};

#define LIST_MAX 1024

struct node *head = NULL;

void initList(int data);
struct node* createNode(int data);
int isEmpty();
int isFull();
void insertAtBegin(int data);
void insertAtEnd(int data);
//TODO: void insertAtPos(int data, int pos);
//TODO: int removeFromBegin();
//TODO: int removeFromEnd();
//TODO: int removeFromPos(int pos);
void show();
void deleteList();

int
main(int argc, char **argv)
{
  return 0;
}

void
initList(int data)
{
  head = createNode(data);
  head->pos = 0;  
  head->next = NULL;
}

struct node*
createNode(int data)
{
  struct node *newnode = (struct node*)malloc(sizeof(struct node));
  if (newnode == NULL)
    exit(1);

  newnode->data = data;
  return newnode;
}

int
isEmpty() { return head == NULL; }

int isFull()
{
  struct node *curr = head;
  while (curr->next != NULL)
    curr = curr->next;
  return curr->pos == LIST_MAX-1;
}

void
insertAtBegin(int data)
{
  if (isFull())
    return; 

  struct node *old_head = head;
  struct node *n = createNode(data);
  n->pos = 0;
  n->next = old_head;
  head = n;

  struct node *updt = head->next;
  while (updt != NULL) {
    updt->pos++;
    updt = updt->next;
  }
}

void
insertAtEnd(int data)
{
  if (isFull())
    return;

  struct node *curr = head;
  int acc_pos = 0;
  while (curr->next != NULL) {
    curr = curr->next;
    acc_pos++;
  }

  struct node *n = createNode(data);
  n->pos = acc_pos+1;
  n->next = NULL;
  curr->next = n;
}

void
show()
{
  if(isEmpty())
    return;

  struct node *curr = head;
  while (curr != NULL) {
    printf("(%d)%d -> ", curr->pos, curr->data);
    curr = curr->next;
  }
  printf("\n");
}

void
deleteList()
{
  if(isEmpty())
    return;

  struct node *curr = head;
  struct node *next;
  while (curr != NULL) {
    next = curr->next;
    free(curr);
    curr = next;
  }
  head = NULL;
}
