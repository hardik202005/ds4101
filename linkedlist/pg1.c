
#include <stdio.h>
#include <stdlib.h>
struct Node
{
  int data;
  struct Node *next;
};

struct Node *head = NULL;
int isEmpty()
{
  return head == NULL;
}
void insertAtBegin(int value)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->next = head;
  head = newNode;
}

void insertAtPos(int value, int pos)
{
  if (pos == 0)
  {
    insertAtBegin(value);
    return;
  }

  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = value;

  struct Node *temp = head;
  for (int i = 0; i < pos - 1 && temp != NULL; i++)
  {
    temp = temp->next;
  }

  if (temp == NULL)
  {
    printf("Position out of bounds\n");
    free(newNode);
    return;
  }

  newNode->next = temp->next;
  temp->next = newNode;
}

void insertAtEnd(int value)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->next = NULL;

  if (isEmpty())
  {
    head = newNode;
    return;
  }

  struct Node *temp = head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = newNode;
}

void deleteAtBegin()
{
  if (isEmpty())
  {
    printf("List is empty\n");
    return;
  }

  struct Node *temp = head;
  head = head->next;
  free(temp);
}

void deleteAtEnd()
{
  if (isEmpty())
  {
    printf("List is empty\n");
    return;
  }

  if (head->next == NULL)
  {
    free(head);
    head = NULL;
    return;
  }

  struct Node *temp = head;
  while (temp->next->next != NULL)
  {
    temp = temp->next;
  }

  free(temp->next);
  temp->next = NULL;
}

void deleteAtPos(int pos)
{
  if (isEmpty())
  {
    printf("List is empty\n");
    return;
  }

  if (pos == 0)
  {
    deleteAtBegin();
    return;
  }

  struct Node *temp = head;
  for (int i = 0; i < pos - 1 && temp != NULL; i++)
  {
    temp = temp->next;
  }

  if (temp == NULL || temp->next == NULL)
  {
    printf("Position out of bounds\n");
    return;
  }

  struct Node *toDelete = temp->next;
  temp->next = toDelete->next;
  free(toDelete);
}

int isFull()
{
  return 0;
}

void display()
{
  struct Node *temp = head;
  if (isEmpty())
  {
    printf("List is empty\n");
    return;
  }
  while (temp != NULL)
  {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

void search(int value)
{
  struct Node *temp = head;
  int position = 0;
  while (temp != NULL)
  {
    if (temp->data == value)
    {
      printf("Value %d found at position %d\n", value, position);
      return;
    }
    position++;
    temp = temp->next;
  }
  printf("Value %d not found in the list\n", value);
}

int main()
{
  insertAtEnd(10);
  insertAtEnd(20);
  insertAtBegin(5);
  insertAtPos(15, 2);

  printf("Current Linked List: ");
  display();

  deleteAtBegin();
  printf("After deleting at beginning: ");
  display();

  deleteAtEnd();
  printf("After deleting at end: ");
  display();

  deleteAtPos(1);
  printf("After deleting at position 1: ");
  display();

  search(15);
  search(100);

  return 0;
}