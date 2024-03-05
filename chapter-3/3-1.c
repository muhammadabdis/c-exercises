/*
 * Exercise 3-1. Our binary search makes two tests inside the loop, when one
 * would suffice (at the price of more tests outside). Write a version with only one
 * test inside the loop and measure the difference in run-time
 */

#include <stdio.h>

int binsearch(int x, int v[], int n);

int main()
{
    int arr[] = {4, 5, 6, 7, 8};
    int i = binsearch(8, arr, 5);

    printf("found index: %d\n", i);
    return 0;
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x > v[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return x == v[low] ? low : -1;
}
