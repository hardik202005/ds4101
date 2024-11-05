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

Node *constructBSTFromPostorder(int *postorder, int size)
{
  if (size == 0)
    return NULL;

  Node **stack = (Node **)malloc(size * sizeof(Node *));
  int top = -1;

  Node *root = createNode(postorder[size - 1]);
  stack[++top] = root;

  for (int i = size - 2; i >= 0; i--)
  {
    Node *temp = NULL;

    Node *newNode = createNode(postorder[i]);

    while (top >= 0 && postorder[i] < stack[top]->data)
    {
      temp = stack[top];
      top--;
    }

    if (temp != NULL)
    {
      temp->left = newNode;
    }
    else
    {
      stack[top]->right = newNode;
    }

    stack[++top] = newNode;
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
  int postorder[] = {1, 7, 5, 50, 40, 10};
  int size = sizeof(postorder) / sizeof(postorder[0]);

  Node *root = constructBSTFromPostorder(postorder, size);

  printf("Inorder Traversal of the constructed BST: ");
  inorderTraversal(root);
  printf("\n");

  return 0;
}