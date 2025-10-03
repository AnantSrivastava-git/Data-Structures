#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void heapify(int arr[], int n, int i) {
    int largest = i;      
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    
    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n) {
    
    int start_index = (n / 2) - 1;
    int i;

    
    for (i = start_index; i >= 0; i--) {
        heapify(arr, n, i);
    }
}


void heapSort(int arr[], int n) {
    
    buildHeap(arr, n);

    
    int i;
    for (i = n - 1; i > 0; i--) {
        
        swap(&arr[0], &arr[i]);

        heapify(arr, i, 0);
    }
}


int main() {
    
    int data[] = {12, 11, 13, 5, 6, 7};
    int n1 = sizeof(data) / sizeof(data[0]);

    printf("--- Test Case 1 ---\n");
    printf("Original array: ");
    printArray(data, n1);

    
    heapSort(data, n1);

    printf("Sorted array (Ascending): ");
    printArray(data, n1);


    
    int large_data[] = {50, 20, 75, 12, 99, 5, 80, 1};
    int n2 = sizeof(large_data) / sizeof(large_data[0]);

    printf("\n--- Test Case 2 ---\n");
    printf("Original array: ");
    printArray(large_data, n2);


    heapSort(large_data, n2);

    printf("Sorted array (Ascending): ");
    printArray(large_data, n2);

    return 0;
}