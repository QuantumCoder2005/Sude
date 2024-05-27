/*
10.Write a Program to create a Binary Search Tree and display its mirror image with and without
disturbing the original tree. Also display height of a tree using nonrecursion.
*/
#include <stdio.h>
#include <stdlib.h>

// Definition of the tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to display the inorder traversal of the tree
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to create the mirror image of the tree iteratively (modifies the original tree)
void mirrorTreeIterative(struct Node* root) {
    if (root == NULL) {
        return;
    }
    struct Node* stack[100];
    int top = -1;
    stack[++top] = root;
    while (top >= 0) {
        struct Node* current = stack[top--];
        struct Node* temp = current->left;
        current->left = current->right;
        current->right = temp;
        if (current->left) {
            stack[++top] = current->left;
        }
        if (current->right) {
            stack[++top] = current->right;
        }
    }
}

// Function to create a mirror image of the tree without modifying the original tree
struct Node* mirrorCopy(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }
    struct Node* newRoot = createNode(root->data);
    newRoot->left = mirrorCopy(root->right);
    newRoot->right = mirrorCopy(root->left);
    return newRoot;
}

// Function to calculate the height of the tree iteratively
int treeHeight(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int height = 0;
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        int nodeCount = rear - front;
        if (nodeCount == 0) {
            return height;
        }
        height++;
        while (nodeCount > 0) {
            struct Node* node = queue[front++];
            if (node->left != NULL) {
                queue[rear++] = node->left;
            }
            if (node->right != NULL) {
                queue[rear++] = node->right;
            }
            nodeCount--;
        }
    }
    return height;
}

int main() {
    struct Node* root = NULL;
    int n, data;

    // Input number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Input node values
    for (int i = 0; i < n; i++) {
        printf("Enter node value %d: ", i + 1);
        scanf("%d", &data);
        root = insert(root, data);
    }

    // Display the original tree in inorder
    printf("Original tree inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Display the mirror image of the tree without modifying the original tree
    struct Node* mirroredRoot = mirrorCopy(root);
    printf("Mirror image (without modifying original) inorder traversal: ");
    inorderTraversal(mirroredRoot);
    printf("\n");

    // Display the mirror image of the tree by modifying the original tree
    mirrorTreeIterative(root);
    printf("Mirror image (modifying original) inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    // Display the height of the original tree
    int height = treeHeight(root);
    printf("Height of the tree: %d\n", height);

    return 0;
}
