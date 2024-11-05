#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

struct Node
{
  char data[MAX_STRING_LENGTH];
  struct Node *next;
  struct Node *prev;
};

struct Node *head = NULL;

int isEmpty()
{
  return head == NULL;
}

void insertAtBegin(const char *value)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  strncpy(newNode->data, value, MAX_STRING_LENGTH);
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

void insertAtPos(const char *value, int pos)
{
  if (pos == 0)
  {
    insertAtBegin(value);
    return;
  }

  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  strncpy(newNode->data, value, MAX_STRING_LENGTH);

  struct Node *temp = head;
  for (int i = 0; i < pos - 1; i++)
  {
    if (temp == NULL)
    {
      printf("Position out of bounds\n");
      free(newNode);
      return;
    }
    temp = temp->next;
  }

  newNode->next = temp;
  newNode->prev = temp->prev;

  if (temp->prev != NULL)
  {
    temp->prev->next = newNode;
  }
  temp->prev = newNode;

  if (pos == 1)
  {
    head = newNode;
  }
}

void insertAtEnd(const char *value)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  strncpy(newNode->data, value, MAX_STRING_LENGTH);
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
  while (temp->next != NULL)
  {
    temp = temp->next;
  }

  if (temp->prev != NULL)
  {
    temp->prev->next = NULL;
  }
  else
  {
    head = NULL;
  }
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
  for (int i = 0; i < pos; i++)
  {
    if (temp == NULL)
    {
      printf("Position out of bounds\n");
      return;
    }
    temp = temp->next;
  }

  if (temp == NULL)
  {
    printf("Position out of bounds\n");
    return;
  }

  if (temp->prev != NULL)
  {
    temp->prev->next = temp->next;
  }

  if (temp->next != NULL)
  {
    temp->next->prev = temp->prev;
  }

  free(temp);
}

int isFull()
{
  return 0;
}

void display()
{
  if (isEmpty())
  {
    printf("List is empty\n");
    return;
  }

  struct Node *temp = head;
  while (temp != NULL)
  {
    printf("%s <-> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

void search(const char *value)
{
  if (isEmpty())
  {
    printf("List is empty\n");
    return;
  }

  struct Node *temp = head;
  int position = 0;
  while (temp != NULL)
  {
    if (strcmp(temp->data, value) == 0)
    {
      printf("Value \"%s\" found at position %d\n", value, position);
      return;
    }
    position++;
    temp = temp->next;
  }
  printf("Value \"%s\" not found in the list\n", value);
}

int main()
{
  insertAtEnd("Node1");
  insertAtEnd("Node2");
  insertAtBegin("Node0");
  insertAtPos("Node1.5", 2);

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

  search("Node1.5");
  search("Node3");

  return 0;
}