#include <stdio.h> 
#include <stdlib.h>

struct node { char data; struct node *next; }; 

struct node* 
createNode(char ch) 
{ 
  struct node *n = (struct node*)malloc(sizeof(struct node));
  if (n == NULL) { 
    fprintf(stderr, "Unable to create a node\n"); exit(1); 
  } 

  n->data = ch; n->next = NULL; 
  return n; 
} 

void 
insertAtEnd(struct node *n, char ch) 
{ 
  struct node *temp = n; 

  while (temp->next != NULL) 
    temp = temp->next; 

  struct node *newnode = createNode(ch); 
  temp->next = newnode; 
}

void
show(struct node *n)
{
  if (n == NULL)
    return;

  struct node *temp = n;
  
  while (temp != NULL) {
    printf("%c ", temp->data);
    temp = temp->next;
  }
  printf("\n");
} 

void
deleteList(struct node **n)
{
  if (*n == NULL)
    return;

  struct node *curr = *n;
  struct node *next;
  while (curr != NULL) {
    next = curr->next;
    free(curr);
    curr = next;
  }

  *n = NULL;
}

int 
main() 
{ 
  struct node *init = createNode('a');  
  
  for (int i = 1; i <= 25; i++)
    insertAtEnd(init, 'a'+i);

  show(init);
  deleteList(&init);

  return 0; 
}
