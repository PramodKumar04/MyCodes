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
int height(bst* root){
        int x,y;
        bst* temp=root;
        if(temp){
                x=height(temp->lchild);
                y=height(temp->rchild);
                return x>=y?x+1:y+1;
        }
        return 0;
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
bst* minKey(bst* root){
        bst* t=root;
        if(!t){
                return NULL;
        }
        while(t!=NULL && t->lchild!=NULL)
                t=t->lchild;
        return t;
}
bst* maxKey(bst* root){
        bst* t=root;
        if(!t){
                return NULL ;
        }
        while(t!=NULL && t->rchild!=NULL)
                t=t->rchild;
        return t;
}
bst* inpre(bst* root)
{
        bst* p=root;
        if(root->lchild!=NULL)
                return maxKey(root->lchild);
}
bst* insucc(bst* root) {
        bst* p=root;
        if(root->rchild=NULL)
                return minKey(root->rchild);
}
bst* delete(bst* p,int key){
        bst* q;
        if(root==NULL)
                return NULL;
        if(p->data==key && p->lchild==NULL && p->rchild==NULL){
                if(p==root)
                        root=NULL;
                free(p);
                return NULL;
        }
        if(key<p->data){
                p->lchild=delete(p->lchild,key);
        }
        else if(key>p->data){
                p->rchild=delete(p->rchild,key);
        }
        else{
                if(height(p->lchild)>height(p->rchild)){
                        printf("root=%d\n",root->data);
                        q=inpre(p);
                        p->data=q->data;
                        p->lchild=delete(p->lchild,q->data);
                }
                else{
                        printf("root=%d\n",root->data);
                        q=insucc(p);
                        p->data=q->data;
                        p->lchild=delete(p->rchild,q->data);
                }
        }
        return p;
}
int main() {
    int choice, key;
    bst* res;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. In-order Traversal\n");
        printf("4. Search\n");
        printf("5. Find Minimum Key\n");
        printf("6. Find Maximum Key\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter element to delete: ");
                scanf("%d", &key);
                bst* del = delete(root, key);
                if(del==NULL){
                    printf("element not found\n");
                }
                else{
                    printf("element found: %d\n");
                }
                break;
            case 3:
                printf("In-order Traversal: ");
                in_order(root);
                printf("\n");
                break;
            case 4:
                printf("Enter element to search: ");
                scanf("%d", &key);
                res = search(key);
                if (res == NULL)
                    printf("Element not found\n");
                else
                    printf("Element found: %d\n", res->data);
                break;
            case 5:
                res = minKey(root);
                if (res == NULL)
                    printf("bst is empty\n");
                else
                    printf("Minimum key: %d\n", res->data);
                break;
            case 6:
                res = maxKey(root);
                if (res == NULL)
                    printf("bst is empty\n");
                else
                    printf("Maximum key: %d\n", res->data);
                break;
            case 7:
                printf("THANK YOU!\n");
                exit(0);
            default:
                printf("Invalid\n");
        }
    }
    return 0;
}