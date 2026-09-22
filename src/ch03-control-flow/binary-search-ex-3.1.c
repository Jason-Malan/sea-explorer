#include <stdio.h>
#include <time.h>

#define REPEATS 10000000

int binary_search(int x, int v[], int n);

int main(void)
{
    int values[] = {1, 10, 20, 30, 40, 50};
    int n = sizeof values / sizeof values[0];
    volatile int result = 0;

    clock_t start = clock();

    for (int i = 0; i < REPEATS; ++i)
        result += binary_search(i % 60, values, n);

    clock_t end = clock();

    printf("Result: %d\n", result);
    printf("Time: %.6f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);
}

int binary_search(int x, int v[], int n) 
{
    int low, mid, high;
    low = 0;
    high = n - 1;

    while (low < high)
    {
        mid = (low + high) / 2;
        if (x < v[mid])
        {
            high = mid - 1;
        } 
        else 
        {
            low = mid + 1;
        }
    }

    return v[low] == x ? low : -1;
}