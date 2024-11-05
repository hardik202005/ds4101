#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int vertex;
  struct Node *next;
} Node;

typedef struct Graph
{
  int numVertices;
  Node **adjLists;
} Graph;

Node *createNode(int vertex)
{
  Node *newNode = malloc(sizeof(Node));
  newNode->vertex = vertex;
  newNode->next = NULL;
  return newNode;
}

Graph *createGraph(int vertices)
{
  Graph *graph = malloc(sizeof(Graph));
  graph->numVertices = vertices;
  graph->adjLists = malloc(vertices * sizeof(Node *));

  for (int i = 0; i < vertices; i++)
  {
    graph->adjLists[i] = NULL;
  }
  return graph;
}

void addEdge(Graph *graph, int src, int dest)
{

  Node *newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;

  newNode = createNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}

void deleteEdge(Graph *graph, int src, int dest)
{
  Node *temp = graph->adjLists[src];
  Node *prev = NULL;

  while (temp != NULL && temp->vertex != dest)
  {
    prev = temp;
    temp = temp->next;
  }
  if (temp != NULL)
  {
    if (prev == NULL)
    {
      graph->adjLists[src] = temp->next;
    }
    else
    {
      prev->next = temp->next;
    }
    free(temp);
  }

  temp = graph->adjLists[dest];
  prev = NULL;

  while (temp != NULL && temp->vertex != src)
  {
    prev = temp;
    temp = temp->next;
  }
  if (temp != NULL)
  {
    if (prev == NULL)
    {
      graph->adjLists[dest] = temp->next;
    }
    else
    {
      prev->next = temp->next;
    }
    free(temp);
  }
}

void printGraph(Graph *graph)
{
  for (int v = 0; v < graph->numVertices; v++)
  {
    Node *temp = graph->adjLists[v];
    printf("Vertex %d:", v);
    while (temp)
    {
      printf(" -> %d", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}

int main()
{
  int vertices, edges, src, dest;

  printf("Enter the number of vertices: ");
  scanf("%d", &vertices);

  Graph *graph = createGraph(vertices);

  printf("Enter the number of edges: ");
  scanf("%d", &edges);

  for (int i = 0; i < edges; i++)
  {
    printf("Enter edge %d (format: src dest): ", i + 1);
    scanf("%d %d", &src, &dest);
    addEdge(graph, src, dest);
  }

  printf("\nGraph representation:\n");
  printGraph(graph);

  printf("Enter edge to delete (format: src dest): ");
  scanf("%d %d", &src, &dest);
  deleteEdge(graph, src, dest);

  printf("\nGraph after deletion:\n");
  printGraph(graph);

  return 0;
}