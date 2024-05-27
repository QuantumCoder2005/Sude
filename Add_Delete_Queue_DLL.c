// Implement ADD and DELETE operations of QUEUE on Doubly linked lists
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Define the queue structure
typedef struct {
    Node* head;
    Node* tail;
} Queue;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the queue
void initializeQueue(Queue* q) {
    q->head = NULL;
    q->tail = NULL;
}

// Function to add an element to the queue (enqueue)
void enqueue(Queue* q, int data) {
    Node* newNode = createNode(data);
    if (q->tail == NULL) {
        // If the queue is empty, both head and tail point to the new node
        q->head = q->tail = newNode;
    } else {
        // Append the new node to the end of the list and update the tail
        q->tail->next = newNode;
        newNode->prev = q->tail;
        q->tail = newNode;
    }
    printf("Enqueued: %d\n", data);
}

// Function to remove an element from the queue (dequeue)
void dequeue(Queue* q) {
    if (q->head == NULL) {
        // If the queue is empty, there's nothing to dequeue
        printf("Queue is empty, nothing to dequeue.\n");
        return;
    }
    Node* temp = q->head;
    if (q->head == q->tail) {
        // If there's only one element in the queue
        q->head = q->tail = NULL;
    } else {
        // Move the head pointer to the next node
        q->head = q->head->next;
        q->head->prev = NULL;
    }
    printf("Dequeued: %d\n", temp->data);
    free(temp); // Free the memory of the dequeued node
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->head == NULL;
}

// Function to get the front element of the queue
int front(Queue* q) {
    if (q->head == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->head->data;
}

// Function to display the queue
void displayQueue(Queue* q) {
    if (q->head == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    Node* temp = q->head;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue q;
    initializeQueue(&q);
    int choice, value;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Front\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                displayQueue(&q);
                break;
            case 4:
                value = front(&q);
                if (value != -1) {
                    printf("Front element: %d\n", value);
                }
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

