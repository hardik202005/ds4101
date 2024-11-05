#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10

typedef struct Queue
{
  int items[MAX_VERTICES];
  int front;
  int rear;
} Queue;

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
  if (q->rear == MAX_VERTICES - 1)
  {
    printf("Queue is full!\n");
    return;
  }
  if (isEmpty(q))
  {
    q->front = 0;
  }
  q->items[++q->rear] = value;
}

int dequeue(Queue *q)
{
  if (isEmpty(q))
  {
    printf("Queue is empty!\n");
    return -1;
  }
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

void bfs(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices, int startVertex)
{
  bool visited[MAX_VERTICES] = {false};
  Queue q;
  initQueue(&q);

  visited[startVertex] = true;
  enqueue(&q, startVertex);
  printf("Breadth First Search (BFS) starting from vertex %d:\n", startVertex);

  while (!isEmpty(&q))
  {
    int currentVertex = dequeue(&q);
    printf("%d ", currentVertex);

    for (int i = 0; i < numVertices; i++)
    {
      if (graph[currentVertex][i] == 1 && !visited[i])
      {
        visited[i] = true;
        enqueue(&q, i);
      }
    }
  }
  printf("\n");
}

int main()
{
  int vertices, graph[MAX_VERTICES][MAX_VERTICES];

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

  bfs(graph, vertices, 0);

  return 0;
}