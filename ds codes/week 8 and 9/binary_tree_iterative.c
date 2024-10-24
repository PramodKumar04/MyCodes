#include <stdio.h>
#include <stdlib.h>
typedef struct bt{
        int value;
        struct bt* lchild;
        struct bt* rchild;
}bt;
typedef struct{
        int front,rear;
        bt** a;
        int size;
}cqueue;
cqueue* createQ(cqueue *q,int size){
    cqueue* cq1=(cqueue*)malloc(sizeof(cqueue));
    if(cq1==NULL){
        printf("memory not allocated");
        return NULL;
    }
    cq1->rear=cq1->front=-1;
    cq1->size=size;
    cq1->a=(bt**)malloc(cq1->size*sizeof(bt*));
    return cq1;
}
int isFull(cqueue *cq1){
    return((cq1->front+1)%cq1->size==cq1->rear);
}
int isEmpty(cqueue *cq1){
    return(cq1->rear==-1);
}
void enqueue(cqueue *cq1, bt* element){
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

bt* dequeue(cqueue *cq1){
    if(isEmpty(cq1)){
        printf("queue is underflown\n");
        return 0;
    }
    bt* ele=cq1->a[cq1->rear];
    if(cq1->rear==cq1->front){
        cq1->rear=cq1->front=-1;
    }
    else if(cq1->rear==cq1->size-1){
        cq1->rear=0;
    }
    else{
        cq1->rear++;
   }
    return ele;

}
bt* create(int size){
        cqueue *cq1=createQ(cq1,size);
        bt* root= (bt*)malloc(sizeof(bt));
        printf("please enter the value of root: ");
        scanf("%d",&root->value);
        root->lchild=root->rchild=NULL;
        enqueue(cq1,root);
        while(!isEmpty(cq1)){
                bt* p=dequeue(cq1);
                int x;
                printf("please enter the value of left child of %d: ",p->value);
                scanf("%d",&x);
                if(x!=-1){
                        bt* t=(bt*)malloc(sizeof(bt));
                        t->value=x;
                        p->lchild=t;
                        enqueue(cq1,p->lchild);
                }
                printf("please enter the value of right child of %d: ",p->value);
                scanf("%d",&x);
                if(x!=-1){
                        bt* t=(bt*)malloc(sizeof(bt));
                        t->value=x;
                        p->rchild=t;
                        enqueue(cq1,p->rchild);
                }
        }
        free(cq1->a);
        free(cq1);
        return root;
}
typedef struct stack{
        bt **s;
        int top;
        int size;
}stack;

stack* createStack(int size){
        stack* s1=(stack*)malloc(sizeof(stack));
        s1->size=size;
        s1->top=-1;
        s1->s=(bt**)malloc(size*sizeof(bt*));
        return s1;
}
int isFullStack(stack *s1){
        if(s1->top==(s1->size-1)){
                return 1;
        }

        else{
                return 0;
        }
}
int isEmptyStack(stack* s1){
        if(s1->top==-1){
                return 1;
        }
        else{
                return 0;
        }
}
void push(stack* s1,bt* element){
        if(isFullStack(s1)){
                printf("stack overflown\n");
        }
        else{
                s1->top++;
                s1->s[s1->top]=element;
        }
}
bt*  pop(stack* s1){
        if(isEmptyStack(s1)){
                printf("stack underflow\n");
                return 0;
        }
        bt*  n=s1->s[s1->top];
        s1->top--;
        return n;
}
void deleteStack(stack* s1){
        free(s1->s);
        free(s1);
}
void pre_order(bt* root,int size){
        if(!root){
                return;
        }
        stack* s1=createStack(size);
        bt* p=root;
        while(1){
                while(p){
                        printf("%d ",p->value);
                        push(s1,p);
                        p=p->lchild;
                }
                if(isEmptyStack(s1))
                        break;
                p=pop(s1);
                p=p->rchild;
        }
        printf("\n");
        deleteStack(s1);
}
void in_order(bt* root,int size){
        if(!root){
                return;
        }
        stack* s1= createStack(size);
        bt* p=root;
        while(1){
                while(p){
                        push(s1,p);
                        p=p->lchild;
                }
                if(isEmptyStack(s1))
                        break;
                p=pop(s1);
                printf("%d ",p->value);
                p=p->rchild;
        }
        printf("\n");
        deleteStack(s1);
}
void post_order(bt* root,int size){
        if(!root){
                return;
        }
        stack* s1=createStack(size);
        bt* p=root;
        bt* prev =NULL;
        do{
                while(p!=NULL){
                        push(s1,p);
                        p=p->lchild;
                }
                while(p==NULL && !isEmptyStack(s1)){
                        p=pop(s1);
                        if(p->rchild==NULL || p->rchild==prev){
                                printf("%d ",p->value);
                                prev=p;
                                p=NULL;
                        }
                        else{
                                push(s1,p);
                                p=p->rchild;
                        }
                }
        }while(!isEmptyStack(s1));

        printf("\n");
        deleteStack(s1);
}
int main(){
        int size,choice,x,key;
        printf("please enter the size: ");
        scanf("%d",&size);
        bt* tree= (bt*)malloc(sizeof(bt));
        tree=create(size);
        while(1){
                printf("\n1.in_order\n2.pre_order\n3.post_order\n0.end\n");
                printf("please enter your choice: ");
                scanf("%d",&choice);
                switch(choice){
                        case 1:in_order(tree,size);
                               break;
                        case 2:pre_order(tree,size);
                               break;
                        case 3:post_order(tree,size);
                               break;
                        case 0: printf("THANK YOU\n");
                               break;
                        default:printf("INVALID");
                }
                if(choice==0){
                        break;
                }
        }
        free(tree);
