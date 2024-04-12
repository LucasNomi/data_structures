#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

void connectList(struct node *head_n1, struct node *head_n2);
void show();

int
main(int argc, char **argv)
{
  return 0;
}

void
connect(struct node *head_n1, struct node *head_n2)
{
  struct node *temp = head_n1;

  while (temp->next != NULL)
    temp = temp->next;

  temp->next = head_n2;  
}

void
show(struct node *head)
{
  struct node *curr = n;
  while (curr != NULL) {
    printf("%d -> ", curr->data);
    curr = curr->next;
  }
  printf("\n");
}
