#include <stdio.h>
#include<string.h>
struct string{
    char s[100];
    int length;
};
void display(struct string *ptr){
    for(int i=0;i<ptr->length;i++){
        printf("%c",ptr->s[i]);
    }
    printf("\n");
}
void append(struct string *ptr,char b){
    if(ptr->length<99){
        ptr->s[ptr->length]=b;
        ptr->length++;
        ptr->s[ptr->length] = '\0';
    }
    else{
        printf("array is full");
    }

}
char getElement(struct string *ptr,int index){
    return ptr->s[index];
}
void setElement(struct string *ptr,int index,char b){
    ptr->s[index]=b;
}
void leftShift(struct string *ptr){
    if(ptr->length>0){
        for(int i=0;i<ptr->length;i++){
           ptr->s[i-1]=ptr->s[i];
        }
        ptr->length--;
        
    }
    else{
        printf("array is empty.");
    }
}
int main(){
    struct string ptr;
    printf("please enter a string: ");
    gets(ptr.s);
    ptr.length=strlen(ptr.s);
    append(&ptr,'p');
    display(&ptr);
    char r=getElement(&ptr,3);
    printf("%c\n",r);
    setElement(&ptr,3,'k');
    display(&ptr);
    printf("the string after left string: \n");
    leftShift(&ptr);
    display(&ptr);

    return 0;
}