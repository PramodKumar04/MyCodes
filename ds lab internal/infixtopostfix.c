#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *a;
    int top;
    int maxSize;
} charArray;

charArray* create(int size) {
    charArray *arr = (charArray*)malloc(sizeof(charArray));
    arr->a = (char*)malloc(size * sizeof(char));
    arr->top = -1;
    arr->maxSize = size;
    return arr;
}

void push(charArray *arr, char element) {
    if (arr->top < arr->maxSize - 1) {
        arr->a[++arr->top] = element;
    } else {
        printf("Stack overflow\n");
    }
}

char pop(charArray *arr) {
    if (arr->top >= 0) {
        return arr->a[arr->top--];
    } else {
        printf("Stack underflow\n");
        return '\0';
    }
}
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    } else {
        return 0;
    }
}
char peek(charArray *a1){
    if (a1->top >= 0) {
        return a1->a[a1->top];
    } else {
        return '\0';
    }
}
void compare(char *b) {
    int len = strlen(b);
    char *b1 = (char*)malloc((len + 1) * sizeof(char)); // Allocate memory for the result string including null terminator
    int k = 0;
    charArray *a1 = create(len);

    for (int i = 0; i < len; i++) {
        if (a1->top == -1 && !isalpha(b[i])) {
            push(a1, b[i]);
        }
        else if (isalpha(b[i])) {
            b1[k] = b[i];
            k++;
        }
        else if (b[i] == '[' || b[i] == '{' || b[i] == '(') {
            push(a1, b[i]);
        }
        else if (b[i] == ']' || b[i] == ')' || b[i] == '}') {
            char brac;
            if (b[i] == ']') {
                brac = '[';
            } else if (b[i] == ')') {
                brac = '(';
            } else {
                brac = '{';
            }
            while (a1->top != -1 && a1->a[a1->top] != brac) {
                b1[k] = pop(a1);
                k++;
            }
            pop(a1);
        }
        else{
            while(a1->top!=-1 && precedence(peek(a1))>=precedence(b[i])){
                b1[k++]=pop(a1);
            }
            push(a1,b[i]);
        }
    }
    while (a1->top != -1) {
        b1[k++] = pop(a1);
    }
    b1[k] = '\0'; 
    printf("Result: %s\n", b1);
    free(b1);
    free(a1->a);
    free(a1);
}

int main() {
    char b[100];
    printf("please enter your string: ");
    gets(b);
    compare(b);
    return 0;
}
