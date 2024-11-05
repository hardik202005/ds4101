#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10

void dfs(int graph[MAX_VERTICES][MAX_VERTICES], int visited[], int vertex, int numVertices)
{

  visited[vertex] = true;
  printf("%d ", vertex);

  for (int i = 0; i < numVertices; i++)
  {

    if (graph[vertex][i] == 1 && !visited[i])
    {
      dfs(graph, visited, i, numVertices);
    }
  }
}

int main()
{
  int vertices, graph[MAX_VERTICES][MAX_VERTICES] = {0};

  printf("Enter the number of vertices: ");
  scanf("%d", &vertices);

  printf("Enter the adjacency matrix (%d x %d):\n", vertices, vertices);
  for (int i = 0; i < vertices; i++)
  {
    for (int j = 0; j < vertices; j++)
    {
      scanf("%d", &graph[i][j]);
    }
  }

  int visited[MAX_VERTICES] = {0};

  printf("Depth First Search (DFS) traversal starting from vertex 0:\n");
  dfs(graph, visited, 0, vertices);

  printf("\n");
  return 0;
}