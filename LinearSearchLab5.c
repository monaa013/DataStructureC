#include <stdio.h>

// Linear Search
int linearSearch(int arr[], int n, int key, int *elementComparisons, int *indexComparisons) {
    *elementComparisons = 0;
    *indexComparisons = 0;
    for (int i = 0; i < n; i++) {
        *indexComparisons += 1;
        if (arr[i] == key) {
            *elementComparisons += 1;
            return i; // Element found at index i
        }
        *elementComparisons += 1;
    }
    return -1; // Element not found
}

// Sentinel Search
int sentinelSearch(int arr[], int n, int key, int *elementComparisons, int *indexComparisons) {
    *elementComparisons = 0;
    *indexComparisons = 0;
    int last = arr[n - 1];
    arr[n - 1] = key;

    int i = 0;
    while (arr[i] != key) {
        *elementComparisons += 1;
        i++;
    }

    arr[n - 1] = last;
    if (i < n - 1 || arr[n - 1] == key) {
        *indexComparisons += 1;
        return i;
    }
    return -1; // Element not found
}

// Binary Search
int binarySearch(int arr[], int left, int right, int key, int *elementComparisons, int *indexComparisons) {
    *elementComparisons = 0;
    *indexComparisons = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        *indexComparisons += 1;
        if (arr[mid] == key) {
            *elementComparisons += 1;
            return mid; // Element found at index mid
        }
        *elementComparisons += 1;

        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // Element not found
}

// Bubble Sort
void bubbleSort(int arr[], int n, int *comparisons, int *dataTransfers) {
    *comparisons = 0;
    *dataTransfers = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            *comparisons += 1;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                *dataTransfers += 3; // Three data transfers (swap)
            }
        }
    }
}

// Insertion Sort
void insertionSort(int arr[], int n, int *comparisons, int *dataTransfers) {
    *comparisons = 0;
    *dataTransfers = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        *comparisons += 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            *comparisons += 1;
            *dataTransfers += 1; // Data transfer for shifting
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    printf("Enter the number of chocolates: ");
    scanf("%d", &n);

    int chocolates[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &chocolates[i]);
    }

    int key;
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Perform Bubble Sort
    int bubbleComparisons, bubbleDataTransfers;
    bubbleSort(chocolates, n, &bubbleComparisons, &bubbleDataTransfers);

    // Perform Insertion Sort
    int insertionComparisons, insertionDataTransfers;
    insertionSort(chocolates, n, &insertionComparisons, &insertionDataTransfers);

    // Perform Linear Search
    int linearElementComparisons, linearIndexComparisons;
    int linearResult = linearSearch(chocolates, n, key, &linearElementComparisons, &linearIndexComparisons);

    // Perform Sentinel Search
    int sentinelElementComparisons, sentinelIndexComparisons;
    int sentinelResult = sentinelSearch(chocolates, n, key, &sentinelElementComparisons, &sentinelIndexComparisons);

    // Perform Binary Search (Requires array to be sorted)
    int binaryElementComparisons, binaryIndexComparisons;
    int binaryResult = binarySearch(chocolates, 0, n - 1, key, &binaryElementComparisons, &binaryIndexComparisons);

    // Display results
    printf("\nSorted Chocolates: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", chocolates[i]);
    }
    printf("\n");

    printf("\nLinear Search:\n");
    printf("Element Comparisons: %d\n", linearElementComparisons);
    printf("Index Comparisons: %d\n", linearIndexComparisons);
    if (linearResult != -1) {
        printf("Element found at index: %d\n", linearResult);
    } else {
        printf("Element not found\n");
    }
    printf("\n");

    printf("Sentinel Search:\n");
    printf("Element Comparisons: %d\n", sentinelElementComparisons);
    printf("Index Comparisons: %d\n", sentinelIndexComparisons);
    if (sentinelResult != -1) {
        printf("Element found at index: %d\n", sentinelResult);
    } else {
        printf("Element not found\n");
    }
    printf("\n");

    printf("Binary Search:\n");
    printf("Element Comparisons: %d\n", binaryElementComparisons);
    printf("Index Comparisons: %d\n", binaryIndexComparisons);
    if (binaryResult != -1) {
        printf("Element found at index: %d\n", binaryResult);
    } else {
        printf("Element not found\n");
    }
    printf("\n");

    printf("Bubble Sort:\n");
    printf("Total Comparisons: %d\n", bubbleComparisons);
    printf("Total Data Transfers: %d\n", bubbleDataTransfers);
    printf("\n");

    printf("Insertion Sort:\n");
    printf("Total Comparisons: %d\n", insertionComparisons);
    printf("Total Data Transfers: %d\n", insertionDataTransfers);

    return 0;
}
