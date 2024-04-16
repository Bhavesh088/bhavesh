#include <stdio.h>

// Iterative Binary Search
int binarySearchIterative(int arr[], int n, int x) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // Element not found
}

// Recursive Binary Search
int binarySearchRecursive(int arr[], int low, int high, int x) {
    if (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            return binarySearchRecursive(arr, mid + 1, high, x);
        else
            return binarySearchRecursive(arr, low, mid - 1, x);
    }
    return -1; // Element not found
}

int main() {
    int arr[] = {3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 4;

    // Iterative Binary Search
    int resultIterative = binarySearchIterative(arr, n, x);
    if (resultIterative != -1)
        printf("Element found at index %d (Iterative)\n", resultIterative);
    else
        printf("Element not found (Iterative)\n");

    // Recursive Binary Search
    int resultRecursive = binarySearchRecursive(arr, 0, n - 1, x);
    if (resultRecursive != -1)
        printf("Element found at index %d (Recursive)\n", resultRecursive);
    else
        printf("Element not found (Recursive)\n");

    return 0;
}
