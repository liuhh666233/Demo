#include <stdio.h>

void inplace_swap(int *x, int *y)
{
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

void reverse_array(int a[], int cnt)
{
    int first, last;
    for (first = 0, last = cnt - 1; first < last; first++, last--)
    {
        printf("Input: %d - %d\n", a[first], a[last]);
        inplace_swap(&a[first], &a[last]);
        printf("Output: %d - %d\n", a[first], a[last]);
    }
}
int main()
{
    int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    reverse_array(a, 9);
    for (int i = 0; i < 9; i++)
    {
        printf("%d", a[i]);
    }
} 