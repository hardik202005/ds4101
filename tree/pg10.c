#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool hasDeadEnd(Node *root)
{
  if (root == NULL)
  {
    return false;
  }

  if (root->left == NULL && root->right == NULL)
  {
    return true;
  }

  return hasDeadEnd(root->left) || hasDeadEnd(root->right);
}

bool checkDeadEnds(Node *root)
{
  if (root == NULL)
    return false;

  if (root->left == NULL && root->right == NULL)
  {
    return false;
  }

  if (root->left && root->right)
  {
    return checkDeadEnds(root->left) || checkDeadEnds(root->right);
  }

  if (root->left)
  {

    return checkDeadEnds(root->left);
  }
  else
  {
    return checkDeadEnds(root->right);
  }
}

int main()
{
  Node *root = NULL;
  root = insert(root, 10);
  root = insert(root, 5);
  root = insert(root, 15);
  root = insert(root, 3);
  root = insert(root, 7);
  root = insert(root, 12);
  root = insert(root, 17);

  if (checkDeadEnds(root))
  {
    printf("The BST contains dead ends.\n");
  }
  else
  {
    printf("The BST does not contain dead ends.\n");
  }

  return 0;
}