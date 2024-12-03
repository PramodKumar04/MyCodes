#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    struct Node *rchild,*lchild;
    int data,height;
}avl;
avl* root =NULL;
avl* node(int data){
    avl* temp=(avl*)malloc(sizeof(avl));
    temp->data=data;
    temp->height=1;
    temp->lchild=temp->rchild=NULL;
    return temp;
}
int nodeHeight(avl* p){
    int hl,hr;
    hl=p && p->lchild?p->lchild->height:0;
    hr=p && p->rchild?p->rchild->height:0;
    return hl>hr ? hl+1 :hr+1;

}
int balanceFactor(avl* p){
    int hl,hr;
    hl=p && p->lchild ? p->lchild->height:0;
    hr=p && p->rchild ? p->rchild->height:0;
    return hl-hr;
}
avl* LLRotation(avl* p){
    avl* pl=p->lchild;
    avl* plr=pl->rchild;
    pl->rchild=p;//assigning pl right child to p
    p->lchild=plr;//p left child will be plr
    p->height=nodeHeight(p);
    pl->height=nodeHeight(pl);
    if(root==p){
        root=pl;
    }
    return pl;
}
avl* RRRotation(avl* p){
    avl* pr=p->rchild;
    avl* prl=pr->lchild;
    pr->lchild=p;//assigning pr left child to p
    p->rchild=prl;//p left child will be plr
    p->height=nodeHeight(p);
    pr->height=nodeHeight(pr);
    if(root==p){
        root=pr;
    }
    return pr;
}
avl* LRRotation(avl* p){
    avl* pl=p->lchild;
    avl* plr=pl->rchild;
    pl->rchild =plr->lchild;
    p->lchild=plr->rchild;
    plr->lchild=pl;
    plr->rchild=p;
    p->height=nodeHeight(p);
    pl->height=nodeHeight(pl);
    plr->height=nodeHeight(plr);
    if(root==p){
        root=plr;
    }
    return plr;
}
avl* RLRotation(avl* p){
    avl* pr=p->rchild;
    avl* prl=pr->lchild;
    pr->lchild =prl->rchild;
    p->rchild=prl->lchild;
    prl->rchild=pr;
    prl->lchild=p;
    p->height=nodeHeight(p);
    pr->height=nodeHeight(pr);
    prl->height=nodeHeight(prl);
    if(root==p){
        root=prl;
    }
    return prl;
}
avl* Rinsert(avl* p,int data){
    if(p==NULL){
        return node(data);
    }
    if(data<p->data)
        p->lchild=Rinsert(p->lchild,data);
    else
        p->rchild=Rinsert(p->rchild,data);
    p->height=nodeHeight(p);
    if(balanceFactor(p)==2 && balanceFactor(p->lchild)==1)
        return LLRotation(p);
    if(balanceFactor(p)==-2 && balanceFactor(p->rchild)==-1)
        return RRRotation(p);
    if(balanceFactor(p)==2 && balanceFactor(p->lchild)==-1)
        return LRRotation(p);
    if(balanceFactor(p)==-2 && balanceFactor(p->rchild)==1)
        return RLRotation(p);
    return p;
}
void in_order(avl* root){
        avl* p=root;
        if(p){
                in_order(p->lchild);
                printf("%d ",p->data);
                in_order(p->rchild);
        }
}
void pre_order(avl* p){
        //avl* p=root;
        if(p){
                printf("%d ",p->data);
                pre_order(p->lchild);
                pre_order(p->rchild);
        }
}
int main() {
    root = Rinsert(root, 1);
    root = Rinsert(root, 2);
    root = Rinsert(root, 5);
    root = Rinsert(root, 6);
    root = Rinsert(root, 10);
    root = Rinsert(root, 0);
    root = Rinsert(root, 60);
    root = Rinsert(root, 40);
     root = Rinsert(root, 45);
    root = Rinsert(root, 50);


    printf("In-order traversal of the AVL tree: ");
    in_order(root);
    printf("\nPre-order traversal of the AVL tree: ");
    pre_order(root);
    printf("\n");

    return 0;
}
