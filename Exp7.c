#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INF 99999

void printSolution(int V, int dist[][V])
{
    printf("The following matrix shows the shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
            {
                printf("%7s", "INF");
            }
            else
            {
                printf("%7d", dist[i][j]);
            }
        }
        printf("\n");
    }
}

void floydWarshall(int V, int graph[][V])
{
    int dist[V][V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printSolution(V, dist);
}

int main()
{
    int V;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int graph[V][V];
    char inputBuffer[20];

    printf("Enter the adjacency matrix for the graph:\n");
    printf("(Use 'inf' for infinity/no direct path)\n");

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            scanf("%s", inputBuffer); // Text input
            if (strcmp(inputBuffer, "inf") == 0 || strcmp(inputBuffer, "INF") == 0)
            {
                graph[i][j] = INF;
            }
            else
            {
                graph[i][j] = atoi(inputBuffer); // Text to Number Conversion
            }
        }
    }

    floydWarshall(V, graph);

    return 0;
}
