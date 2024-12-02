# CIS2520-F24-A4

## Student Information 
Name            : Markus Gavra
Student Number  : 1277056
Email           : mgavra@uoguelph.ca

## Assignment Overview
What is the assignment about?  
Explain the purpose of the program and what it accomplishes.

- `Purpose`: This assignment was all about reading an adjacency matrix that was stored within a txt file and then reading it into our program and building a graph structure
             and then with that building an adjacency list using a linked list. After process the graph and create the following structure, we then had to code three different 
             algorithms which were Breadth-First Search (BFS), Depth-First Search (DFS), Find Shortest Path using Dijkstra's Algorithm. After all this was done we had to build 
             run the program with a given menu and make sure our code had proper error messages and no memory leaks

- `What did it accomplishes`: This program successfully:

                              - Read and processed adjacency matrices from text files to construct graph structures.
                              - Converted the adjacency matrix into an adjacency list representation using a linked list.
                              - Implemented and tested the three required algorithms:
                              - BFS: For exploring vertices layer by layer.
                              - DFS: For exploring vertices in depth-first order.
                              - Dijkstra's Algorithm: For calculating the shortest path between vertices.
                              - Provided a user-friendly menu interface for interaction.
                              - Ensured robustness by addressing potential errors and edge cases.
                              - Verified memory management to prevent leaks, ensuring the program runs efficiently.

- `Error Handling`: Within this assignment I ensure that proper error messages were made for invalid inputs, empty graph, failure to read txt file, and etc

- `Memory Testing`: Made sure to free the graph, linked list, queue, and stack used within my program
                    ==47271== HEAP SUMMARY:
                    ==47271==     in use at exit: 0 bytes in 0 blocks
                    ==47271==   total heap usage: 19 allocs, 19 frees, 48,428 bytes allocated
                    ==47271== 
                    ==47271== All heap blocks were freed -- no leaks are possible
                    ==47271== 
                    ==47271== For lists of detected and suppressed errors, rerun with: -s
                    ==47271== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

## Compiling the program
To compile and run the program, follow these steps:

1. Compile the program by using the provided makefile. Simply run `make` in your terminal.
   
2. Once compiled, execute the program by typing: `./Matrix example-graph.txt`

3. The program will launch, and you can interact with it through the terminal interface to perform various algorithms search operations.

4. After you finish running the program, you can simiply do `make clean` to clean the program

## Resources 
Did you use any resources (for example book, notes etc) in this assignment?
- `Youtube`: To learn and understand the algorithms btter
- `Lecture Slides`: To see how the tracing looked like and what to expect from my code

## Implementation
Is the assignment complete? If not, mention what part of the assignment is missing or incomplete.
- `Assigment Completed`: Assignment has been fully completed, making sure that my program had everything mentioned in the assignment notes