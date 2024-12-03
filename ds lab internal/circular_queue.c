//1602-23-737-160
//menu driven program on circular queue
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int rear;
    int front;
    int size;
    int *a;
}cqueue;
cqueue* create(){
    cqueue*cq1=(cqueue*)malloc(sizeof(cqueue));
    if(cq1==NULL){
        printf("memory not allocated");
        return NULL;
    }
    cq1->rear=-1;
    cq1->front=-1;
    printf("please enter the size: ");
    scanf("%d",&cq1->size);
    cq1->a=(int*)malloc(cq1->size*sizeof(int));
    return cq1;
}
int isFull(cqueue *cq1){
    return((cq1->front+1)%cq1->size==cq1->rear);
}
int isEmpty(cqueue *cq1){
    return(cq1->rear==-1);
}
void enqueue(cqueue *cq1, int element){
    if (isFull(cq1)) {
        printf("Queue is overflown\n");
        return;
    }
    if (isEmpty(cq1)) {
        cq1->rear = cq1->front = 0;
    } 
    else {
        cq1->front = (cq1->front + 1) % cq1->size;
    }
    cq1->a[cq1->front] = element;
}

void dequeue(cqueue *cq1){
    if(isEmpty(cq1)){
        printf("buffer is empty no data to burn\n");
        return;
    }
    int burn_data=cq1->a[cq1->rear];
    if(cq1->rear==cq1->front){
        cq1->rear=cq1->front=-1;
    }
    else if(cq1->rear==cq1->size-1){
        cq1->rear=0;
    }
    else{
        cq1->rear++;
    }
    printf("the dequed element: %d\n",burn_data);
}
void peek(cqueue* cq1){
    if(isEmpty(cq1)){
        printf("QUEUE IS UNDERFLOWN\n");
        return;
    }
    printf("the peeked element at rear: %d\n",cq1->a[cq1->rear]);
    printf("the peeked element at front: %d\n",cq1->a[cq1->front]);
}
void display(cqueue*cq1){
    if(isEmpty(cq1)){
        printf("queue is underflown\n");
        return;
    }
    printf("the elements are: ");
    int i=cq1->rear;
    while(1){
        printf("%d ",cq1->a[i]);
        if(i==cq1->front){
            break;
        }
        i=(i+1)%cq1->size;
    }
    printf("\n");
}
int main(){
        cqueue* cq1 = create();
    int choice,p,pos;
    while(1){
        printf("please enter your choice: \n");
        printf("1.insert data\n2.burn data\n3.peek\n4.display\n0.end\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("enter an element: ");
                   scanf("%d",&p);
                   enqueue(cq1,p);
                   break;
            case 2:dequeue(cq1);
                   break;
            case 3:peek(cq1);
                   break;
            case 5:display(cq1);
                   break;
            case 0: printf("THANK YOU");
                    break;
            default:printf("INVALID");
            
        }
        if(choice==0){
            break;
        }
    }
    free(cq1->a);
    free(cq1);
    return 0;
}
