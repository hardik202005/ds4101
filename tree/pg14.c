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
  else
  {
    root->right = insert(root->right, data);
  }
  return root;
}

void postorderTraversal(Node *root)
{
  if (root == NULL)
    return;

  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d ", root->data);
}

Node *preorderToBST(int *preorder, int *index, int size)
{
  if (*index >= size)
    return NULL;

  Node *root = createNode(preorder[*index]);
  (*index)++;

  while (*index < size && preorder[*index] < root->data)
  {
    root->left = preorderToBST(preorder, index, size);
  }
  root->right = preorderToBST(preorder, index, size);

  return root;
}

int main()
{
  int preorder[] = {10, 5, 3, 7, 15, 12, 20};
  int size = sizeof(preorder) / sizeof(preorder[0]);
  int index = 0;

  Node *root = preorderToBST(preorder, &index, size);

  printf("Postorder Traversal: ");
  postorderTraversal(root);
  printf("\n");

  return 0;
}