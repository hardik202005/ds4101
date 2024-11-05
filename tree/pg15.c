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

Node *constructBSTFromPreorder(int *preorder, int size)
{
  if (size == 0)
    return NULL;

  Node *root = createNode(preorder[0]);
  Node **stack = (Node **)malloc(size * sizeof(Node *));
  int top = -1;
  stack[++top] = root;

  for (int i = 1; i < size; i++)
  {
    Node *temp = NULL;

    while (top >= 0 && preorder[i] > stack[top]->data)
    {
      temp = stack[top];
      top--;
    }

    if (temp != NULL)
    {
      temp->right = createNode(preorder[i]);
      stack[++top] = temp->right;
    }
    else
    {
      stack[top]->left = createNode(preorder[i]);
      stack[++top] = stack[top]->left;
    }
  }

  free(stack);
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
  int preorder[] = {10, 5, 1, 7, 40, 50};
  int size = sizeof(preorder) / sizeof(preorder[0]);

  Node *root = constructBSTFromPreorder(preorder, size);

  printf("Inorder Traversal of the constructed BST: ");
  inorderTraversal(root);
  printf("\n");

  return 0;
}