#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Binary Tree structure
typedef struct {
    int tree[MAX_SIZE];
    int size;
} BinaryTree;

// Function to get left child index
int leftChild(int i) {
    return 2 * i + 1;
}

// Function to get right child index
int rightChild(int i) {
    return 2 * i + 2;
}

// Function to get parent index
int parent(int i) {
    return (i - 1) / 2;
}

// Function to create a binary tree (initialize with size 0)
void create(BinaryTree* bt) {
    bt->size = 0;
}

// Function to insert a node into the binary tree
void insert(BinaryTree* bt, int value) {
    if (bt->size >= MAX_SIZE) {
        printf("Binary tree is full.\n");
        return;
    }
    bt->tree[bt->size] = value;
    bt->size++;
}

// Preorder Traversal (Root, Left, Right)
void preorder(BinaryTree* bt, int index) {
    if (index >= bt->size) return;  // Base case for recursion
    printf("%d ", bt->tree[index]);  // Visit the current node
    preorder(bt, leftChild(index));  // Traverse left subtree
    preorder(bt, rightChild(index));  // Traverse right subtree
}

// Inorder Traversal (Left, Root, Right)
void inorder(BinaryTree* bt, int index) {
    if (index >= bt->size) return;
    inorder(bt, leftChild(index));  // Traverse left subtree
    printf("%d ", bt->tree[index]);  // Visit the current node
    inorder(bt, rightChild(index));  // Traverse right subtree
}

// Postorder Traversal (Left, Right, Root)
void postorder(BinaryTree* bt, int index) {
    if (index >= bt->size) return;
    postorder(bt, leftChild(index));  // Traverse left subtree
    postorder(bt, rightChild(index));  // Traverse right subtree
    printf("%d ", bt->tree[index]);  // Visit the current node
}

// Function to delete the last node (simple delete for binary tree)
void delete(BinaryTree* bt) {
    if (bt->size == 0) {
        printf("Tree is empty.\n");
        return;
    }
    bt->size--;  // Remove the last element (node)
    printf("Deleted node %d\n", bt->tree[bt->size]);
}

// Function to display the tree in level-order (for debugging purposes)
void display(BinaryTree* bt) {
    if (bt->size == 0) {
        printf("Tree is empty.\n");
        return;
    }
    for (int i = 0; i < bt->size; i++) {
        printf("%d ", bt->tree[i]);
    }
    printf("\n");
}

int main() {
    BinaryTree bt;
    create(&bt);  // Initialize the binary tree

    // Insert nodes
    insert(&bt, 1);  // Root
    insert(&bt, 2);  // Left child of 1
    insert(&bt, 3);  // Right child of 1
    insert(&bt, 4);  // Left child of 2
    insert(&bt, 5);  // Right child of 2
    insert(&bt, 6);  // Left child of 3
    insert(&bt, 7);  // Right child of 3

    // Display the tree in level-order
    printf("Binary Tree (Level Order): ");
    display(&bt);
    
    // Preorder traversal
    printf("Preorder Traversal: ");
    preorder(&bt, 0);  // Start from the root (index 0)
    printf("\n");

    // Inorder traversal
    printf("Inorder Traversal: ");
    inorder(&bt, 0);  // Start from the root (index 0)
    printf("\n");

    // Postorder traversal
    printf("Postorder Traversal: ");
    postorder(&bt, 0);  // Start from the root (index 0)
    printf("\n");

    // Deleting the last node
    delete(&bt);
    delete(&bt);

    // Display after deletions
    printf("Binary Tree after deletions: ");
    display(&bt);

    return 0;
}
