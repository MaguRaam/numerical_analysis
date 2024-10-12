#include <stdio.h>
#include <math.h>
#include <time.h> 


// compute pi using Gregory series
double compute_pi(int N)
{
    double sum = 0.0;
    
    // compute partial sums
    for (int k = 1; k <= N; ++k)
    {
        sum += pow(-1, k - 1)/(2.0*k - 1.0);
    }
    
    return 4.0*sum;
}

int main()
{
    clock_t start = clock();

    // print pi to 16 decimal places
    printf("%.16f\n", compute_pi(1000));

    clock_t end = clock();

    // compute and print time spent    
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_spent);
}
