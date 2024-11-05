#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

struct Node
{
  char data[MAX_STRING_LENGTH];
  struct Node *next;
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
  head = newNode;
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

void insertAtEnd(const char *value)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  strncpy(newNode->data, value, MAX_STRING_LENGTH);
  newNode->next = NULL;

  if (isEmpty())
  {
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
  for (int i = 0; i < pos - 1; i++)
  {
    temp = temp->next;
    if (temp == NULL)
    {
      printf("Position out of bounds\n");
      return;
    }
  }

  struct Node *toDelete = temp->next;
  if (toDelete == NULL)
  {
    printf("Position out of bounds\n");
    return;
  }

  temp->next = toDelete->next;
  free(toDelete);
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
    printf("%s -> ", temp->data);
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

  printf("Current Singly Linked List: ");
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