#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100 // Maximum size of the stack

// Initialize the stack and top pointer
int stack[MAX_SIZE];
int top = -1;

// Function to check if the stack is empty
bool isEmpty() {
    return top == -1;
}

// Function to check if the stack is full
bool isFull() {
    return top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(int item) {
    if (isFull()) {
        printf("Stack overflow! Cannot push %d.\n", item);
        return;
    }
    stack[++top] = item;
    printf("Pushed %d onto the stack.\n", item);
}

// Function to pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack underflow! Cannot pop.\n");
        return -1;
    }
    return stack[top--];
}

// Function to peek at the top element without removing it
int peek() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack[top];
}

int main() {
    push(10);
    push(20);
    push(30);

    printf("Top element: %d\n", peek());

    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop());

    printf("Is the stack empty? %s\n", isEmpty() ? "Yes" : "No");

    return 0;
}
