#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
} Node;

Node *createNode(int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}

typedef struct Queue
{
  Node **array;
  int front;
  int rear;
  int capacity;
} Queue;

Queue *createQueue(int capacity)
{
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  queue->capacity = capacity;
  queue->front = queue->rear = 0;
  queue->array = (Node **)malloc(capacity * sizeof(Node *));
  return queue;
}

int isEmpty(Queue *queue)
{
  return queue->front == queue->rear;
}

void enqueue(Queue *queue, Node *node)
{
  queue->array[queue->rear++] = node;
}

Node *dequeue(Queue *queue)
{
  return queue->array[queue->front++];
}

void rightView(Node *root)
{
  if (root == NULL)
  {
    return;
  }

  Queue *queue = createQueue(100);
  enqueue(queue, root);

  while (!isEmpty(queue))
  {
    int nodeCount = queue->rear - queue->front;
    for (int i = 0; i < nodeCount; i++)
    {
      Node *currentNode = dequeue(queue);

      if (i == nodeCount - 1)
      {
        printf("%d ", currentNode->data);
      }

      if (currentNode->left != NULL)
      {
        enqueue(queue, currentNode->left);
      }
      if (currentNode->right != NULL)
      {
        enqueue(queue, currentNode->right);
      }
    }
  }

  free(queue->array);
  free(queue);
}

int main()
{

  Node *root = createNode(1);
  root->left = createNode(2);
  root->right = createNode(3);
  root->left->left = createNode(4);
  root->left->right = createNode(5);
  root->right->left = createNode(6);
  root->right->right = createNode(7);

  printf("Right View of the Binary Tree: ");
  rightView(root);
  printf("\n");

  return 0;
}