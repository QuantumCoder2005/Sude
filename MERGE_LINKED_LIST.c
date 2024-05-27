// merge two sorted linked lists

#include <stdio.h>
#include <stdlib.h>

// Definition of a doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the end of the doubly linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to merge two sorted doubly linked lists
struct Node* mergeSortedLists(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node* result = NULL;

    if (head1->data <= head2->data) {
        result = head1;
        result->next = mergeSortedLists(head1->next, head2);
        if (result->next != NULL) {
            result->next->prev = result;
        }
    } else {
        result = head2;
        result->next = mergeSortedLists(head1, head2->next);
        if (result->next != NULL) {
            result->next->prev = result;
        }
    }

    return result;
}

// Function to print the doubly linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d <-> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to free the list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    struct Node* mergedHead = NULL;
    int n1, n2, value;

    // Input first sorted list
    printf("Enter the number of elements in the first sorted list: ");
    scanf("%d", &n1);
    printf("Enter the elements of the first sorted list:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &value);
        insertAtEnd(&head1, value);
    }

    // Input second sorted list
    printf("Enter the number of elements in the second sorted list: ");
    scanf("%d", &n2);
    printf("Enter the elements of the second sorted list:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &value);
        insertAtEnd(&head2, value);
    }

    // Merge the two sorted lists
    mergedHead = mergeSortedLists(head1, head2);

    // Print the merged list
    printf("Merged sorted list: \n");
    printList(mergedHead);

    // Free the allocated memory
    freeList(mergedHead);

    return 0;
}
