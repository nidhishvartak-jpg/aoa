#include <stdio.h>

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int size;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int data[size];

    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &data[i]);
    }

    printf("Unsorted Array:\n");
    printArray(data, size);

    insertionSort(data, size);

    printf("Sorted Array:\n");
    printArray(data, size);

    return 0;
}
