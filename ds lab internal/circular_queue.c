//1602-23-737-160
//menu driven program on circular queue

#include<stdio.h>
#include<stdlib.h>
typedef struct{
        int f,r,size;
        int *a;
}Queue;

Queue * createQueue(int size)
{
        Queue *q=(Queue*)malloc(sizeof(Queue));
        q->f=q->r=-1;
        q->size=size;
        q->a=(int*)malloc(q->size*sizeof(int));
}
int isFull(Queue *q)
{
        if (q->r-q->f==1)
        {return 1;
        }
        if (q->f==q->size-1&& q->r==0)
        {
                return 1;}
        return 0;
}

void enqueue(int element,Queue *q)
{
        if(isFull(q)){
                printf("queue full");
                return;
        }
        if (q->f==-1)
        {
                q->r++;
        }
         if(q->f==q->size-1)
        {
                q->f=0;
        }
        else{q->f++;}

        q->a[q->f]=element;

}
int dequeue(Queue*q)
{
        if(q->f==-1){
                printf("empty\n");
                return NULL;
        }
        int b=q->a[q->r];

        if(q->f==q->r)
        {
                q->f=q->r=-1;
        }
        else if(q->r==q->size-1)
        {
                q->r=0;
        }
        else{q->r++;}

       return b;
}
void display(Queue *q)
{        if(q->f==-1){
                printf("empty\n");
                }
        if (q->f>q->r)
        {
        for (int i=q->r;i<=q->f;i++)
        {
                printf("%d ",q->a[i]);
        }
        }
        else
        {for (int i=q->r;i<=q->size-1;i++)
                {
                        printf("%d ",q->a[i]);
                }
                for (int i=0;i<=q->f;i++)
                {
                        printf("%d ",q->a[i]);
                }
        }

}
int front(Queue *q)
{
         if(q->f==-1){
                printf("empty\n");
                return NULL;

        }
         return q->a[q->f];
}
int rear(Queue *q)
{
         if(q->f==-1){
                printf("empty\n");
                return NULL;

        }
         return q->a[q->r];
}

int main()
{
        int size;
        printf("enter size");
        scanf("%d",&size);
        Queue *q=createQueue(size);

        int element,c,r=1;
        while(r)
        {
            printf("Menu\n1.enqueue\n2.dequeue\n3.display\n4.front\n5.rear\n6.exit\nEnter Choice:");
            scanf("%d",&c);
            switch (c)
            {
                case 1:
                        scanf("%d",&element);
                        enqueue(element,q);
                        break;
                case 2:
                        if (q->f==-1)
                        {printf("empty");}
                        else{

                        printf("%d",dequeue(q));
                                        }

                        break;
                case 3:
                        display(q);
                        break;
                case 4:
                        printf("%d",front(q));
                        break;
                case 5:

                        printf("%d",rear(q));
                        break;
                case 6:
                        r=0;
                        break;
                default:
                        printf("wrong Choice");

            }
        }   
}

