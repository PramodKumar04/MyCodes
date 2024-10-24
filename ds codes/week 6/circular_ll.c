#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int value;
    struct node *next;
} node;
node *head = NULL;
node* create() {
    node* l1 = (node*)malloc(sizeof(node));
    if (l1 == NULL) {
        printf("Memory not allocated.\n");
        return NULL;
    }
    printf("Please enter the value: ");
    scanf("%d", &l1->value);
    l1->next = NULL;
    return l1;
}
void insertBegin(int data) {
    node* l1 = (node*)malloc(sizeof(node));
    if (l1 == NULL) {
        printf("Memory not allocated.\n");
        return;
    }
    if(head==NULL){
            head=l1;
            l1->next=head;
            return;
    }
    node* last =head;
    l1->value = data;
    l1->next = head;
    while(last->next!=head){
            last=last->next;
    }
    l1->next=head;
    last->next=l1;
    head = l1;
}
void insertEnd(int data) {
    node* l1 = (node*)malloc(sizeof(node));
    if (l1 == NULL) {
        printf("Memory not allocated.\n");
        return;
    }
    l1->value = data;

    if (head == NULL) {
        insertBegin(data);
        return;
    }

    node* last = head;
    while(last->next!=head){
            last=last->next;
    }
    last->next = l1;
    l1->next=head;
}
void insertAt(int pos, int data) {
    if (pos == 1) {
        insertBegin(data);
        return;
    }

    node* l1 = (node*)malloc(sizeof(node));
    if (l1 == NULL) {
        printf("Memory not allocated.\n");
        return;
    }
    l1->value = data;

    node* temp = head;
    for (int i = 0;i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == head || temp==NULL) {
        printf("Position out of bounds.\n");
        free(l1);
        return;
    }

    l1->next = temp->next;
    temp->next = l1;
}
void delete_begin(){
        if(head==NULL){
                printf("list is empty\n");
                return;
        }
        node*last=head;
        while(last->next!=head){
                last=last->next;
        }
        printf("the element deleted is %d\n",last->value);
        head=head->next;
        last->next=head;
}
void delete_end(){
        if(head==NULL){
                printf("list is empty\n");
                return;
        }
        node*last=head;
        node* last1;
        while(last->next!=head){
                last1=last;
                last=last->next;
        }
        printf("the element deleted is %d\n",last->value);
        last1->next=head;
}
void delete_at(int pos){
        if(head==NULL){
                printf("list is empty\n");
                return;
        }
        if(pos==1){
                delete_begin();
                return;
        }
        node*last=head;
        node* last1;
        for(int i=1;i<pos;i++){
                last1=last;
                last=last->next;
        }
        if(last==head){
                printf("position out of bounds\n");
                return;
        }
        printf("element is deleted %d\n",last->value);
        last1->next=last->next;
        free(last);
}
void display() {
    node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    do{
            printf("%d-> ",temp->value);
            temp=temp->next;
    }while(temp!=head);
    printf("end\n");
}
int main() {
    node* l1 = create();
    int choice,p,pos;
    while(1){
        printf("please enter your choice: \n");
        printf("1.insertBegin\n2.insetEnd\n3.insertAt\n4.delete_begin\n5.delete_end\n6.delete_at\n7.display\n0.end\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("enter an element: ");
                   scanf("%d",&p);
                   insertBegin(p);
                   break;
            case 2:printf("enter an element: ");
                   scanf("%d",&p);
                   insertEnd(p);
                   break;
            case 3:printf("enter an position and element: ");
                   scanf("%d %d",&p,&pos);
                   insertAt(pos,p);
                   break;
            case 4:delete_begin();
                   break;
            case 5:delete_end();
                   break;
            case 6:printf("enter an position: ");
                   scanf("%d",&pos);
                   delete_at(pos);

            case 7: display();
                    break;
            case 0: printf("THANK YOU");
                    break;
            default:printf("INVALID");

        }
        if(choice==0){
            break;
        }
    }
    free(l1);
    return 0;
}


~
~
~
~

