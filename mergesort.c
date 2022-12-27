#include <stdio.h>
#include <stdlib.h>

#define N 8

/*
This implementation has a memory leak

int *merge(int *p, int m, int *q, int n, int *r, int o)
{
    if (!m)
    {
        int *x = malloc(sizeof(int) * (n + o));
        for (int i = 0; i < o; i++)
        {
            x[i] = r[i];
        }
        for (int i = 0; i < n; i++)
        {
            x[o + i] = q[i];
        }
        return x;
    }
    if (!n)
    {
        int *x = malloc(sizeof(int) * (m + o));
        for (int i = 0; i < o; i++)
        {
            x[i] = r[i];
        }
        for (int i = 0; i < m; i++)
        {
            x[o + i] = p[i];
        }
        return x;
    }
    if (p[0] < q[0])
    {
        int x[o + 1];
        for (int i = 0; i < o; i++)
        {
            x[i] = r[i];
        }
        x[o] = p[0];
        return merge(p + 1, m - 1, q, n, x, o + 1);
    }
    int x[o + 1];
    for (int i = 0; i < o; i++)
    {
        x[i] = r[i];
    }
    x[o] = q[0];
    return merge(p, m, q + 1, n - 1, x, o + 1);
}

int *merge_sort(int *x, int n)
{
    if (n == 2)
    {
        if (x[0] < x[1])
        {
            return x;
        }
        else
        {
            int tmp = x[0];
            x[0] = x[1];
            x[1] = tmp;
            return x;
        }
    }
    else if (n == 1)
    {
        return x;
    }
    int m = (int)(n / 2);
    int *p = merge_sort(x, m);
    int *q = merge_sort(x + m, n - m);
    return merge(p, m, q, n - m, (int *)NULL, 0);
}
*/

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