/*  Name: Markus Gavra
 *  Student ID: 1220576
 *  Date: November 29, 2024
 *  Description: Main file with menu and user input handling.
 *
 *  Assignment #2: Graph Traversal and Shortest Path Algorithms
 *  File: main.c - Main file with menu and user input handling.
 */

// Header Files
#include "graph.h"

// Main Function
int main(int argc, char *argv[])
{

    // Check if the correct number of arguments are provided
    if (argc != 2)
    {
        // Print the correct usage of the program
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Read the graph from the file
    Graph *graph = readGraph(argv[1]);
    
    // Check if the graph was created successfully
    if (graph == NULL)
    {
        // Print an error message if the graph could not be created
        printf("Error creating graph from file.\n");
        return 1;
    }

    // Variables
    int choice;
    int startVertex = 1;

    // Do-While loop to keep the program running
    do
    {

        // Display the options
        prompt();

        // Get user input
        printf("\nEnter a Choice: ");
        scanf("%d", &choice);

        // Perform the selected operation
        switch (choice) {
            
            // Display Adjacency List
            case 1:
                createAdjacencyList(graph);
                displayAdjacencyList(graph);
                break;

            // Perform Breadth-First Search (BFS)
            case 2:
                bfs(graph, startVertex);
                break;

            // Perform Depth-First Search (DFS)
            case 3:
                dfs(graph, startVertex);
                break;

            // Find Shortest Path using Dijkstra's Algorithm
            case 4:
                dijkstra(graph, startVertex);
                break;

            // Exit the program
            case 5:
                freeGraph(graph);
                printf("\n------ Exiting Program ------\n\n");
                return 0;

            // Default case
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }

    } while (true);

    return 0;
}
