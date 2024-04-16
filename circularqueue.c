#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100 // Maximum size of the circular queue

// Initialize the circular queue and front/rear pointers
int circularQueue[MAX_SIZE];
int front = -1;
int rear = -1;

// Function to check if the circular queue is empty
bool isEmpty() {
    return front == -1;
}

// Function to check if the circular queue is full
bool isFull() {
    return (front == 0 && rear == MAX_SIZE - 1) || (rear == front - 1);
}

// Function to insert an element into the circular queue (enqueue)
void enqueue(int item) {
    if (isFull()) {
        printf("Circular queue overflow! Cannot enqueue %d.\n", item);
        return;
    }
    if (front == -1)
        front = 0;
    rear = (rear + 1) % MAX_SIZE;
    circularQueue[rear] = item;
    printf("Enqueued %d.\n", item);
}

// Function to remove an element from the circular queue (dequeue)
int dequeue() {
    if (isEmpty()) {
        printf("Circular queue underflow! Cannot dequeue.\n");
        return -1;
    }
    int item = circularQueue[front];
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX_SIZE;
    printf("Dequeued element: %d\n", item);
    return item;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    dequeue();
    dequeue();

    return 0;
}
