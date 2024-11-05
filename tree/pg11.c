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

void inorderTraversal(Node *root, int *arr, int *index)
{
  if (root == NULL)
    return;

  inorderTraversal(root->left, arr, index);
  arr[(*index)++] = root->data;
  inorderTraversal(root->right, arr, index);
}

int compare(const void *a, const void *b)
{
  return (*(int *)a - *(int *)b);
}

Node *sortedArrayToBST(int *arr, int start, int end)
{
  if (start > end)
    return NULL;

  int mid = (start + end) / 2;
  Node *node = createNode(arr[mid]);

  node->left = sortedArrayToBST(arr, start, mid - 1);
  node->right = sortedArrayToBST(arr, mid + 1, end);

  return node;
}

Node *binaryTreeToBST(Node *root)
{
  if (root == NULL)
    return NULL;

  int size = 0;
  int *arr = (int *)malloc(1000 * sizeof(int));
  int index = 0;
  inorderTraversal(root, arr, &index);
  size = index;

  qsort(arr, size, sizeof(int), compare);

  Node *bstRoot = sortedArrayToBST(arr, 0, size - 1);

  free(arr);
  return bstRoot;
}

void printInorder(Node *root)
{
  if (root != NULL)
  {
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
  }
}

int main()
{
  Node *root = createNode(10);
  root->left = createNode(30);
  root->right = createNode(15);
  root->left->left = createNode(20);
  root->left->right = createNode(5);

  printf("Inorder Traversal of the original Binary Tree: ");
  printInorder(root);
  printf("\n");

  Node *bstRoot = binaryTreeToBST(root);

  printf("Inorder Traversal of the resulting Binary Search Tree: ");
  printInorder(bstRoot);
  printf("\n");

  return 0;
}