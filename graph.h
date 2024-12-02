// Libraries Used
#ifndef GRAPH_H
#define GRAPH_H

// Libraries Used
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

// Define maximum number of vertices in the graph
#define MAX_VERTICES 100

// Structure representing a node in an adjacency list
typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

// Structure representing a graph
typedef struct Graph
{
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
    Node *adjList[MAX_VERTICES];
} Graph;

// Queue structure for BFS
typedef struct Queue
{
    int items[MAX_VERTICES];
    int front, rear;
} Queue;

// Stack structure for DFS
typedef struct Stack
{
    int items[MAX_VERTICES];
    int top;
} Stack;

// Graph Function definitions
void prompt(void);
Graph *readGraph(const char *filename);
Node *createNode(int vertex);
void displayAdjacencyList(Graph *graph);
void createAdjacencyList(Graph *graph);

// Queue Functions defintions for BFS Algorithms Function
Queue *createQueue();
bool isEmptyQueue(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q); 
void freeQueue(Queue *q);
void bfs(Graph *graph, int startVertex);

// Stack Functions definitions for DFS Algorithms Function
Stack *createStack();
bool isStackEmpty(Stack *stack);
void push(Stack *stack, int value);
int pop(Stack *stack);
void freeStack(Stack *stack);
void dfs(Graph *graph, int startVertex);

// Dijkstra's Algorithm Function
void dijkstra(Graph *graph, int startVertex);

// Free definition for freeing the memory allocated for the graph
void freeGraph(Graph *graph);

#endif // GRAPH_H
