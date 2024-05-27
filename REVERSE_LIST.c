//Reverse list

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
struct ListNode {
    int data;
    struct ListNode* next;
};

// Function to reverse the linked list iteratively
void Reverse(struct ListNode** head) {
    struct ListNode* prev = NULL;
    struct ListNode* current = *head;
    struct ListNode* next = NULL;

    while (current != NULL) {
        // Store the next node
        next = current->next;
        // Reverse the current node's pointer
        current->next = prev;
        // Move pointers one position ahead
        prev = current;
        current = next;
    }
    *head = prev;
}

// Function to push a new node at the beginning of the list
void push(struct ListNode** head, int new_data) {
    struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

// Function to print the linked list
void printList(struct ListNode* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to free the linked list
void freeList(struct ListNode* head) {
    struct ListNode* tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    struct ListNode* head = NULL;
    int n, value;

    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(&head, value);
    }

    printf("Original list: \n");
    printList(head);

    Reverse(&head);

    printf("Reversed list: \n");
    printList(head);

    // Free the allocated memory
    freeList(head);

    return 0;
}
