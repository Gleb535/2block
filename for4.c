#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *sort(int *, int);

int main(void)
{
    int n;
    scanf("%d", &n);
    int mas[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", &mas[i]);
    printf("\n");

    for (int i = 0; i < n; ++i)
        printf("%d ", mas[i]);
    int *ptr_mas = mas;
    printf("\n%d", ptr_mas[2]);

    return 0;
}

int *sort(int *ms, int len)
{
    int *sorted = malloc((len + 1) * sizeof(int));
    memcpy(sorted, ms, (len + 1) * sizeof(int));

    for (int i = 0; i < len; i++)
        for (int j = 0; j < len - 1 - i; j++)
            if (sorted[j] > sorted[j + 1])
            {
                int temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
    free(sorted);
    return sorted;
}