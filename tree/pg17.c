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

  if (root->left == NULL)
  {
    root->left = insert(root->left, data);
  }
  else if (root->right == NULL)
  {
    root->right = insert(root->right, data);
  }
  else
  {

    printf("Cannot insert %d: Both children are present for node %d\n", data, root->data);
  }

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

  printf("Enter the number of nodes to insert (should be a full binary tree): ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    printf("Enter value for node %d: ", i + 1);
    scanf("%d", &data);
    root = insert(root, data);
  }

  printf("Inorder Traversal of the constructed Strictly Binary Tree: ");
  inorderTraversal(root);
  printf("\n");

  return 0;
}