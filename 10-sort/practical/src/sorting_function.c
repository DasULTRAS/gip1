#include <stdio.h>
#include <stdlib.h>

#include "sorting_function.h"
#include "my_array.h"

#define swap(a, b)\
{\
int temp = a;\
a = b;\
b = temp;\
}


void merge_sort(int *array, unsigned int length) {
    if (length <= 1)
        return;

    // Teilen in zwei Array
    int *arr1 = array;
    unsigned int arr1_length = length / 2;
    int *arr2 = array + arr1_length;
    unsigned int arr2_length = length - arr1_length;

    // die geteilten weiter teilen, danach sind diese sortiert
    merge_sort(arr1, arr1_length);
    merge_sort(arr2, arr2_length);

    // einen neuen temp array chronologisch auffüllen (sortiert)
    int *arr = calloc(length, sizeof(int));
    int arr1_pointer = 0;
    int arr2_pointer = 0;
    for (int i = 0; i < length; ++i)
        if ((*(arr1 + arr1_pointer) < *(arr2 + arr2_pointer) || arr2_pointer >= arr2_length) &&
            arr1_pointer < arr1_length) {
            arr[i] = *(arr1 + arr1_pointer);
            ++arr1_pointer;
        } else if (arr2_pointer < arr2_length) {
            arr[i] = *(arr2 + arr2_pointer);
            ++arr2_pointer;
        }

    // Neuen Array wieder in den alten verschieben
    for (int i = 0; i < length; ++i)
        array[i] = arr[i];

    // Speicher für neuen Array zurückgeben
    free(arr);
}

void quick_sort(int *arr, int left, int right) {
    int l = left;
    int r = right - 1;
    // int pivot = right;

    do {
        while (arr[l] < arr[right])
            ++l;
        while (arr[right] <= arr[r] && l < r)
            --r;
        if (l < r) swap(arr[l], arr[r]);
    } while (l < r);

    // Pivot in die mitte tauschen
    swap(arr[l], arr[right]);

    if (left < l - 1)
        quick_sort(arr, left, l - 1);
    if (l + 1 < right)
        quick_sort(arr, l + 1, right);
}
