#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    int id;
    int deadline;
    int profit;
} Job;

void jobSequencing(Job arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].profit < arr[j + 1].profit)
            {
                Job temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].deadline > maxDeadline)
        {
            maxDeadline = arr[i].deadline;
        }
    }

    int result[maxDeadline];
    bool slot[maxDeadline];
    for (int i = 0; i < maxDeadline; i++)
    {
        slot[i] = false;
    }

    int totalProfit = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].deadline - 1; j >= 0; j--)
        {
            if (slot[j] == false)
            {
                result[j] = arr[i].id;
                slot[j] = true;
                totalProfit += arr[i].profit;
                break;
            }
        }
    }

    printf("\nOptimal sequence of jobs:\n");
    for (int i = 0; i < maxDeadline; i++)
    {
        if (slot[i])
        {
            printf("J%d ", result[i]);
        }
    }
    printf("\nMaximum profit: %d\n", totalProfit);
}

int main()
{
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    Job arr[n];

    printf("Enter job ID, deadline, and profit for each job:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &arr[i].id, &arr[i].deadline, &arr[i].profit);
    }

    jobSequencing(arr, n);

    return 0;
}
