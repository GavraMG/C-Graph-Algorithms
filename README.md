# 🌐 Graph Traversal and Shortest Path Algorithms - C Programming Project

<p align="center">
  <img width="700" alt="ePortfolio Management Screenshot" src="https://github.com/user-attachments/assets/6c2e0e91-1b90-4f06-8445-a959a8fa3911">
</p>

## 📖 Table of Contents

- [About My Project](#-about-my-project)
  - [Features](#-features)
  - [Tech Used](#-tech-used)
  - [How to Run](#-how-to-run)
  - [How It Works](#-how-it-works)
- [Contact](#-contact)

<br/>

## About My Project
The Graph Traversal and Shortest Path Algorithms project is a C-based application that reads a graph from a file and allows users to interact with it via a set of graph operations. Designed as part of my CIS2520 coursework, this project provides an in-depth exploration of graph theory, focusing on representations such as adjacency matrices and lists, and implementing classic graph traversal algorithms like Breadth-First Search (BFS), Depth-First Search (DFS), and Dijkstra's Algorithm.

The project also emphasizes efficient memory management and robust error handling, showcasing proficiency in C programming, data structures, and algorithms.

<br/>

## 🚀 Features

- **Display Adjacency List:** Converts the adjacency matrix into an adjacency list and displays it.
- **Breadth-First Search (BFS):** Traverse the graph layer by layer starting from vertex 1.
- **Depth-First Search (DFS):** Explore the graph in depth-first order starting from vertex 1.
- **Dijkstra's Algorithm:** Calculate the shortest path from vertex 1 to all other vertices.
- **Menu-Driven Interface:** A command-line interface that allows users to choose different graph operations easily.
- **Robust Error Handling:** Ensures proper messages for invalid inputs, missing files, and other errors.
- **Memory Management:** Dynamically allocated data structures are managed to ensure no memory leaks, confirmed by tools like Valgrind.

<br/>

## 💻 Tech Used

This program uses:

- **C Language:** The core programming language used to implement graph traversal and shortest path algorithms.
- **Data Structures:** Implemented linked lists for adjacency lists, stacks for DFS, and queues for BFS.
- **File I/O:** Read graph data from a text file to build an adjacency matrix and graph structure.
- **Makefile:** Automate compilation with a makefile to ensure smooth building of the executable.

<br/>

## 🛠️ How to Run

1. **Build the Program**
    - Make sure you have `make` installed.
    - Navigate to the directory containing the project files and compile using:
      ```sh
      make
      ```
    - This command will compile all necessary files into an executable.

2. **Run the Program**
    - To start the application, run the following command:
      ```sh
      ./MATRIX example-graph.txt
      ```
    - Replace `example-graph.txt` with the path to your own graph file if needed.
    - Replace `example-graph.txt` with the path to your own graph file if needed.

3. **Clean the Program**
    - To remove the compiled executable and object files, run:
      ```sh
      make clean
      ```

<br/>

## 📝 How It Works

The Graph Traversal and Shortest Path Algorithms project is controlled through a command-line menu that provides the following options:

- **1. Display Adjacency List:** Converts the adjacency matrix to an adjacency list and displays it for all vertices. This helps visualize the connections between nodes more easily.
- **2. Breadth-First Search (BFS):** Allows the user to traverse the graph starting from vertex 1, exploring all neighbors level by level before moving deeper.
- **3. Depth-First Search (DFS):** Enables depth-first traversal of the graph from vertex 1, going deep into each branch before backtracking to explore other branches.
- **4. Dijkstra's Algorithm:** Computes and displays the shortest path from vertex 1 to all other vertices, highlighting the minimum cost paths in the graph.
- **5. Exit:** Quits the program, freeing all allocated memory to prevent leaks.

Each of these features provides a unique perspective or operation on the graph, making the system versatile for various graph theory analyses.

After performing an operation, the program returns to the main menu until the user chooses to exit. This iterative interaction is designed to make the program easy to navigate, while ensuring all allocated memory is properly managed before quitting.

<br/>

## ✉️ Contact

Got any questions? Feel free to reach out!

- [Email](mailto:markusgavra@gmail.com)
- [LinkedIn](https://www.linkedin.com/in/markus-gavra)

