#include <stdio.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int *a, int l, int r) {
    int pivot = a[r];
    int index_of_lowest = l - 1;
    for (int i = l; i < r; ++i) {
        if (a[i] <= pivot) {
            index_of_lowest++;
            swap(&a[i], &a[index_of_lowest]);
        }
    }
    swap(&a[index_of_lowest + 1], &a[r]);
    return (index_of_lowest + 1);
}

void quicksort(int *a, int l, int r) {
    if (l < r) {
        int p = partition(a, l, r);
        quicksort(a, l, p - 1);
        quicksort(a, p + 1, r);
    }
}


int main() {
    int n = 11;
    int a[] = {10, 8, 125, 3, 8, 2, 9, 113, -1, 56, 34};

    quicksort(&a[0], 0, n - 1);
    printf("Sorted array:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
