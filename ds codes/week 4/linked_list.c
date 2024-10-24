//1602-23-737-160
//menu driven program on linked list
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

    if (head == NULL) {
        head = l1;
    } else {
        node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = l1;
    }
    return l1;
}
void insertBegin(int data) {
    node* l1 = (node*)malloc(sizeof(node));
    if (l1 == NULL) {
        printf("Memory not allocated.\n");
        return;
    }
    l1->value = data;
    l1->next = head;
    head = l1;       
}
void insertEnd(int data) {
    node* l1 = (node*)malloc(sizeof(node));
    if (l1 == NULL) {
        printf("Memory not allocated.\n");
        return;
    }
    l1->value = data;
    l1->next = NULL;

    if (head == NULL) {
        head = l1;
        return;
    }

    node* last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = l1;
}
void insertAt(int pos, int data) {
    if (pos == 0) {
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
    for (int i = 0; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        free(l1);
        return;
    }

    l1->next = temp->next;
    temp->next = l1;
}
void insertNext(int pos,int data){
    node* l1=(node*)malloc(sizeof(node));
    l1->value=data;
    node* temp=head;
    for(int i=0;temp!=NULL && i<pos;i++){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("memory cannot be allocated");
        return;
    }
    l1->next=temp->next;
    temp->next=l1;
}
void deleteNode(int key) {
    node* temp = head;
    node* prev = NULL;

    if (temp != NULL && temp->value == key) {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->value != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) 
        return;

    prev->next = temp->next;
    free(temp);
}
void display() {
    node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("null\n");
}
void reverse(){
    node* prev=NULL;
    node* current=head;
    node* next=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
}
void sort() {
    if (head == NULL) {
        return;
    }

    int swapped;
    node* current;
    node* prev = NULL;

    do {
        swapped = 0;
        current= head;

        while (current->next != prev) {
            if (current->value > current->next->value) {
                int temp = current->value;
                current->value = current->next->value;
                current->next->value = temp;
                swapped = 1;
            }
            current = current->next;
        }
        prev = current;
    } while (swapped);
    display();
}
int main() {
    node* l1 = create();
    int choice,p,pos;
    while(1){
        printf("please enter your choice: \n");
        printf("1.insertBegin\n2.insetEnd\n3.insertAt\n4.deleteNode\n5.insertNext\n6.Sort\n7.reverse\n8.display\n0.end\n");
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
            case 4:printf("enter an element: ");
                   scanf("%d",&p);
                   deleteNode(p);
                   break;
            case 5:printf("enter an position and element: ");
                   scanf("%d %d",&pos,&p);
                   insertNext(pos,p);
                   break;
            case 6:sort();
                    break;
            case 7: reverse();
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
    return 0;
}
