#include<stdio.h>
#include<stdlib.h>
struct Stack{
        int *s;
        int top;
        int size;
}s1;
typedef struct Stack stack;
void create(){
        printf("please enter the size: ");
        scanf("%d",&s1.size);
        s1.top=-1;
        s1.s=(int*)malloc(s1.size*sizeof(int));
}
void display(){
        if(s1.top==-1){
                printf("stack underflow\n");
        }
        else{
        for(int i=0;i<=s1.top;i++){
                printf("%d\n",s1.s[i]);
        }
        }


}
int isFull(){
        if(s1.top==(s1.size-1)){
                return 1;
        }

        else{
                return 0;
        }
}
int isEmpty(){
        if(s1.top==-1){
                return 1;
        }
        else{
                return 0;
        }
}
void push(int element){
        if(isFull()){
                printf("stack overflown\n");
        }
        else{
                s1.top++;
                s1.s[s1.top]=element;
        }
}
int pop(){
        if(isEmpty()){
                printf("stack underflow\n");
                return 0;
        }
        int n=s1.s[s1.top];
        s1.top--;
        return n;
}
int peek(){
        if(isEmpty()){
                printf("stack underflow\n");
                return 0;

        }
        int n =s1.s[s1.top];
        return n;
}
int main(){
        create();
        int a;
        int element,p,p1;
        while(1){
                 printf("1.push\n2.pop\n3.peek\n4.display\n5.isFull\n6.isEmpty\n0.end\n");
                 printf("please enter your choice: ");
                 scanf("%d",&a);
                switch(a){
                        case 1:scanf("%d",&element);
                               push(element);
                               display(s1);
                               break;
                        case 2:p=pop();
                               printf("the popped element: %d\n",p);
                               break;
                        case 3:p1=peek();
                               printf("the peeked element %d\n",p1);
                               break;
                        case 4:display();
                               break;
                        case 5: if(isFull()){
                                        printf("stack over flow\n");
                                }
                                else{
                                        printf("stack is not full\n");
                                }
                                break;
                        case 6:if(isEmpty()){
                                       printf("stack under flow\n");
                               }
                               else{
                                       printf("stack is having elements: \n");
                                       display(s1);
                                }
                               break;
                         default:printf("Thank You.\n");
                }
                if(a==0){
                        break;
                }
        }
        return 0;
}



