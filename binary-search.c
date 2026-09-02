#include <stdio.h>

int binary_search(int x, int v[], int n);

int main()
{
    int input[] = {1,10,20,30,40,50};
    int result = binary_search(50, input, 6);
    printf("%d", result);
    return 0;
}

int binary_search(int x, int v[], int n) 
{
    int low, mid, high;
    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        printf("low: %d, mid: %d, high: %d \n", low, mid, high);
        if (x < v[mid])
        {
            // weird how my book says +1 here...
            high = mid - 1;
        } 
        else if (x > v[mid])
        {
            low = mid + 1;
        }
        else 
        {
            return mid;
        }
    }

    return -1;
}