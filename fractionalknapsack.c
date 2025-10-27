#include <stdio.h>

struct Item
{
    int profit;
    int weight;
    double ratio;
};

double fractionalKnapsack(int capacity, struct Item arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i].ratio = (double)arr[i].profit / arr[i].weight;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].ratio < arr[j + 1].ratio)
            {
                struct Item temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    double totalProfit = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight <= capacity)
        {
            totalProfit += arr[i].profit;
            capacity -= arr[i].weight;
        }
        else
        {
            totalProfit += arr[i].profit * ((double)capacity / arr[i].weight);
            break;
        }
    }

    return totalProfit;
}

int main()
{
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter the profit and weight for each item:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &items[i].profit, &items[i].weight);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    double maxProfit = fractionalKnapsack(capacity, items, n);
    printf("Maximum profit in Knapsack = %.2f\n", maxProfit);

    return 0;
}
