#include <stdio.h>
#include <stdlib.h>
typedef struct node{
        int data;
        struct node *lchild,*rchild;
}bst;
bst* root=NULL;
bst* newNode(int data){
        bst* temp=(bst*)malloc(sizeof(bst));
        temp->data=data;
        temp->lchild=temp->rchild=NULL;
        return temp;
}
void insert(int key){
        bst* t=root;
        bst *r,*p;
        if(!root){
                root=newNode(key);
                return;
        }
        while(t){
                r=t;
                if(key<t->data)
                        t=t->lchild;
                else if(key>t->data)
                        t=t->rchild;
                else//if t->data == key since no duplicate elements in bst
                        return;
        }
        p=newNode(key);
        if(key<r->data)
                r->lchild=p;
        else
                r->rchild=p;
}
void in_order(bst* root){
        bst* p=root;
        if(p){
                in_order(p->lchild);
                printf("%d ",p->data);
                in_order(p->rchild);
        }
}
bst* search(int key){
        bst* t=root;
        while(t){
                if(key==t->data){
                        return t;
                }
                else if(key<t->data){
                        t=t->lchild;
                }
                else if(key>t->data){
                        t=t->rchild;
                }
        }
        return NULL;
}
void minKey(bst* root){
        bst* t=root;
        if(!t){
                return;
        }
        while(t!=NULL && t->lchild!=NULL)
                t=t->lchild;
        printf("%d\n",t->data);
}
void maxKey(bst* root){
        bst* t=root;
        if(!t){
                return ;
        }
        while(t!=NULL && t->rchild!=NULL)
                t=t->rchild;
        printf("%d\n",t->data);
}

int main(){
        int a[7];
        printf("please enter the elements to be inserted: ");
        for(int i=0;i<7;i++){
                scanf("%d",&a[i]);
                insert(a[i]);
        }
        printf("\n Inorder Traversal\n");
        in_order(root);
        bst* res=search(60);
        if(res==NULL)
                printf("not found");
        else
                printf("element is found %d\n",res->data);
        maxKey(root);
        minKey(root);
        return 0;
}
