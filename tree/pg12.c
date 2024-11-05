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

int findKthLargest(Node *root, int k)
{
  if (root == NULL || k <= 0)
    return -1;

  int size = 0;
  int *arr = (int *)malloc(1000 * sizeof(int));
  int index = 0;
  inorderTraversal(root, arr, &index);
  size = index;

  if (k > size)
  {
    free(arr);
    return -1;
  }

  int kthLargest = arr[size - k];
  free(arr);
  return kthLargest;
}

int main()
{
  Node *root = createNode(15);
  root->left = createNode(10);
  root->right = createNode(20);
  root->left->left = createNode(8);
  root->left->right = createNode(12);
  root->right->left = createNode(17);
  root->right->right = createNode(25);

  int k = 3;
  int kthLargest = findKthLargest(root, k);

  if (kthLargest != -1)
  {
    printf("The %dth largest element in the BST is: %d\n", k, kthLargest);
  }
  else
  {
    printf("Invalid K value or K exceeds the number of elements in the BST.\n");
  }

  return 0;
}