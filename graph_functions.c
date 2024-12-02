/*  Name: Markus Gavra
 *  Student ID: 1220576
 *  Date: November 29, 2024
 *  Description: This file contains the function implementations for the graph.h header file. 
 *               The functions are used to read a graph from a file, display the adjacency list, 
 *               perform BFS, DFS, and Dijkstra's algorithm, and free the memory allocated for the graph.
 * 
 *  Assignment #2: Graph Traversal and Shortest Path Algorithms
 *  File: graph_functions.c - Function implementations for the graph.h header file. 
 */

// Header Files
#include "graph.h"

/**
 * Displays the menu options for the user.
 * The user can choose from the following options:
 * 1. Display Adjacency List
 * 2. Perform Breadth-First Search (BFS)
 * 3. Perform Depth-First Search (DFS)
 * 4. Find Shortest Path using Dijkstra's Algorithm
 * 5. Exit
 *
 * The user is prompted to enter a choice.
 * The function does not take any arguments.
 * The function does not return anything.
 *
 * Function #1: Display the menu options for the user
 */

void prompt(void)
{
    printf("\nMenu:\n");
    printf("1. Display Adjacency List\n");
    printf("2. Perform Breadth-First Search (BFS)\n");
    printf("3. Perform Depth-First Search (DFS)\n");
    printf("4. Find Shortest Path using Dijkstra's Algorithm\n");
    printf("5. Exit\n");
}

/**
 * Reads a graph from a file and constructs the graph structure.
 * @param filename The name of the file containing the adjacency matrix.
 * @return Pointer to the created Graph structure, or NULL if an error occurs.
 *
 * Function #2: Read the graph from a file and construct the graph structure
 */

Graph *readGraph(const char *filename)
{
    // Open the file
    FILE *file = fopen(filename, "r");
    
    // Check if the file was opened successfully
    if (file == NULL)
    {
        // Print an error message if the file could not be opened
        printf("\nError opening file!\n");
        return NULL;
    }

    // Variables
    char buffer[100];
    int numVertices = 0;

    // Read the number of vertices from the file
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        numVertices++;
    }

    // Validate the number of vertices
    if (numVertices <= 0 || numVertices > MAX_VERTICES)
    {
        // Print an error message if the number of vertices is invalid
        printf("Error: Invalid number of vertices detected: %d\n", numVertices);
        fclose(file);
        return NULL;
    }

    // Allocate memory for the graph structure
    Graph *graph = malloc(sizeof(*graph));
    
    // Check if memory allocation was successful
    if (graph == NULL)
    {
        // Print an error message if memory allocation fails
        printf("\nMemory allocation failed!\n");
        fclose(file);
        return NULL;
    }

    // Initialize the graph
    graph->numVertices = numVertices;

    // Rewind the file to start reading the matrix
    rewind(file);

    // Parse the adjacency matrix
    for (int i = 0; i < numVertices; i++)
    {
        // Read a row from the file
        if (fgets(buffer, sizeof(buffer), file) == NULL)
        {
            // Print an error message if a row is missing
            printf("Error: Missing adjacency matrix row %d\n", i);
            freeGraph(graph);
            fclose(file);
            return NULL;
        }

        // Parse each number in the row
        char *token = strtok(buffer, " ");
        for (int j = 0; j < numVertices; j++)
        {
            // Check if the token is NULL
            if (token == NULL)
            {
                // Print an error message if a column is missing
                printf("Error: Missing columns in row %d\n", i);
                freeGraph(graph);
                fclose(file);
                return NULL;
            }

            // Convert the token to an integer and store it in the adjacency matrix
            graph->adjMatrix[i][j] = atoi(token);
            token = strtok(NULL, " ");
        }
    }

    // Close the file
    fclose(file);

    // Return the created graph
    return graph;
}

/**
 * Creates a new node for the adjacency list.
 * @param vertex The vertex number that this node will represent.
 * @return Pointer to the newly created Node structure.
 *
 * Function #3: Create a new node for the adjacency list
 */

