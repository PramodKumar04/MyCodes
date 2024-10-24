#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
        int size;
        char *a;
        int top;
}charArray;
charArray* create(int size){
        charArray *a1=(charArray*)malloc(sizeof(charArray));
        a1->top=-1;
        a1->size=size;
        a1->a=(char *)malloc(a1->size*sizeof(char));
        return a1;
}
int isFull(charArray *a1){
        return a1->top==a1->size-1;
}
int isEmpty(charArray *a1){
        return a1->top==-1;
}
void push(charArray *a1,char element){
        if(isFull(a1)){
                printf("stack overflown\n");
                return;
        }
        a1->top++;
        a1->a[a1->top]=element;
}
void pop(charArray *a1){
        if(isEmpty(a1)){
                printf("stack underflown\n");
                return;
        }
        a1->top--;

}
void compare(charArray *a1,char element){
        if(a1->top==-1){
                push(a1,element);
        }
        else if(a1->a[a1->top]=='{'){
                if(element=='}'){
                        pop(a1);
                }
                else{
                        push(a1,element);
                }
        }
        else if(a1->a[a1->top]=='['){
                if(element==']'){
                        pop(a1);
                }
                else{
                        push(a1,element);
                }
        }
        else if(a1->a[a1->top]=='('){
                if(element==')'){
                        pop(a1);
                }
                else{
                        push(a1,element);
                }
        }
        else if(a1->a[a1->top]=='"'){
                if(element='"'){
                        pop(a1);
                }
                else{
                        push(a1,element);
                }
        }
       
        else{
                push(a1,element);
        }
}
void reverse(charArray *a1){
        char a[100]=strrev(a1->a);
        for(int i=0;a[i]!='\0';i++){
                if(a[i]==' '){
                        printf("\n");
                }
                else{
                        printf("%c",a[i]);
                }
        }
}
int main(){
        char a[100];
        printf("please enter your string: ");
        gets(a);
        int len=strlen(a);
        charArray *a1=create(len);
        for(int i=0;i<len;i++){
                if(a[i]==','){
                        continue;
                }
                compare(a1,a[i]);
        }
        reverse(a1);
        if(isEmpty(a1)){
                printf("true\n");
        }
        else{
                printf("false\n");
        }
        
        free(a1->a);
        free(a1);
        return 0;
}
