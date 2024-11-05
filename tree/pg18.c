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

Node *insert(Node *root, int data)
{
  if (root == NULL)
  {
    return createNode(data);
  }

  Node **queue = (Node **)malloc(100 * sizeof(Node *));
  int front = 0, rear = 0;

  queue[rear++] = root;

  while (front < rear)
  {
    Node *current = queue[front++];

    if (current->left == NULL)
    {
      current->left = createNode(data);
      free(queue);
      return root;
    }
    else
    {
      queue[rear++] = current->left;
    }

    if (current->right == NULL)
    {
      current->right = createNode(data);
      free(queue);
      return root;
    }
    else
    {
      queue[rear++] = current->right;
    }
  }

  free(queue);
  return root;
}

void inorderTraversal(Node *root)
{
  if (root != NULL)
  {
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
  }
}

int main()
{
  Node *root = NULL;
  int n, data;

  printf("Enter the number of nodes to insert (almost complete binary tree): ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    printf("Enter value for node %d: ", i + 1);
    scanf("%d", &data);
    root = insert(root, data);
  }

  printf("Inorder Traversal of the constructed Almost Complete Binary Tree: ");
  inorderTraversal(root);
  printf("\n");

  return 0;
}