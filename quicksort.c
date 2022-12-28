#include <stdio.h>
#include <stdlib.h>

#define N 8

void quick_sort(int *x, int n)
{
    if (n < 2)
    {
        return;
    }

    int p = (int)n / 2;
    int pivot = x[p];

    int n_less = 0;
    for (int i = 0; i < n; i++)
    {
        if (x[i] < pivot)
        {
            n_less++;
        }
    }
    int n_greater = n - n_less - 1;

    int *less = NULL;
    int *greater = NULL;

    if (n_less)
    {
        less = malloc(sizeof(int) * n_less);
        int i_less = 0;
        for (int i = 0; i < n; i++)
        {
            if (x[i] < pivot)
            {
                less[i_less++] = x[i];
            }
        }
        quick_sort(less, n_less);
    }
    if (n_greater)
    {
        greater = malloc(sizeof(int) * n_greater);
        int i_greater = 0;
        for (int i = 0; i < n; i++)
        {
            if ((i != p) && (x[i] >= pivot))
            {
                greater[i_greater++] = x[i];
            }
        }
        quick_sort(greater, n_greater);
    }

    for (int i = 0; i < n_less; i++)
    {
        x[i] = less[i];
    }
    x[n_less] = pivot;
    for (int i = 0; i < n_greater; i++)
    {
        x[n_less + 1 + i] = greater[i];
    }

    return;
}

int main()
{
    int a[] = {1, 3, 2, 4, 6, 7, 5, 8};
    quick_sort(a, N);
    for (int i = 0; i < N; i++)
    {
        printf("%d, ", a[i]);
    }
    printf("\n");
    return 0;
}