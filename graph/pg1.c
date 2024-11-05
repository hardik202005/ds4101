#include <stdio.h>

#define MAX_VERTICES 10

void printAdjacencyMatrix(int matrix[MAX_VERTICES][MAX_VERTICES], int vertices)
{
  printf("Adjacency Matrix:\n");

  for (int i = 0; i < vertices; i++)
  {
    for (int j = 0; j < vertices; j++)
    {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  int vertices, edges;
  int matrix[MAX_VERTICES][MAX_VERTICES] = {0};

  printf("Enter the number of vertices (max %d): ", MAX_VERTICES);
  scanf("%d", &vertices);

  printf("Enter the number of edges: ");
  scanf("%d", &edges);

  for (int i = 0; i < edges; i++)
  {
    int src, dest;
    printf("Enter edge %d (format: src dest): ", i + 1);
    scanf("%d %d", &src, &dest);

    if (src >= 0 && src < vertices && dest >= 0 && dest < vertices)
    {

      matrix[src][dest] = 1;
      matrix[dest][src] = 1;
    }
    else
    {
      printf("Invalid edge! Please enter vertices between 0 and %d.\n", vertices - 1);
      i--;
    }
  }

  printAdjacencyMatrix(matrix, vertices);

  return 0;
}