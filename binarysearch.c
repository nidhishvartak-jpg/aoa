#include <stdio.h>

int binarySearch(int arr[], int size, int target)
{
    int low = 0;
    int high = size - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2; // To avoid potential overflow

        if (arr[mid] == target)
        {
            return mid; // Target found
        }

        if (arr[mid] < target)
        {
            low = mid + 1; // Search in the right half
        }
        else
        {
            high = mid - 1; // Search in the left half
        }
    }

    return -1; // Target not found
}

int main()
{
    int size, target, result;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int data[size];

    printf("Enter %d integers in sorted order:\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &data[i]);
    }

    printf("Enter the element to search for: ");
    scanf("%d", &target);

    result = binarySearch(data, size, target);

    if (result != -1)
    {
        printf("Element found at index: %d\n", result);
    }
    else
    {
        printf("Element not found in the array.\n");
    }

    return 0;
}
