#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

typedef struct Queue
{
  int items[100];
  int front;
  int rear;
} Queue;

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

void initQueue(Queue *q)
{
  q->front = -1;
  q->rear = -1;
}

bool isEmpty(Queue *q)
{
  return q->front == -1;
}

void enqueue(Queue *q, int value)
{
  if (q->rear == 99)
    return;
  if (isEmpty(q))
    q->front = 0;
  q->items[++(q->rear)] = value;
}

int dequeue(Queue *q)
{
  if (isEmpty(q))
    return -1;
  int item = q->items[q->front];
  if (q->front >= q->rear)
  {
    q->front = -1;
    q->rear = -1;
  }
  else
  {
    q->front++;
  }
  return item;
}

void bfs(Graph *graph, int startVertex)
{
  bool visited[100] = {false};
  Queue q;
  initQueue(&q);

  visited[startVertex] = true;
  enqueue(&q, startVertex);

  printf("Breadth First Search (BFS) starting from vertex %d:\n", startVertex);

  while (!isEmpty(&q))
  {
    int currentVertex = dequeue(&q);
    printf("%d ", currentVertex);

    Node *adjList = graph->adjLists[currentVertex];
    while (adjList != NULL)
    {
      int connectedVertex = adjList->vertex;
      if (!visited[connectedVertex])
      {
        visited[connectedVertex] = true;
        enqueue(&q, connectedVertex);
      }
      adjList = adjList->next;
    }
  }
  printf("\n");
}

int main()
{
  int vertices, edges;

  printf("Enter the number of vertices: ");
  scanf("%d", &vertices);

  Graph *graph = createGraph(vertices);

  printf("Enter the number of edges: ");
  scanf("%d", &edges);

  for (int i = 0; i < edges; i++)
  {
    int src, dest;
    printf("Enter edge %d (format: src dest): ", i + 1);
    scanf("%d %d", &src, &dest);
    addEdge(graph, src, dest);
  }

  bfs(graph, 0);

  for (int i = 0; i < vertices; i++)
  {
    Node *temp = graph->adjLists[i];
    while (temp)
    {
      Node *toFree = temp;
      temp = temp->next;
      free(toFree);
    }
  }
  free(graph->adjLists);
  free(graph);

  return 0;
}