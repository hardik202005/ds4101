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

int maxDepth(Node *node)
{

  if (node == NULL)
  {
    return 0;
  }

  int leftDepth = maxDepth(node->left);
  int rightDepth = maxDepth(node->right);

  return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

int main()
{

  Node *root = createNode(1);
  root->left = createNode(2);
  root->right = createNode(3);
  root->left->left = createNode(4);
  root->left->right = createNode(5);
  root->right->left = createNode(6);

  int depth = maxDepth(root);
  printf("Maximum Depth of the Binary Tree: %d\n", depth);

  return 0;
}