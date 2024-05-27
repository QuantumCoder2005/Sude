//implement circular double ended queue where user can add and remove the elements from both front and rearofthequeue

#include <stdio.h>
#include <stdlib.h>

// Define structure for deque node
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Define structure for deque
typedef struct {
    Node* front;
    Node* rear;
} Deque;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to initialize the deque
void initDeque(Deque* deque) {
    deque->front = NULL;
    deque->rear = NULL;
}

// Function to check if the deque is empty
int isEmpty(Deque* deque) {
    return deque->front == NULL;
}

// Function to add element to the front of the deque
void addFront(Deque* deque, int data) {
    Node* newNode = createNode(data);
    if (isEmpty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
    deque->front->prev = deque->rear;
    deque->rear->next = deque->front;
}

// Function to add element to the rear of the deque
void addRear(Deque* deque, int data) {
    Node* newNode = createNode(data);
    if (isEmpty(deque)) {
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
    deque->front->prev = deque->rear;
    deque->rear->next = deque->front;
}

// Function to remove element from the front of the deque
int removeFront(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return -1;
    }
    int data = deque->front->data;
    Node* temp = deque->front;
    if (deque->front == deque->rear) {
        deque->front = NULL;
        deque->rear = NULL;
    } else {
        deque->front = deque->front->next;
        deque->front->prev = deque->rear;
        deque->rear->next = deque->front;
    }
    free(temp);
    return data;
}

// Function to remove element from the rear of the deque
int removeRear(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return -1;
    }
    int data = deque->rear->data;
    Node* temp = deque->rear;
    if (deque->front == deque->rear) {
        deque->front = NULL;
        deque->rear = NULL;
    } else {
        deque->rear = deque->rear->prev;
        deque->rear->next = deque->front;
        deque->front->prev = deque->rear;
    }
    free(temp);
    return data;
}

// Function to display elements in the deque
void displayDeque(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty\n");
        return;
    }
    Node* current = deque->front;
    printf("Deque: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != deque->front);
    printf("\n");
}

int main() {
    Deque deque;
    initDeque(&deque);
    int choice, element;

    do {
        printf("\nCircular Double Ended Queue (Deque) Operations\n");
        printf("1. Add element to the front\n");
        printf("2. Add element to the rear\n");
        printf("3. Remove element from the front\n");
        printf("4. Remove element from the rear\n");
        printf("5. Display the deque\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to add to the front: ");
                scanf("%d", &element);
                addFront(&deque, element);
                break;
            case 2:
                printf("Enter element to add to the rear: ");
                scanf("%d", &element);
                addRear(&deque, element);
                break;
            case 3:
                element = removeFront(&deque);
                if (element != -1)
                    printf("Removed element from the front: %d\n", element);
                break;
            case 4:
                element = removeRear(&deque);
                if (element != -1)
                    printf("Removed element from the rear: %d\n", element);
                break;
            case 5:
                displayDeque(&deque);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
