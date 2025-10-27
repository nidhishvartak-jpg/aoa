#include <stdio.h>
#include <stdbool.h>

void naiveSearch(const char *text, const char *pattern)
{
    int n = 0;
    while (text[n] != '\0')
    {
        n++;
    }

    int m = 0;
    while (pattern[m] != '\0')
    {
        m++;
    }

    bool found = false;

    for (int i = 0; i <= n - m; i++)
    {
        int j;

        for (j = 0; j < m; j++)
        {
            if (text[i + j] != pattern[j])
            {
                break;
            }
        }

        if (j == m)
        {
            printf("Pattern found at index %d\n", i);
            found = true;
        }
    }

    if (!found)
    {
        printf("Pattern not found in the text.\n");
    }
}

int main()
{
    char text[256];
    char pattern[256];

    printf("Enter the main text string: ");
    scanf("%s", text);

    printf("Enter the pattern string: ");
    scanf("%s", pattern);

    printf("\n--- Results ---\n");
    naiveSearch(text, pattern);

    return 0;
}
