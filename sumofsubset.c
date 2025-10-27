#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 20

bool hasSolution = false;

void printSubset(int subset[], int size)
{
    hasSolution = true;
    printf("[ ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", subset[i]);
    }
    printf("]\n");
}

void findSubsets(
    int set[],
    int n,
    int subset[],
    int subsetSize,
    int currentSum,
    int targetSum,
    int index)
{
    if (currentSum == targetSum)
    {
        printSubset(subset, subsetSize);
        return;
    }

    if (index == n || currentSum > targetSum)
    {
        return;
    }

    subset[subsetSize] = set[index];
    findSubsets(set, n, subset, subsetSize + 1, currentSum + set[index], targetSum, index + 1);

    findSubsets(set, n, subset, subsetSize, currentSum, targetSum, index + 1);
}

int main()
{
    int set[MAX_SIZE];
    int subset[MAX_SIZE];
    int n, targetSum;

    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &set[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    printf("\nSubsets with sum %d are:\n", targetSum);
    findSubsets(set, n, subset, 0, 0, targetSum, 0);

    if (!hasSolution)
    {
        printf("No subset with the given sum found.\n");
    }

    return 0;
}
