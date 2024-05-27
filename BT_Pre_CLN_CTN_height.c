//Write a Program to create a Binary Tree and perform following non-recursive operations on it. a. Preorder Traversal b. Count Leaf Nodes c. Count total no. of nodes d. Display height of a tree.

#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Queue structure for level order traversal
struct Queue {
    struct Node* data;
    struct Queue* next;
};

void enqueue(struct Queue** front, struct Queue** rear, struct Node* node) {
    struct Queue* newQueueNode = (struct Queue*)malloc(sizeof(struct Queue));
    newQueueNode->data = node;
    newQueueNode->next = NULL;
    if (*rear == NULL) {
        *front = *rear = newQueueNode;
        return;
    }
    (*rear)->next = newQueueNode;
    *rear = newQueueNode;
}

struct Node* dequeue(struct Queue** front, struct Queue** rear) {
    if (*front == NULL) return NULL;
    struct Node* node = (*front)->data;
    struct Queue* temp = *front;
    *front = (*front)->next;
    if (*front == NULL) *rear = NULL;
    free(temp);
    return node;
}

int isQueueEmpty(struct Queue* front) {
    return front == NULL;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in a binary tree
struct Node* insertNode(struct Node* root, int data) {
    struct Node* newNode = createNode(data);
    if (root == NULL) {
        return newNode;
    }

    struct Queue *front = NULL, *rear = NULL;
    enqueue(&front, &rear, root);

    while (!isQueueEmpty(front)) {
        struct Node* temp = dequeue(&front, &rear);

        if (temp->left == NULL) {
            temp->left = newNode;
            return root;
        } else {
            enqueue(&front, &rear, temp->left);
        }

        if (temp->right == NULL) {
            temp->right = newNode;
            return root;
        } else {
            enqueue(&front, &rear, temp->right);
        }
    }

    return root;
}

// Function for non-recursive preorder traversal
void preorderTraversal(struct Node* root) {
    if (root == NULL) return;

    struct Node* stack[100];
    int top = -1;

    stack[++top] = root;

    while (top >= 0) {
        struct Node* node = stack[top--];
        printf("%d ", node->data);

        if (node->right != NULL) {
            stack[++top] = node->right;
        }
        if (node->left != NULL) {
            stack[++top] = node->left;
        }
    }
    printf("\n");
}

// Function to count leaf nodes
int countLeafNodes(struct Node* root) {
    if (root == NULL) return 0;

    int count = 0;
    struct Queue *front = NULL, *rear = NULL;
    enqueue(&front, &rear, root);

    while (!isQueueEmpty(front)) {
        struct Node* temp = dequeue(&front, &rear);

        if (temp->left == NULL && temp->right == NULL) {
            count++;
        } else {
            if (temp->left != NULL) enqueue(&front, &rear, temp->left);
            if (temp->right != NULL) enqueue(&front, &rear, temp->right);
        }
    }

    return count;
}

// Function to count total number of nodes
int countTotalNodes(struct Node* root) {
    if (root == NULL) return 0;

    int count = 0;
    struct Queue *front = NULL, *rear = NULL;
    enqueue(&front, &rear, root);

    while (!isQueueEmpty(front)) {
        struct Node* temp = dequeue(&front, &rear);
        count++;
        if (temp->left != NULL) enqueue(&front, &rear, temp->left);
        if (temp->right != NULL) enqueue(&front, &rear, temp->right);
    }

    return count;
}

// Function to display height of the tree
int displayHeight(struct Node* root) {
    if (root == NULL) return 0;

    int height = 0;
    struct Queue *front = NULL, *rear = NULL;
    enqueue(&front, &rear, root);

    while (1) {
        int nodeCount = 0;
        struct Queue *tempFront = front, *tempRear = rear;
        
        while (!isQueueEmpty(tempFront)) {
            dequeue(&tempFront, &tempRear);
            nodeCount++;
        }

        if (nodeCount == 0) return height;
        
        height++;
        while (nodeCount > 0) {
            struct Node* node = dequeue(&front, &rear);
            if (node->left != NULL) enqueue(&front, &rear, node->left);
            if (node->right != NULL) enqueue(&front, &rear, node->right);
            nodeCount--;
        }
    }
}

int main() {
    struct Node* root = NULL;
    int choice, data;

    while (1) {
        printf("\nBinary Tree Operations:\n");
        printf("1. Insert node\n");
        printf("2. Preorder traversal\n");
        printf("3. Count leaf nodes\n");
        printf("4. Count total nodes\n");
        printf("5. Display height\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;
            case 2:
                printf("Preorder traversal: ");
                preorderTraversal(root);
                break;
            case 3:
                printf("Number of leaf nodes: %d\n", countLeafNodes(root));
                break;
            case 4:
                printf("Total number of nodes: %d\n", countTotalNodes(root));
                break;
            case 5:
                printf("Height of the tree: %d\n", displayHeight(root));
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
