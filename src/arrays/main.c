#include <stdio.h>

int sumArray(int arr[], int size) {
    if (size == 0) {
        return 0;
    }

    return arr[size - 1] + sumArray(arr, size - 1);
}

int findMax(int arr[], int size) {
    if (size == 1) {
        return arr[0];
    }

    int max = findMax(arr, size - 1);

    if (arr[size - 1] > max) {
        return arr[size - 1];
    } else {
        return max;
    }
}

int binarySearch(int arr[], int left, int right, int target) {
    if (right >= left) {
        int pivot = left + (right - left) / 2;

        if (arr[pivot] == target) {
            return 1;
        }

        if (arr[pivot] > target) {
            return binarySearch(arr, left, pivot - 1, target);
        } 

        return binarySearch(arr, pivot + 1, right, target);
    }

    return -1;
}

int isSorted(int arr[], int size) {
    if (size == 1) {
        return 1;
    }

    if (arr[size - 1] >= arr[size - 2]) {
        return isSorted(arr, size - 1);
    }

    return -1;
}

int main(int argc, char *argv[]) {
    int arr[] = {2, 1, 1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(int);

    printf("sumArray(arr): %d\n", sumArray(arr, size));
    printf("findMax(arr): %d\n", findMax(arr, size));
    printf("binarySearch(arr, 0, size, 10): %d (1 = found, -1 = not found)\n", binarySearch(arr, 0, size, 10));
    printf("binarySearch(arr, 0, size, 2): %d (1 = found, -1 = not found)\n", binarySearch(arr, 0, size, 2));
    printf("isSorted(arr, 5): %d\n", isSorted(arr, size));
}
