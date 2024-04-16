#include <stdio.h>
#include <stdlib.h>

// Define the structure for a singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the list
void insertStart(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    printf("Inserted %d\n", newNode->data);
}

// Function to delete the first node from the list
void deleteStart(struct Node** head) {
    struct Node* temp = *head;
    if (*head == NULL) {
        printf("Impossible to delete from an empty Singly Linked List\n");
        return;
    }
    *head = (*head)->next;
    printf("Deleted: %d\n", temp->data);
    free(temp);
}

// Function to display the entire linked list
void display(struct Node* node) {
    printf("\nLinked List: ");
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL; // Initialize an empty linked list

    // Insert some elements at the beginning
    insertStart(&head, 10);
    insertStart(&head, 20);
    insertStart(&head, 30);

    // Display the list
    display(head);

    // Delete the first element
    deleteStart(&head);

    // Display the updated list
    display(head);

    return 0;
}
