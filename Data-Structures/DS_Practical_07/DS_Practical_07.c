#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int adj[MAX][MAX];   // adjacency matrix
int visited[MAX];    // visited array for DFS/BFS
int queue[MAX];      // queue for BFS
int front = -1, rear = -1;
int n;               // number of vertices

// Enqueue for BFS
void enqueue(int v) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

// Dequeue for BFS
int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

// BFS traversal
void BFS(int start) {
    for (int i = 0; i < n; i++) visited[i] = 0;
    enqueue(start);
    visited[start] = 1;

    printf("BFS: ");
    while (front <= rear) {
        int v = dequeue();
        printf("%d ", v);
        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// DFS traversal
void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

// Outdegree of a node
int outdegree(int v) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1) count++;
    }
    return count;
}

// Find sink nodes
void findSinkNodes() {
    printf("Sink nodes: ");
    for (int i = 0; i < n; i++) {
        int flag = 1;
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == 1) {
                flag = 0;
                break;
            }
        }
        if (flag) printf("%d ", i);
    }
    printf("\n");
}

int main() {
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    // BFS
    BFS(start);

    // DFS
    for (int i = 0; i < n; i++) visited[i] = 0;
    printf("DFS: ");
    DFS(start);
    printf("\n");

    // Outdegree
    printf("Outdegree of node %d = %d\n", start, outdegree(start));

    // Sink nodes
    findSinkNodes();

    return 0;
}