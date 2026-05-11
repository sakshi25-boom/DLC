#include <stdio.h>

// Helper function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function: places the pivot in its correct position
int partition(int arr[], int low, int high) {
    // We choose the last element as the pivot
    int pivot = arr[high]; 
    int i = (low - 1); // Index of the smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    // Swap the pivot element with the element at i+1
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Main QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is the partitioning index, arr[pi] is now at the right place
        int pi = partition(arr, low, high);

        // Separately sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int data[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(data) / sizeof(data[0]);
    
    printf("Unsorted array: \n");
    printArray(data, n);
    
    quickSort(data, 0, n - 1);
    
    printf("Sorted array: \n");
    printArray(data, n);
    return 0;
}
