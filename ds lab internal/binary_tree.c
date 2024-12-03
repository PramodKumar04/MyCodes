#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
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
cqueue* createQ(cqueue *q){
    cqueue* cq1=(cqueue*)malloc(sizeof(cqueue));
    if(cq1==NULL){
        printf("memory not allocated");
        return NULL;
    }
    cq1->rear=cq1->front=-1;
    cq1->size=MAX_SIZE;
    cq1->a=(bt**)malloc(cq1->size*sizeof(bt*));
    return cq1;
}
int isFull(cqueue *cq1){
    return(cq1->size-1 == cq1->front );
}
int isEmpty(cqueue *cq1){
    return(cq1->rear==-1);
}
void enqueue(cqueue* cq1, bt* element){
    if (isFull(cq1)) {
        printf("Queue is overflown\n");
        return;
    }
    else if(cq1->front==-1 && cq1->rear==-1){
        cq1->front++;
        cq1->rear++;
    }
    else if (isEmpty(cq1)) {
        cq1->rear = cq1->front = 0;
    }
    else {
        cq1->front = cq1->front+1;
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
        cqueue *cq1=createQ(cq1);
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
void in_order(bt* root){
        bt* p=root;
        if(p){
                in_order(p->lchild);
                printf("%d ",p->value);
                in_order(p->rchild);
        }
}
void post_order(bt* root){
        bt* p=root;
        if(p){
                post_order(p->lchild);
                post_order(p->rchild);
                printf("%d ",p->value);
        }
}
void pre_order(bt* p){
        if(p){
                printf("%d ",p->value);
                pre_order(p->lchild);
                pre_order(p->rchild);
        }
}
void level_order(bt* root,int size){
        cqueue *cq1=createQ(cq1);
        bt* temp=root;
        if(root==NULL){
                printf("no binary tree found\n");
                return;
        }
        printf("%d ",temp->value);
        enqueue(cq1,temp);
        while(!isEmpty(cq1)){
                bt* p=dequeue(cq1);
                if(p->lchild){
                        printf("%d ",p->lchild->value);
                        enqueue(cq1,p->lchild);
                }
                if(p->rchild){
                        printf("%d ",p->rchild->value);
                        enqueue(cq1,p->rchild);
                }
        }
        free(cq1->a);
        free(cq1);
}
int sum(bt* root){
         bt* temp=root;
         if(temp==NULL){
                 return 0;
        }
        return temp->value+sum(temp->lchild)+sum(temp->rchild);
}
int height(bt* root){
        int x,y;
        bt* temp=root;
        if(temp){
                x=height(temp->lchild);
                y=height(temp->rchild);
                return x>=y?x+1:y+1;
        }
        return 0;
}
int count(bt* root){
        bt* temp=root;
        int x,y;
        if(temp){
                x=count(temp->lchild);
                y=count(temp->rchild);
                return x+y+1;
        }
        return 0;
}
int search(int key,bt* root){
        bt* temp=root;
        if(temp==NULL){
                return -1;
        }
        int found=search(key,temp->lchild);
        if(!found){
                found= search(key,temp->rchild);
        }
        return found;

}
int main(){
        int choice,x,key;
        bt* tree= (bt*)malloc(sizeof(bt));
        tree=create(MAX_SIZE);
        while(1){
                printf("\n1.in_order\n2.pre_order\n3.post_order\n4.count\n5.sum\n6.height\n7.level_order\n8.search\n0.end\n");
                printf("please enter your choice: ");
                scanf("%d",&choice);
                switch(choice){
                        case 1:in_order(tree);
                               break;
                        case 2:pre_order(tree);
                               break;
                        case 3:post_order(tree);
                               break;
                        case 4:x=count(tree);
                               printf("%d\n",x);
                               break;
                        case 5:x=sum(tree);
                               printf("sum of the node is %d\n",x);
                               break;
                        case 6:x=height(tree);
                               printf("height of tree %d\n",x);
                               break;
                        case 7:level_order(tree,count(tree));
                               break;
                        case 8:printf("enter the value to search: ");
                               scanf("%d",&key);
                               x=search(key,tree);
                               printf("value found: %d\n",x);
                               break;
                        case 0:printf("THANK YOU\n");
                               break;
                        default:printf("INVALID");
                }
                if(choice==0){
                        break;
                }
        }
        free(tree);
        return 0;
}
