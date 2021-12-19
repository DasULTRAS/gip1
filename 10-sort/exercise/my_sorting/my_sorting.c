#define swap(a, b) \
{\
int temp = a;\
a = b;\
b = temp;\
}

/**
 * Sorting by Bubblesort algorithm
 * @param array
 * @param length
 */
void bubble_sort(int *array, unsigned int length) {
    for (int i = length; i > 0; --i)
        for (int j = 0; j < i; ++j)
            if (array[j] > array[j + 1]) swap(array[j], array[j + 1]);
}
