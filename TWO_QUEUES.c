//Write a Program to implement multiple two queues using array and perform following operations on it. A. Addq, B. Delq, C. Display Queue.

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define NUM_QUEUES 2 // Number of queues

// Arrays to hold the front and rear indices for each queue
int front[NUM_QUEUES];
int rear[NUM_QUEUES];

// Array to hold the elements of the queues
int array[MAX_SIZE];

// Function to initialize the queues
void initializeQueues() {
    for (int i = 0; i < NUM_QUEUES; i++) {
        front[i] = -1;
        rear[i] = -1;
    }
}

// Function to check if the queue is empty
int isEmpty(int queueNumber) {
    return (front[queueNumber] == -1);
}

// Function to check if the queue is full
int isFull(int queueNumber, int start, int end) {
    return ((rear[queueNumber] + 1) % MAX_SIZE == front[queueNumber]) || ((rear[queueNumber] + 1) % (end + 1) == start);
}

// Function to add an element to the queue
void enqueue(int queueNumber, int start, int end, int value) {
    if (isFull(queueNumber, start, end)) {
        printf("Queue %d is full. Cannot enqueue.\n", queueNumber + 1);
        return;
    }
    if (isEmpty(queueNumber)) {
        front[queueNumber] = start;
        rear[queueNumber] = start;
    } else {
        rear[queueNumber] = (rear[queueNumber] + 1) % (end + 1);
    }
    array[rear[queueNumber]] = value;
    printf("Enqueued %d to queue %d.\n", value, queueNumber + 1);
}

// Function to remove an element from the queue
int dequeue(int queueNumber, int start, int end) {
    if (isEmpty(queueNumber)) {
        printf("Queue %d is empty. Cannot dequeue.\n", queueNumber + 1);
        return -1;
    }
    int dequeuedValue = array[front[queueNumber]];
    if (front[queueNumber] == rear[queueNumber]) {
        front[queueNumber] = -1;
        rear[queueNumber] = -1;
    } else {
        front[queueNumber] = (front[queueNumber] + 1) % (end + 1);
    }
    printf("Dequeued %d from queue %d.\n", dequeuedValue, queueNumber + 1);
    return dequeuedValue;
}

// Function to display the elements of the queue
void displayQueue(int queueNumber, int start, int end) {
    if (isEmpty(queueNumber)) {
        printf("Queue %d is empty.\n", queueNumber + 1);
        return;
    }
    printf("Queue %d: ", queueNumber + 1);
    int i = front[queueNumber];
    while (1) {
        printf("%d ", array[i]);
        if (i == rear[queueNumber]) {
            break;
        }
        i = (i + 1) % (end + 1);
    }
    printf("\n");
}

int main() {
    initializeQueues();
    int partitionSize = MAX_SIZE / NUM_QUEUES;

    int choice, queueNumber, value;
    while (1) {
        printf("\n1. Addq (Enqueue)\n2. Delq (Dequeue)\n3. Display Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the queue number (1 to %d): ", NUM_QUEUES);
                scanf("%d", &queueNumber);
                if (queueNumber < 1 || queueNumber > NUM_QUEUES) {
                    printf("Invalid queue number\n");
                } else {
                    printf("Enter value to enqueue: ");
                    scanf("%d", &value);
                    enqueue(queueNumber - 1, (queueNumber - 1) * partitionSize, queueNumber * partitionSize - 1, value);
                }
                break;
            case 2:
                printf("Enter the queue number (1 to %d): ", NUM_QUEUES);
                scanf("%d", &queueNumber);
                if (queueNumber < 1 || queueNumber > NUM_QUEUES) {
                    printf("Invalid queue number\n");
                } else {
                    dequeue(queueNumber - 1, (queueNumber - 1) * partitionSize, queueNumber * partitionSize - 1);
                }
                break;
            case 3:
                printf("Enter the queue number (1 to %d): ", NUM_QUEUES);
                scanf("%d", &queueNumber);
                if (queueNumber < 1 || queueNumber > NUM_QUEUES) {
                    printf("Invalid queue number\n");
                } else {
                    displayQueue(queueNumber - 1, (queueNumber - 1) * partitionSize, queueNumber * partitionSize - 1);
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
        }
    }

    return 0;
}

