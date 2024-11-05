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

Node *buildTree(int postorder[], int inorder[], int inorderStart, int inorderEnd, int *postorderIndex)
{
  // Base case
  if (inorderStart > inorderEnd)
  {
    return NULL;
  }

  int rootValue = postorder[*postorderIndex];
  Node *root = createNode(rootValue);
  (*postorderIndex)--;

  if (inorderStart == inorderEnd)
  {
    return root;
  }

  int inorderIndex = search(inorder, inorderStart, inorderEnd, rootValue);

  root->right = buildTree(postorder, inorder, inorderIndex + 1, inorderEnd, postorderIndex);
  root->left = buildTree(postorder, inorder, inorderStart, inorderIndex - 1, postorderIndex);

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

  int postorder[] = {4, 5, 2, 6, 7, 3, 1};
  int inorder[] = {4, 2, 5, 1, 6, 3, 7};
  int n = sizeof(postorder) / sizeof(postorder[0]);
  int postorderIndex = n - 1;

  Node *root = buildTree(postorder, inorder, 0, n - 1, &postorderIndex);

  printf("Inorder traversal of the constructed tree: ");
  printInorder(root);
  printf("\n");

  return 0;
}
