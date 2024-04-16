#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100 // Maximum size of the queue

// Initialize the queue and front/rear pointers
int queue[MAX_SIZE];
int front = 0;
int rear = -1;

// Function to check if the queue is empty
bool isEmpty() {
    return front > rear;
}

// Function to check if the queue is full
bool isFull() {
    return rear == MAX_SIZE - 1;
}

// Function to insert an element into the queue (enqueue)
void enqueue(int item) {
    if (isFull()) {
        printf("Queue overflow! Cannot enqueue %d.\n", item);
        return;
    }
    queue[++rear] = item;
    printf("Enqueued %d.\n", item);
}

// Function to remove an element from the queue (dequeue)
int dequeue() {
    if (isEmpty()) {
        printf("Queue underflow! Cannot dequeue.\n");
        return -1;
    }
    return queue[front++];
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Dequeued element: %d\n", dequeue());
    printf("Dequeued element: %d\n", dequeue());

    return 0;
}
