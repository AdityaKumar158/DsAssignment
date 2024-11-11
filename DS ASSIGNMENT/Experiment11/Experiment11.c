#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Global variables
int adjMatrix[MAX][MAX]; // Adjacency Matrix
int visited[MAX];        // Visited array for DFS and BFS
int n;                   // Number of nodes in the graph

// Function prototypes
void createGraph();
void displayGraph();
void BFS(int startNode);
void DFS(int startNode);

int main() {
    int choice, startNode;

    while (1) {
        // Display the menu
        printf("\n--- Graph Operations Menu ---\n");
        printf("1. Create a Graph using Adjacency Matrix\n");
        printf("2. Perform BFS from a given starting node\n");
        printf("3. Perform DFS from a given starting node\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createGraph();
                displayGraph();
                break;
            case 2:
                printf("Enter starting node for BFS (0 to %d): ", n - 1);
                scanf("%d", &startNode);
                BFS(startNode);
                break;
            case 3:
                printf("Enter starting node for DFS (0 to %d): ", n - 1);
                scanf("%d", &startNode);
                // Reset visited array before each DFS
                for (int i = 0; i < n; i++) visited[i] = 0;
                printf("Nodes reachable using DFS: ");
                DFS(startNode);
                printf("\n");
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to create a graph using adjacency matrix
void createGraph() {
    int i, j;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }
}

// Function to display the adjacency matrix of the graph
void displayGraph() {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform Breadth-First Search (BFS)
void BFS(int startNode) {
    int queue[MAX], front = 0, rear = -1;
    int visited[MAX] = {0}; // Reset visited array

    printf("Nodes reachable using BFS: ");
    visited[startNode] = 1;
    queue[++rear] = startNode;

    while (front <= rear) {
        int currentNode = queue[front++]; // Dequeue
        printf("%d ", currentNode);

        // Check adjacent nodes
        for (int i = 0; i < n; i++) {
            if (adjMatrix[currentNode][i] == 1 && !visited[i]) {
                queue[++rear] = i; // Enqueue
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// Function to perform Depth-First Search (DFS)
void DFS(int startNode) {
    visited[startNode] = 1;
    printf("%d ", startNode);

    // Recursively visit all adjacent unvisited nodes
    for (int i = 0; i < n; i++) {
        if (adjMatrix[startNode][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}
