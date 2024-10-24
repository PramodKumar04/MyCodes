#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int value;
    struct node *next,*prev;
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
    l1->prev=NULL;
    head=l1;
    return l1;
}
void insertBegin(int data) {
    node* l1 = (node*)malloc(sizeof(node));
    if (l1 == NULL) {
        printf("Memory not allocated.\n");
        return;
    }
    l1->value=data;
    if(head==NULL){
            l1->prev=NULL;
            l1->next=NULL;
            head=l1;
            return;
    }
    l1->next=head;
    head->prev=l1;
    head=l1;
    l1->prev=NULL;
   printf("\n %d has been inserted at begin\n",data);
}
void insertEnd(int data) {
    node* l1 = (node*)malloc(sizeof(node));
    if (l1 == NULL) {
        printf("Memory not allocated.\n");
        return;
    }
    l1->prev=NULL;
    l1->value = data;
    l1->next = NULL;

    if (head == NULL) {
        head = l1;
        l1->prev=l1->next=NULL;
        return;
    }

    node* last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = l1;
    l1->prev=last;
    l1->next=NULL;
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
    node* temp1;
    for (int i = 1;i < pos-1; i++) {
        if(temp==NULL){
                printf("position out of boujnds\n");
                free(temp);
                return;
        }
        temp1=temp;
        temp = temp->next;
    }
    temp1->next=l1;
    l1->prev=temp1;
    l1->next=temp;
    temp->prev=l1;
    /*
    l1->next= temp->next;
    l1->prev=temp;
    if(temp->next!=NULL){
            temp->next->prev=l1;
    }
    temp->next=l1;*/

}
void delete_Begin(){
        if(head==NULL){
                printf("list is empty\n");
                return;
        }
        printf("the beginning node is deleted: %d\n",head->value);
        head=head->next;
        head->prev=NULL;
}
void delete_last(){
        if(!head){
                printf("list is empty\n");
                return;
        }
        node* last =head;
        while(last->next->next!=NULL){
                last=last->next;
        }
        printf("the deleted element is %d\n",last->next->value);
        last->next->prev=NULL;
        last->next=NULL;
}
void delete_at(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (pos == 1) {
        delete_Begin();
        return;
    }

    node* current = head;
    for (int i = 1; i < pos && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    if (current->next == NULL) {
        if (current->prev != NULL) {
            current->prev->next = NULL;
        }
    }

    printf("Deleted node with value: %d\n", current->value);
    free(current);
}
void display() {
    node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("%d <=> ", temp->value);
        temp = temp->next;
    }
    printf("null\n");
}
void display_rev(){
        node* temp=head;
        if(!temp){
                printf("list is empty.\n");
                return;
        }
        while(temp->next!=NULL){
                temp=temp->next;
        }
        while(temp!=NULL){
                printf("%d <=> ", temp->value);
                temp=temp->prev;
        }
        printf("null\n");
}
int main() {
    node* l1 = create();
    int choice,p,pos;
    while(1){
        printf("please enter your choice: \n");
        printf("1.insertBegin\n2.insetEnd\n3.insertAt\n4.delete_Begin\n5.delete_last\n6.delete_at\n7.display_rev\n8.display\n0.end\n");
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
            case 4: delete_Begin();
                   break;
            case 5:delete_last();
                   break;
            case 6:printf("enter the position: ");
                   scanf("%d",&pos);
                   delete_at(pos);
                   break;
            case 7:display_rev();
                   break;
            case 8: display();
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

