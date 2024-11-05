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
int search(int arr[], int start, int end, int value)
{
  for (int i = start; i <= end; i++)
  {
    if (arr[i] == value)
    {
      return i;
    }
  }
  return -1;
}

Node *buildTree(int preorder[], int inorder[], int inorderStart, int inorderEnd, int *preorderIndex)
{

  if (inorderStart > inorderEnd)
  {
    return NULL;
  }

  int rootValue = preorder[*preorderIndex];
  Node *root = createNode(rootValue);
  (*preorderIndex)++;

  if (inorderStart == inorderEnd)
  {
    return root;
  }

  int inorderIndex = search(inorder, inorderStart, inorderEnd, rootValue);

  root->left = buildTree(preorder, inorder, inorderStart, inorderIndex - 1, preorderIndex);
  root->right = buildTree(preorder, inorder, inorderIndex + 1, inorderEnd, preorderIndex);

  return root;
}

void printInorder(Node *node)
{
  if (node == NULL)
  {
    return;
  }
  printInorder(node->left);
  printf("%d ", node->data);
  printInorder(node->right);
}

int main()
{

  int preorder[] = {1, 2, 4, 5, 3, 6, 7};
  int inorder[] = {4, 2, 5, 1, 6, 3, 7};
  int n = sizeof(preorder) / sizeof(preorder[0]);
  int preorderIndex = 0;

  Node *root = buildTree(preorder, inorder, 0, n - 1, &preorderIndex);

  printf("Inorder traversal of the constructed tree: ");
  printInorder(root);
  printf("\n");

  return 0;
}