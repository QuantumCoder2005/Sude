/*
26. Write a Program to implement circular queuewhere user can add and remove the elements fromrear andfront end of 
*/


#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of the queue

// Circular queue structure
typedef struct {
    int arr[MAX];
    int front;
    int rear;
    int count;
} CircularQueue;

// Function to initialize the queue
void initQueue(CircularQueue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

// Function to check if the queue is empty
int isEmpty(CircularQueue *q) {
    return q->count == 0;
}

// Function to check if the queue is full
int isFull(CircularQueue *q) {
    return q->count == MAX;
}

// Function to add an element to the rear of the queue
void enqueueRear(CircularQueue *q, int data) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue at rear.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = data;
    q->count++;
    printf("%d enqueued to rear of queue\n", data);
}

// Function to add an element to the front of the queue
void enqueueFront(CircularQueue *q, int data) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue at front.\n");
        return;
    }
    q->front = (q->front - 1 + MAX) % MAX;
    q->arr[q->front] = data;
    q->count++;
    printf("%d enqueued to front of queue\n", data);
}

// Function to remove an element from the front of the queue
int dequeueFront(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue from front.\n");
        return -1;
    }
    int data = q->arr[q->front];
    q->front = (q->front + 1) % MAX;
    q->count--;
    return data;
}

// Function to remove an element from the rear of the queue
int dequeueRear(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue from rear.\n");
        return -1;
    }
    int data = q->arr[q->rear];
    q->rear = (q->rear - 1 + MAX) % MAX;
    q->count--;
    return data;
}

// Function to display the queue
void displayQueue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements are:\n");
    int i = q->front;
    for (int j = 0; j < q->count; j++) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Main function to test the queue operations
int main() {
    CircularQueue q;
    initQueue(&q);

    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue at Rear\n");
        printf("2. Enqueue at Front\n");
        printf("3. Dequeue from Front\n");
        printf("4. Dequeue from Rear\n");
        printf("5. Display Queue\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue at rear: ");
                scanf("%d", &data);
                enqueueRear(&q, data);
                break;
            case 2:
                printf("Enter the element to enqueue at front: ");
                scanf("%d", &data);
                enqueueFront(&q, data);
                break;
            case 3:
                data = dequeueFront(&q);
                if (data != -1) {
                    printf("Dequeued element from front is %d\n", data);
                }
                break;
            case 4:
                data = dequeueRear(&q);
                if (data != -1) {
                    printf("Dequeued element from rear is %d\n", data);
                }
                break;
            case 5:
                displayQueue(&q);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