Node *createNode(int vertex) 
{
    // Allocate memory for the new node
    Node *newNode = malloc(sizeof(*newNode));

    // Check if memory allocation was successful
    if (newNode != NULL)
    {
        // Initialize the node structure
        newNode->vertex = vertex;
        newNode->next = NULL;
    }

    else 
    {

        // Print an error message if memory allocation fails
        printf("\nMemory allocation failed!\n");
        return NULL;
    }

    // Return the newly created node
    return newNode;

}

/**
 * Displays the adjacency list of the graph.
 * @param graph Pointer to the Graph structure.
 *
 * Function #4: Display the adjacency list of the graph
 */

void displayAdjacencyList(Graph *graph)
{
    // Check if the graph is empty or not initialized
    if (graph == NULL)
    {
        // Print an error message if the graph is empty or not initialized
        printf("\nGraph is empty or not initialized.\n");
        return;
    }

    // Print the adjacency list representation of the graph
    printf("\n------ Adjacency List Representation: ------\n");

    // Iterate over each vertex in the graph
    for (int i = 0; i < graph->numVertices; i++)
    {
        // Print the vertex number (i + 1 for 1-based indexing)
        printf("Vertex %d:", i + 1); 
        
        // Get the adjacency list for the current vertex
        Node *current = graph->adjList[i];
        
        // Print the adjacency list for the current vertex
        while (current != NULL)
        {
            // Print the vertex number and the weight of the edge
            printf(" -> %d (%d)", current->vertex + 1, graph->adjMatrix[i][current->vertex]);
            current = current->next;
        }

        // Print NULL if the adjacency list is empty
        printf(" NULL\n");
    }
}

/**
 * Converts the adjacency matrix of the graph to an adjacency list.
 * @param graph Pointer to the Graph structure.
 *
 * Function #5: Convert the adjacency matrix to an adjacency list
 */

void createAdjacencyList(Graph *graph)
{
    // Checks if the graph is empty or not initialized
    if (graph == NULL)
    {
        printf("\nGraph is empty or not initialized.\n");
        return;
    }

    // Iterate over each vertex (source vertex)
    for (int i = 0; i < graph->numVertices; i++)
    {
        // Initialize the adjacency list for the current vertex
        Node *adjList = NULL;
        Node *lastNode = NULL; // Keep track of the last node in the list

        // Iterate over all vertices (destination vertex)
        for (int j = 0; j < graph->numVertices; j++)
        {
            // Check if there is an edge between the source and destination vertices
            if (graph->adjMatrix[i][j] != 0)
            {
                Node *newNode = createNode(j);

                // Check if memory allocation was successful
                if (newNode == NULL)
                {
                    // Print an error message if memory allocation fails
                    printf("\nMemory allocation failed!\n");
                    return;
                }

                if (adjList == NULL)
                {
                    // If the list is empty, the new node becomes the head
                    adjList = newNode;
                }
                
                else
                {
                    // If the list is not empty, add the new node to the end
                    lastNode->next = newNode;
                }

                // Update the last node to be the new node
                lastNode = newNode;
            }
        }

        // Assign the built adjacency list to the graph
        graph->adjList[i] = adjList;
    }
}

// Queue Functions for BFS Algorithms Function

