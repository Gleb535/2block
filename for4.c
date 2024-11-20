#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *sort(int *, int);

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    int mas[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", &mas[i]);

    int *ptr = mas;

    int *res = sort(ptr, n);
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d ", res[i]);

    return 0;
}

int *sort(int *ms, int len)
{
    int *sorted = malloc((len) * sizeof(int));
    memcpy(sorted, ms, (len) * sizeof(int));

    for (int i = 0; i < len; i++)
        for (int j = 0; j < len - 1 - i; j++)
            if (sorted[j] > sorted[j + 1])
            {
                int temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
    return sorted;
}