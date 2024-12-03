#include <stdio.h>

void insert(int a[], int n) {
    int i = n, temp;
    temp = a[i];
    while (i > 1 && temp > a[i / 2]) {
        a[i] = a[i / 2];
        i = i / 2;
    }
    a[i] = temp;
}

void deleteMax(int a[], int n) {
    int i, j, temp;
    int val = a[1]; // Root (max element)
    a[1] = a[n];    // Replace root with the last element
    a[n] = val;     // Move max to the end
    i = 1;
    j = 2 * i;

    while (j <= n - 1) {
        if (j < n - 1 && a[j + 1] > a[j]) {
            j = j + 1; // Point to the larger child
        }
        if (a[i] < a[j]) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i = j;
            j = 2 * j;
        } else {
            break;
        }
    }
}

int main() {
    int h[8] = {0, 14, 15, 5, 20, 30, 8, 40}; // 1-based indexing
    int n = 7; // Number of elements in the heap
    int i;

    // Build max heap
    for (i = 2; i <= n; i++) {
        insert(h, i);
    }

    printf("Max heap after insertion: ");
    for (i = 1; i <= n; i++) {
        printf("%d ", h[i]);
    }

    // Perform heap sort
    for (i = n; i > 1; i--) {
        deleteMax(h, i);
    }

    printf("\nArray after heap sort: ");
    for (i = 1; i <= n; i++) {
        printf("%d ", h[i]);
    }

    return 0;
}
