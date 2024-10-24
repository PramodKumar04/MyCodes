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
char pop(charArray *a1){
        if(isEmpty(a1)){
                printf("stack underflown\n");
                return '\0';
        }
        return a1->a[a1->top--];

}
void compare(charArray *a1, char element) {
    if (a1->top == -1) {
        push(a1, element);
    } else if (a1->a[a1->top] == '{' && element == '}') {
        pop(a1);
    } else if (a1->a[a1->top] == '[' && element == ']') {
        pop(a1);
    } else if (a1->a[a1->top] == '(' && element == ')') {
        pop(a1);
    } else if (a1->a[a1->top] == '"' && element == '"') {
        pop(a1);
    } else {
        push(a1, element);
    }
}
void reverse(char *b){
    int len=strlen(b);
    charArray *a1=create(len);
    int i=0;
    for(i=0;i<len;i++){
        push(a1,b[i]);
    }
     for (i = 0; i < len; i++) {
        b[i] =pop(a1);
    }
    b[i]='\0';
    for(i=0;i<len;i++){
        if(b[i]==' '){
            printf("\n");
        }
        else{
            printf("%c",b[i]);
        }
    }
    free(a1->a);
    free(b);

}

int main(){
        char b[100];
        printf("please enter your string: ");
        gets(b);
        reverse(b);
        return 0;
}