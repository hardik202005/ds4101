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

  if (isEmpty())
  {
    head = newNode;
    newNode->next = head;
  }
  else
  {
    struct Node *temp = head;
    while (temp->next != head)
    {
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
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
    if (temp == head)
    {
      printf("Position out of bounds\n");
      free(newNode);
      return;
    }
  }

  newNode->next = temp->next;
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
  }
  else
  {
    struct Node *temp = head;
    while (temp->next != head)
    {
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
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
    struct Node *temp = head;
    while (temp->next != head)
    {
      temp = temp->next;
    }
    temp->next = head->next;
    free(head);
    head = temp->next;
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
    struct Node *temp = head;
    while (temp->next->next != head)
    {
      temp = temp->next;
    }
    free(temp->next);
    temp->next = head;
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
  for (int i = 0; i < pos - 1; i++)
  {
    temp = temp->next;
    if (temp == head)
    {
      printf("Position out of bounds\n");
      return;
    }
  }

  struct Node *toDelete = temp->next;
  if (toDelete == head)
  {
    deleteAtBegin();
  }
  else
  {
    temp->next = toDelete->next;
    free(toDelete);
  }
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
    printf("%d -> ", temp->data);
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

  printf("Current Circular Linked List: ");
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