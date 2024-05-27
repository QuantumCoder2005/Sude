/*
12.Write a Program to create Inorder Threaded Binary Tree and Traverse it in Preorder way.
*/
#include <stdio.h>
#include <stdlib.h>

// Definition of Node structure
typedef struct Node {
    int data;
    struct Node *left, *right;
    int isThreaded;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->isThreaded = 0;
    return newNode;
}

// Function to insert a node in inorder threaded binary tree
void insert(Node** root, int data) {
    Node* newNode = createNode(data);

    if (*root == NULL) {
        *root = newNode;
        return;
    }

    Node* current = *root;
    Node* parent = NULL;

    while (current != NULL) {
        parent = current;

        if (data < current->data) {
            if (current->left == NULL) {
                current->left = newNode;
                newNode->right = current;
                newNode->isThreaded = 1;
                return;
            }
            current = current->left;
        } else {
            if (current->isThreaded || current->right == NULL) {
                if (current->isThreaded) {
                    newNode->right = current->right;
                    newNode->isThreaded = 1;
                }
                current->right = newNode;
                current->isThreaded = 0;
                return;
            }
            current = current->right;
        }
    }
}

// Function to perform preorder traversal of inorder threaded binary tree
void preorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    Node* current = root;
    Node* stack[100]; // Stack to store nodes
    int top = -1;     // Initialize stack as empty

    while (current != NULL || top != -1) {
        while (current != NULL) {
            printf("%d ", current->data);
            if (current->left != NULL) {
                stack[++top] = current; // Push current node to stack
            }
            current = current->left;
        }

        if (top != -1) {
            current = stack[top--]; // Pop from stack
            current = current->right;
        }
    }
}

int main() {
    Node* root = NULL;
    int n, data;

    // Input number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Input node values
    for (int i = 0; i < n; i++) {
        printf("Enter node value %d: ", i + 1);
        scanf("%d", &data);
        insert(&root, data);
    }

    // Traverse the tree in preorder
    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    return 0;
}
