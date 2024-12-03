#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int rear;
    int front;
    int size;
    int *a;
} cqueue;

cqueue* create(int size) {
    cqueue* cq1 = (cqueue*)malloc(sizeof(cqueue));
    if (cq1 == NULL) {
        printf("Memory not allocated\n");
        return NULL;
    }
    cq1->rear = -1;
    cq1->front = -1;
    cq1->size = size;
    cq1->a = (int*)malloc(size * sizeof(int));
    return cq1;
}

int isFull(cqueue* cq1) {
    return (cq1->size - 1 == cq1->front);
}

int isEmpty(cqueue* cq1) {
    return (cq1->rear == -1);
}

void enqueue(cqueue* cq1, int element) {
    if (isFull(cq1)) {
        printf("Queue is overflown\n");
        return;
    }
    if (cq1->front == -1 && cq1->rear == -1) {
        cq1->front++;
        cq1->rear++;
    } else {
        cq1->front = cq1->front + 1;
    }
    cq1->a[cq1->front] = element;
}

int dequeue(cqueue* cq1) {
    if (isEmpty(cq1)) {
        printf("Queue is underflown\n");
        return 0;
    }
    int ele = cq1->a[cq1->rear];
    if (cq1->rear == cq1->front) {
        cq1->rear = cq1->front = -1;
    } else {
        cq1->rear++;
    }
    return ele;
}
void BFS(int G[][7], int start, int n) {
    int visited[7] = {0};
    cqueue* cq1 = create(7);
    printf("%d ", start);
    visited[start] = 1;
    enqueue(cq1, start);

    while (!isEmpty(cq1)) {
        int i = dequeue(cq1);
        for (int j = 0; j < n; j++) {
            if (G[i][j] == 1 && visited[j] == 0) {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(cq1, j);
            }
        }
    }
}

void DFS(int G[][7], int start, int n) {
    static int visited[7] = {0}; 
    if (visited[start] == 0) {
        printf("%d ", start);
        visited[start] = 1;
        for (int j = 0; j < n; j++) {
            if (G[start][j] == 1 && visited[j] == 0) {
                DFS(G, j, n);
            }
        }
    }
}

int main() {
    int G[7][7] = {
        {0, 1, 0, 1, 1, 0, 0},  // 0 connected to 1, 3, 4
        {0, 0, 1, 0, 1, 0, 0},  // 1 connected to 2, 4
        {0, 0, 0, 0, 1, 0, 1},  // 2 connected to 4, 6
        {0, 1, 0, 0, 1, 0, 1},  // 3 connected to 1, 4, 6
        {0, 0, 1, 1, 0, 1, 0},  // 4 connected to 2, 3, 5
        {0, 0, 0, 0, 0, 0, 0},  // 5 has no outgoing edges
        {0, 0, 1, 0, 0, 1, 0}   // 6 connected to 2, 5
    };

    printf("BFS traversal: ");
    BFS(G, 0, 7);
    printf("\nDFS traversal: ");
    DFS(G, 0, 7);
    
    return 0;
}
