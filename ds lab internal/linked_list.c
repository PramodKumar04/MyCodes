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
void even_number() {
    int swapped;
    do {
        swapped = 0;
        node *prev = NULL;
        node *curr = head;
        
        while (curr != NULL && curr->next != NULL) {
            // Check if the current node's value is odd and the next node's value is even
            if (curr->value % 2 != 0 && curr->next->value % 2 == 0) {
                node *next = curr->next;
                
                // Swap nodes
                curr->next = next->next;
                next->next = curr;
                
                if (prev == NULL) {
                    // Update head if swapping the first two nodes
                    head = next;
                } else {
                    // Update the previous node's next pointer
                    prev->next = next;
                }
                
                // Mark that a swap has occurred
                swapped = 1;
                
                // Move to the next pair
                prev = curr;
                curr = curr->next;
            } else {
                // Move to the next node
                prev = curr;
                curr = curr->next;
            }
        }
    } while (swapped); // Continue until no swaps are made
    
    display();
}



int main() {
    node* l1 = create();
    int choice,p,pos;
    while(1){
        printf("please enter your choice: \n");
        printf("1.insertBegin\n2.insetEnd\n3.insertAt\n4.deleteNode\n5.insertNext\n6.even\n7.display\n0.end\n");
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
            case 5:printf("enter an position and element: ");
                   scanf("%d %d",&pos,&p);
                   insertNext(pos,p);
                   break;
            case 6:even_number();
                   break;
        
            case 7 :display();
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
