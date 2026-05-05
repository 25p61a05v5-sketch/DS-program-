
#include <stdio.h>

// Function to find maximum element
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Counting Sort (for a specific digit)
void countingSort(int arr[], int n, int exp) {
    int output[n];        // Output array
    int count[10] = {0};  // Digit count (0–9)

    // Count occurrences
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Convert to cumulative count
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build output array (stable)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy back
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Function to perform Shell Sort
void shellSort(int arr[], int n) {
    int gap, i, j, temp;

    // Start with a large gap, then reduce the gap
    for (gap = n / 2; gap > 0; gap /= 2) {
        
        // Perform insertion sort for this gap
        for (i = gap; i < n; i++) {
            temp = arr[i];

            // Shift earlier gap-sorted elements up
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

// Main function
int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    shellSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}


