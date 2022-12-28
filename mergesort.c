#include <stdio.h>
#include <stdlib.h>

#define N 8

void merge_sort(int *x, int start, int end)
{
    if ((end - start) > 1)
    {
        int m = (int)((start + end) / 2);
        merge_sort(x, start, m);
        merge_sort(x, m, end);

        int len = end - start;
        int y[len];
        int p = 0;
        int left = start;
        int right = m;

        while ((left < m) && (right < end))
        {
            if (x[left] < x[right])
            {
                y[p++] = x[left++];
            }
            else
            {
                y[p++] = x[right++];
            }
        }
        while (left < m)
        {
            y[p++] = x[left++];
        }
        while (right < end)
        {
            y[p++] = x[right++];
        }
        for (int i = 0; i < len; i++)
        {
            x[start + i] = y[i];
        }
    }
}

int main()
{
    int a[] = {1, 3, 2, 4, 6, 7, 5, 8};
    merge_sort(a, 0, N);
    for (int i = 0; i < N; i++)
    {
        printf("%d, ", a[i]);
    }
    printf("\n");
    return 0;
}