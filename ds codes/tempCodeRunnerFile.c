#include <stdio.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int length;
} Array;

// Function to display the array
void display(Array *arr) {
    printf("Array elements: ");
    for (int i = 0; i < arr->length; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

// Function to append an element to the array
void append(Array *arr, int element) {
    if (arr->length < MAX_SIZE) {
        arr->data[arr->length] = element;
        arr->length++;
    } else {
        printf("Array is full, cannot append element.\n");
    }
}

// Function to get an element at a specific index
int getElement(Array *arr, int index) {
    if (index >= 0 && index < arr->length) {
        return arr->data[index];
    } else {
        printf("Invalid index.\n");
        return -1;  // Return a special value to indicate an error
    }
}

// Function to set an element at a specific index
void setElement(Array *arr, int index, int element) {
    if (index >= 0 && index < arr->length) {
        arr->data[index] = element;
    } else {
        printf("Invalid index.\n");
    }
}

// Function to left shift the array
void leftShift(Array *arr) {
    if (arr->length > 0) {
        for (int i = 1; i < arr->length; i++) {
            arr->data[i - 1] = arr->data[i];
        }
        arr->length--;
    } else {
        printf("Array is empty, cannot left shift.\n");
    }
}

int main() {
    Array arr = {{0}, 0};  // Initialize array with length 0

    // Append elements
    append(&arr, 10);
    append(&arr, 20);
    append(&arr, 30);
    append(&arr, 40);

    // Display the array
    display(&arr);

    // Get an element at index 2
    int element = getElement(&arr, 2);
    printf("Element at index 2: %d\n", element);

    // Set an element at index 1
    setElement(&arr, 1, 25);
    printf("After setting element at index 1 to 25:\n");
    display(&arr);

    // Left shift the array
    leftShift(&arr);
    printf("After left shifting the array:\n");
    display(&arr);

    return 0;
}
