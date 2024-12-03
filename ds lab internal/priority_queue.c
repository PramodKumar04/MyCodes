#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct{
        int items[MAX];
        int size;
}PriorityQueue;
void swap(int* a,int* b){
        int temp=*a;
        *a=*b;
        *b=temp;
}
void insert(PriorityQueue *pq,int index){
        int i=index,temp;
        temp=pq->items[i];
        while(i && pq->items[(i-1)/2]>temp){
                pq->items[i]=pq->items[(i-1)/2];
                i= (i-1)/2;
        }
        pq->items[i]=temp;
}
void enqueue(PriorityQueue *pq,int val){
        if(pq->size==MAX){
                printf("priority queue is full\n");
                return;
        }
        pq->items[pq->size++]=val;
        insert(pq,pq->size-1);
}
int heapify_delete(PriorityQueue *pq,int index){
        int smallest=index;
        int left=2*index+1;
        int right=2*index+2;
        if(left<pq->size && pq->items[left]<pq->items[smallest]){
                smallest=left;
        }
        if(right<pq->size && pq->items[right]<pq->items[smallest]){
                smallest=right;
        }
        if(smallest != index){
                swap(&pq->items[index], &pq->items[smallest]);
                heapify_delete(pq,smallest);
        }
}
int dequeue(PriorityQueue *pq){
        if(!pq->size){
                printf("priority queue is empty");
                return -1;
        }
        int item= pq->items[0];
        pq->items[0]=pq->items[--pq->size];
        heapify_delete(pq,0);
        return item;
}
int peek(PriorityQueue *pq){
        if(!pq->size){
                printf("priority queue is empty");
                return -1;
        }
        return pq->items[0];
}
void display(PriorityQueue *pq){
        for(int i=0;i<=pq->size;i++){
                printf("%d ",pq->items[i]);
        }
}
int main(){
        PriorityQueue pq;
        pq.size=0;
        enqueue(&pq,1);
        enqueue(&pq,14);
        enqueue(&pq,15);
        enqueue(&pq,5);
        enqueue(&pq,20);
        enqueue(&pq,30);
        enqueue(&pq,8);
        enqueue(&pq,40);
        printf("\n the elements in priority queue are: ");
        display(&pq);
        printf("\n the dequeued element is: %d",dequeue(&pq));
        printf("\n the new elements in priority queue are: ");
        display(&pq);
        printf("the peek element is: %d\n",peek(&pq));
        return 0;
}