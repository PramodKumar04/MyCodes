#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define I 32767
#define V 7
#define E 9
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

int isFull(cqueue *cq1) {
    return ((cq1->front + 1) % cq1->size == cq1->rear);
}

int isEmpty(cqueue *cq1) {
    return (cq1->rear == -1);
}

void enqueue(cqueue *cq1, int element) {
    if (isFull(cq1)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(cq1)) {
        cq1->rear = cq1->front = 0;
    } else {
        cq1->front = (cq1->front + 1) % cq1->size;
    }
    cq1->a[cq1->front] = element;
}

int dequeue(cqueue *cq1) {
    if (isEmpty(cq1)) {
        printf("Queue is empty\n");
        return -1;
    }
    int ele = cq1->a[cq1->rear];
    if (cq1->rear == cq1->front) {
        cq1->rear = cq1->front = -1;
    } else {
        cq1->rear = (cq1->rear + 1) % cq1->size;
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
void DFS(int G[][7], int start,int n){
        static int visited[7]={0};
        int j;
        if(visited[start]==0){
                printf("%d ",start);
                visited[start]=1;
                for(j=1;j<n;j++){
                        if(G[start][j]==1 && visited[j]==0){
                                DFS(G,j,n);
                        }
                }
        }
}
void printmcst(int t[][V-1]){
        printf("\n minimum cost spanning tree edges\n");
        int sum=0;
        for(int i=0;i<V-1;i++){
                int c=t[2][i];
                printf("\n [%d] --- [%d] cost=%d",t[0][i],t[1][i],c);
                sum=sum+c;
        }
        printf("\n the minimum cost spanning tree +%d\n",sum);
}
void union1(int u,int v,int s[]){
        if(s[u]<s[v]){
                s[u]+=s[v];
                s[v]=u;
        }
        else{
                s[v]+=s[u];
                s[u]=v;
        }
}
int find(int u,int s[]){
        int x=u;
        int v=0;
        while(s[x]>0){
                x=s[x];
        }
        return x;
}
void kruskalsmcst(int a[3][9]){
        int t[3][V-1];
        int visited[E]={0};
        int set[V+1]={-1,-1,-1,-1,-1,-1,-1,-1};
        int i=0;
        while(i<V-1){
                int min=I;
                int u=0,v=0,k=0;
                for(int j=0;j<E;j++){
                        if(visited[j]==0 && a[2][j]<min){
                                min=a[2][j];
                                u=a[0][j];
                                v=a[1][j];
                                k=j;
                        }
                }
                if(find(u,set)!=find(v,set)){
                        t[0][i]=u;
                        t[1][i]=v;
                        t[2][i]=min;
                        union1(find(u,set),find(v,set),set);
                        i++;
                }
                visited[k]=1;
        }
        printmcst(t);
}
void prims(int G[][7], int n) {
    int selected[7] = {0};
    int edge_count = 0;
    int min_cost = 0;
    selected[0] = 1;

    printf("\nEdges in MST (Prim's):\n");
    while (edge_count < n - 1) {
        int min = INT_MAX, x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && G[i][j]) {
                        if (min > G[i][j]) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        printf("Edge %d---%d with weight/cost %d\n", x, y, G[x][y]);
        min_cost += G[x][y];
        selected[y] = 1;
        edge_count++;
    }
    printf("Minimum cost: %d\n", min_cost);
}
int main(){
        int edge[3][9]={{1,1,2,2,3,4,4,5,5},
                        {2,6,3,7,4,5,7,6,7},
                        {25,5,12,10,8,16,14,20,18}};
        kruskalsmcst(edge);
        return 0;
}


/*int main() {
    int G[7][7] = {
        {0, 25, 0, 0, 0, 5, 0},
        {25, 0, 12, 0, 0, 0, 10},
        {0, 12, 0, 8, 0, 0, 0},
        {0, 0, 8, 0, 16, 0, 14},
        {0, 0, 0, 16, 0, 20, 0},
        {5, 0, 0, 0, 20, 0, 0},
        {0, 10, 0, 14, 18, 0, 0}
    };

    printf("BFS traversal: ");
    BFS(G, 0, 7);
    printf("\nDFS traversal: ");
    DFS(G, 0, 7);

    prims(G, 7);


    return 0;
}*/
