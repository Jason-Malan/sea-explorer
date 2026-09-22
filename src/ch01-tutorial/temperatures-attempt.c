// #include <stdio.h>

// int main()
// {
//     float fahr, celsius;
//     float lower, upper, step;

//     lower = 0;
//     upper = 300;
//     step = 20;

//     fahr = lower;
//     while (fahr <= upper)
//     {
//         celsius = (5.0 / 9.0) * (fahr - 32.0);
//         printf("%3.0f %6.1f\n", fahr, celsius);
//         fahr = fahr + step;
//     }

//     return 1;
// }

#include <stdio.h>

#define UPPER 300
#define LOWER 0
#define STEP 20

int main()
{
    // float fahr, celsius;
    // float lower, upper, step;

    // lower = 0;
    // upper = 300;
    // step = 20;

    // fahr = lower;
    // while (fahr <= upper)
    // {
    //     celsius = (5.0 / 9.0) * (fahr - 32.0);
    //     printf("%3.0f %6.1f\n", fahr, celsius);
    //     fahr = fahr + step;
    // }

    int fahr;

    for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP)
    {
        printf("%3d %6.1f \n", fahr, ((5.0 / 9.0) * (fahr - 32.0)));
    }

    return 1;
}