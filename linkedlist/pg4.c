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
  for (int i = 0; i < pos - 1; i++)
  {
    temp = temp->next;
    if (temp == head)
    {
      printf("Position out of bounds\n");
      free(newNode);
      return;
    }
  }

  newNode->next = temp->next;
  newNode->prev = temp;

  if (temp->next != head)
  {
    temp->next->prev = newNode;
  }

  temp->next = newNode;
}

void insertAtEnd(int value)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = value;

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

  if (head->next == head)
  {
    free(head);
    head = NULL;
  }
  else
  {
    struct Node *tail = head->prev;
    struct Node *temp = head;
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

  if (head->next == head)
  {
    free(head);
    head = NULL;
  }
  else
  {
    struct Node *tail = head->prev;
    tail->prev->next = head;
    head->prev = tail->prev;
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
    temp = temp->next;
    if (temp == head)
    {
      printf("Position out of bounds\n");
      return;
    }
  }

  if (temp->next != head)
  {
    temp->next->prev = temp->prev;
  }
  temp->prev->next = temp->next;
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
    printf("%d <-> ", temp->data);
    temp = temp->next;
  } while (temp != head);
  printf("(back to head)\n");
}

void search(int value)
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
    if (temp->data == value)
    {
      printf("Value %d found at position %d\n", value, position);
      return;
    }
    position++;
    temp = temp->next;
  } while (temp != head);

  printf("Value %d not found in the list\n", value);
}

int main()
{
  insertAtEnd(10);
  insertAtEnd(20);
  insertAtBegin(5);
  insertAtPos(15, 2);

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

  search(15);
  search(100);

  return 0;
}