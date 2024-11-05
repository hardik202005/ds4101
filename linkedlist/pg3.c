#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
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
  newNode->prev = NULL;

  if (isEmpty())
  {
    head = newNode;
  }
  else
  {
    head->prev = newNode;
    head = newNode;
  }
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
  newNode->prev = temp;
  if (temp->next != NULL)
  {
    temp->next->prev = newNode;
  }
  temp->next = newNode;
}

void insertAtEnd(int value)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->next = NULL;

  if (isEmpty())
  {
    newNode->prev = NULL;
    head = newNode;
  }
  else
  {
    struct Node *temp = head;
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
  }
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

  if (head != NULL)
  {
    head->prev = NULL;
  }
  free(temp);
}

void deleteAtEnd()
{
  if (isEmpty())
  {
    printf("List is empty\n");
    return;
  }

  struct Node *temp = head;
  if (temp->next == NULL)
  {
    free(head);
    head = NULL;
    return;
  }

  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->prev->next = NULL;
  free(temp);
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
  for (int i = 0; i < pos && temp != NULL; i++)
  {
    temp = temp->next;
  }

  if (temp == NULL)
  {
    printf("Position out of bounds\n");
    return;
  }

  if (temp->next != NULL)
  {
    temp->next->prev = temp->prev;
  }
  if (temp->prev != NULL)
  {
    temp->prev->next = temp->next;
  }
  free(temp);
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
    printf("%d <-> ", temp->data);
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

  printf("Current Doubly Linked List: ");
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