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

  if (data < root->data)
  {
    root->left = insert(root->left, data);
  }
  else if (data > root->data)
  {
    root->right = insert(root->right, data);
  }

  return root;
}

int countNodes(Node *root)
{
  if (root == NULL)
  {
    return 0;
  }
  return 1 + countNodes(root->left) + countNodes(root->right);
}

int main()
{
  Node *root = NULL;
  int n, data;

  printf("Enter the number of nodes to insert into the BST: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    printf("Enter value for node %d: ", i + 1);
    scanf("%d", &data);
    root = insert(root, data);
  }

  int totalNodes = countNodes(root);
  printf("Total number of nodes in the Binary Search Tree: %d\n", totalNodes);

  return 0;
}