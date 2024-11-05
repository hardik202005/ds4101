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
  else if (data > root->data)
  {
    root->right = insert(root->right, data);
  }
  return root;
}

Node *search(Node *root, int data)
{
  if (root == NULL || root->data == data)
  {
    return root;
  }
  if (data < root->data)
  {
    return search(root->left, data);
  }
  else
  {
    return search(root->right, data);
  }
}

Node *minimum(Node *root)
{
  while (root && root->left != NULL)
  {
    root = root->left;
  }
  return root;
}

Node *deleteNode(Node *root, int data)
{
  if (root == NULL)
    return root;
  if (data < root->data)
  {
    root->left = deleteNode(root->left, data);
  }
  else if (data > root->data)
  {
    root->right = deleteNode(root->right, data);
  }
  else
  {

    if (root->left == NULL)
    {
      Node *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL)
    {
      Node *temp = root->left;
      free(root);
      return temp;
    }

    Node *temp = minimum(root->right);
    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
  }
  return root;
}

void preorder(Node *root)
{
  if (root != NULL)
  {
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

void inorder(Node *root)
{
  if (root != NULL)
  {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

void postorder(Node *root)
{
  if (root != NULL)
  {
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
  }
}

int main()
{
  Node *root = NULL;
  int choice, value;

  while (1)
  {
    printf("\nBinary Search Tree Operations:\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Search\n");
    printf("4. Preorder Traversal\n");
    printf("5. Inorder Traversal\n");
    printf("6. Postorder Traversal\n");
    printf("7. Find Minimum Element\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter value to insert: ");
      scanf("%d", &value);
      root = insert(root, value);
      break;
    case 2:
      printf("Enter value to delete: ");
      scanf("%d", &value);
      root = deleteNode(root, value);
      break;
    case 3:
      printf("Enter value to search: ");
      scanf("%d", &value);
      Node *searchResult = search(root, value);
      if (searchResult)
      {
        printf("Value %d found in the tree.\n", value);
      }
      else
      {
        printf("Value %d not found in the tree.\n", value);
      }
      break;
    case 4:
      printf("Preorder Traversal: ");
      preorder(root);
      printf("\n");
      break;
    case 5:
      printf("Inorder Traversal: ");
      inorder(root);
      printf("\n");
      break;
    case 6:
      printf("Postorder Traversal: ");
      postorder(root);
      printf("\n");
      break;
    case 7:
      Node *minNode = minimum(root);
      if (minNode)
      {
        printf("Minimum element in the tree: %d\n", minNode->data);
      }
      else
      {
        printf("The tree is empty.\n");
      }
      break;
    case 8:
      exit(0);
    default:
      printf("Invalid choice! Please try again.\n");
    }
  }

  return 0;
}