// Function #5: creates a queue
Queue *createQueue()
{
    Queue *q = malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Function #6: checks if the queue is empty
bool isEmptyQueue(Queue *q)
{
    return q->rear == -1;
}

// Function #7: enqueues an item
void enqueue(Queue *q, int value)
{
    if (q->rear == MAX_VERTICES - 1)
    {
        printf("\nQueue is full\n");
        return;
    }
    
    if (q->front == -1)
    {
        q->front = 0;
    }
    
    q->rear++;
    q->items[q->rear] = value;
}

// Function #8: dequeues an item
int dequeue(Queue *q)
{
    if (isEmptyQueue(q))
    {
        printf("\nQueue is empty\n");
        return -1;
    }
    
    int item = q->items[q->front];

    q->front++;
    
    if (q->front > q->rear)
    {
        q->front = q->rear = -1;
    }
    return item;
}

// Function #9: frees the memory allocated for the queue
void freeQueue(Queue *q)
{
    if (q != NULL)
    {
        free(q);
    }
}

/**
 * Performs Breadth-First Search (BFS) starting from a given vertex.
 * @param graph Pointer to the Graph structure.
 * @param startVertex The vertex from which BFS starts (0-based index).
 *
 * Function #10: Perform Breadth-First Search (BFS)
 */

void bfs(Graph *graph, int startVertex)
{
    // Checks if the graph is empty or not initialized
    if (graph == NULL)
    {
        // Print an error message if the graph is empty or not initialized
        printf("\nGraph is empty or not initialized.\n");
        return;
    }

    // Create a queue for BFS
    Queue *queue = createQueue();

    // Create an array to keep track of visited vertices
    bool visited[MAX_VERTICES] = {false}; 

    // Enqueue the start vertex
    enqueue(queue, startVertex - 1);
    visited[startVertex - 1] = true;

    printf("\n------ BFS Traversal: ------\n");

    // Mark the start vertex as visited
    while (!isEmptyQueue(queue))
    {
        // Dequeue a vertex from the queue
        int currentVertex = dequeue(queue);
        
        // Print the vertex
        printf("%d ", currentVertex + 1);

        // Explore all neighbors of the current vertex
        Node *temp = graph->adjList[currentVertex];
        
        // Mark the current vertex as visited
        while (temp)
        {
            // Get the vertex number of the neighbor
            int neighbor = temp->vertex;
            
            // Check if the neighbor has been visited
            if (!visited[neighbor])
            {
                // Mark the neighbor as visited and enqueue it
                visited[neighbor] = true;
                enqueue(queue, neighbor);
            }

            // Move to the next neighbor
            temp = temp->next;
        }
    }

    // Free the memory allocated for the queue
    freeQueue(queue);
    printf("\n");
}

// Stacks Functions for DFS Algorithms Function

// Function #11: creates a stack
Stack *createStack()
{
    Stack *stack = malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

// Function #12: checks if the stack is empty
bool isEmptyStack(Stack *stack)
{
    return stack->top == -1;
}

// Function #13: pushes an item to the stack
void push(Stack *stack, int value)
{
    if (stack->top == MAX_VERTICES - 1)
    {
        printf("\nStack overflow\n");
        return;
    }
    stack->items[++stack->top] = value;
}

// Function #14: pops an item from the stack
int pop(Stack *stack)
{
    if (isEmptyStack(stack))
    {
        printf("\nStack underflow\n");
        return -1;
    }
    return stack->items[stack->top--];
}

// Function #15: frees the memory allocated for the stack
void freeStack(Stack *stack)
{
    if (stack != NULL)
    {
        free(stack);
    }
}

/**
 * Performs Depth-First Search (DFS) starting from a given vertex.
 * @param graph Pointer to the Graph structure.
 * @param startVertex The vertex from which DFS starts (0-based index).
 *
 * Function #16: Perform Depth-First Search (DFS)
 */

void dfs(Graph *graph, int startVertex)
{
    // Checks if the graph is empty or not initialized
    if (graph == NULL)
    {
        // Print an error message if the graph is empty or not initialized
        printf("\nGraph is empty or not initialized.\n");
        return;
    }

    // Create a stack for DFS
    Stack *stack = createStack();

    // Create an array to keep track of visited vertices
    bool visited[MAX_VERTICES] = {false};

    // Push the starting vertex onto the stack
    push(stack, startVertex - 1);

    // Print the DFS traversal
    printf("\n------ DFS Traversal: ------\n");

    while (!isEmptyStack(stack))
    {
        // Pop the current vertex from the stack
        int currentVertex = pop(stack);

        // Process the vertex if it hasn't been visited
        if (!visited[currentVertex])
        {
            // Print the vertex
            printf("%d ", currentVertex + 1);

            // Mark the current vertex as visited
            visited[currentVertex] = true;

            // Push each unvisited adjacent vertex to the stack
            Node *temp = graph->adjList[currentVertex];

            // First, gather neighbors into a temporary array to reverse the order
            int neighbors[MAX_VERTICES];
            int count = 0;

            while (temp != NULL)
            {
                // Check if the neighbor has been visited
                if (!visited[temp->vertex])
                {
                    // Store the neighbor in the temporary array
                    neighbors[count++] = temp->vertex; 
                }

                // Move to the next neighbor
                temp = temp->next;
            }

            // Push neighbors to the stack in reverse order
            for (int i = count - 1; i >= 0; i--)
            {
                // Push the neighbor to the stack
                push(stack, neighbors[i]);
            }
        }
    }

    // Free the memory allocated for the stack
    freeStack(stack);
    printf("\n");
}

/**
 * Finds the shortest path from the start vertex to all other vertices using Dijkstra's algorithm.
 * @param graph Pointer to the Graph structure.
 * @param startVertex The vertex from which to start the algorithm (0-based index).
 * 
 * Function #17: Find the shortest path using Dijkstra's algorithm
 */

void dijkstra(Graph *graph, int startVertex)
{
    // Checks if the graph is empty or not initialized
    if (graph == NULL)
    {
        // Print an error message if the graph is empty or not initialized
        printf("\nGraph is empty or not initialized.\n");
        return;
    }

    // Arrays to store the distance and visited status of each vertex
    int distance[MAX_VERTICES];
    bool sptSet[MAX_VERTICES];

    // Initialize the distance and visited arrays
    for (int i = 0; i < graph->numVertices; i++)
    {
        // Set the distance to infinity and visited status to false
        distance[i] = INT_MAX;
        sptSet[i] = false;
    }

    // Set the distance of the start vertex to 0
    distance[startVertex - 1] = 0;

    // Find the shortest path for all vertices
    for (int count = 0; count < graph->numVertices - 1; count++)
    {
        // Find the vertex with the minimum distance value
        int minDistance = INT_MAX;
        int minIndex = -1;

        for (int i = 0; i < graph->numVertices; i++)
        {
            if (!sptSet[i] && distance[i] <= minDistance)
            {
                minDistance = distance[i];
                minIndex = i;
            }
        }

        // Mark the selected vertex as visited
        sptSet[minIndex] = true;

        // Update the distance value of the adjacent vertices
        for (int i = 0; i < graph->numVertices; i++)
        {
            if (!sptSet[i] && graph->adjMatrix[minIndex][i] && distance[minIndex] != INT_MAX && distance[minIndex] + graph->adjMatrix[minIndex][i] < distance[i])
            {
                distance[i] = distance[minIndex] + graph->adjMatrix[minIndex][i];
            }
        }

        // Prints the shortest path from the start vertex to all other vertices
        printf("\n------ Shortest Path from Vertex %d to Vertex %d ------\n\n", startVertex, minIndex + 1);
        
        // Print the shortest path from the start vertex to all other vertices
        for (int i = 0; i < graph->numVertices; i++)
        {
            // Print the vertex number and the distance from the start vertex
            if (distance[i] != INT_MAX)
            {
                printf("Shortest distance from Vertex %d to Vertex %d: %d\n", startVertex, i + 1, distance[i]);
            }

            // Print "INF" if the distance is infinity
            else
            {
                printf("%d\tINF\n", i + 1);
            }
        }
    }    
}

/**
 * Frees the memory allocated for the graph, including the adjacency list.
 * @param graph Pointer to the Graph structure to be freed.
 * 
 * Function #18: Free the memory allocated for the graph
 */

void freeGraph(Graph *graph)
{
    // Check if the graph is empty or not initialized
    if (graph == NULL)
    {
        // Print an error message if the graph is empty or not initialized
        printf("\nGraph is empty or not initialized.\n");
        return;
    }

    // Free the adjacency list for each vertex
    for (int i = 0; i < graph->numVertices; i++)
    {
        // Free each node in the adjacency list
        Node *current = graph->adjList[i];
        
        // Free each node in the adjacency list
        while (current != NULL)
        {
            // Free the current node and move to the next node
            Node *next = current->next;
            free(current);
            current = next;
        }
    }

    // Free the graph structure itself
    free(graph);
}