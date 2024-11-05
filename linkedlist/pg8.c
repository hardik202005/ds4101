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

  if (isEmpty())
  {
    head = newNode;
    newNode->next = head;
    newNode->prev = head;
  }
  else
  {
    struct Node *tail = head->prev;
    newNode->next = head;
    newNode->prev = tail;
    tail->next = newNode;
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
  for (int i = 0; i < pos; i++)
  {
    if (temp == NULL)
    {
      printf("Position out of bounds\n");
      free(newNode);
      return;
    }
    temp = temp->next;
    if (temp == head)
      break;
  }

  newNode->next = temp;
  newNode->prev = temp->prev;
  temp->prev->next = newNode;
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

  if (isEmpty())
  {
    head = newNode;
    newNode->next = head;
    newNode->prev = head;
  }
  else
  {
    struct Node *tail = head->prev;
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = head;
    head->prev = newNode;
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

  if (head->next == head)
  {
    free(head);
    head = NULL;
  }
  else
  {
    struct Node *tail = head->prev;
    head = head->next;
    tail->next = head;
    head->prev = tail;
    free(temp);
  }
}

void deleteAtEnd()
{
  if (isEmpty())
  {
    printf("List is empty\n");
    return;
  }

  struct Node *tail = head->prev;

  if (tail == head)
  {
    free(tail);
    head = NULL;
  }
  else
  {
    struct Node *newTail = tail->prev;
    newTail->next = head;
    head->prev = newTail;
    free(tail);
  }
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
    if (temp == head)
      break;
  }

  if (temp == head)
  {
    printf("Position out of bounds\n");
    return;
  }

  temp->prev->next = temp->next;
  temp->next->prev = temp->prev;
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
  do
  {
    printf("%s <-> ", temp->data);
    temp = temp->next;
  } while (temp != head);
  printf("(back to head)\n");
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
  do
  {
    if (strcmp(temp->data, value) == 0)
    {
      printf("Value \"%s\" found at position %d\n", value, position);
      return;
    }
    position++;
    temp = temp->next;
  } while (temp != head);

  printf("Value \"%s\" not found in the list\n", value);
}

int main()
{
  insertAtEnd("Node1");
  insertAtEnd("Node2");
  insertAtBegin("Node0");
  insertAtPos("Node1.5", 2);

  printf("Current Doubly Circular Linked List: ");
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