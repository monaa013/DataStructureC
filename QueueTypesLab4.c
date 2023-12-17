#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a node from the linked list by value
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found in the list.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to display the linked list
void displayList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Queue operations using linked list (enqueue and dequeue)
void enqueue(struct Node** rear, int data) {
    insertNode(rear, data);
}

void dequeue(struct Node** front) {
    if (*front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = *front;
    *front = (*front)->next;
    free(temp);
}

int main() {
    struct Node* head = NULL; // Linked list
    struct Node* front = NULL; // Front of the queue
    struct Node* rear = NULL; // Rear of the queue

    // Insert nodes into the linked list
    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);

    // Display the linked list
    printf("Linked List: ");
    displayList(head);

    // Delete a node from the linked list
    deleteNode(&head, 20);
    printf("Linked List after deleting 20: ");
    displayList(head);

    // Enqueue elements into the queue (linked list implementation)
    enqueue(&rear, 40);
    enqueue(&rear, 50);
    enqueue(&rear, 60);

    // Dequeue elements from the queue (linked list implementation)
    dequeue(&front);
    printf("Queue after dequeue operation: ");
    displayList(front);

    return 0;
}
