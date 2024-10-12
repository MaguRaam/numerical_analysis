// compute riemann sum

#include <stdio.h>
#include <math.h>

// function pointer
typedef double(*func)(double);


// gaussian function
double gaussian(double x) 
{
    return (1.0 / sqrt(2 * M_PI)) * exp(-x * x / 2.0);
}

// compute riemann sum
double riemann_sum(func f, double a, double b, int n)
{
    double h = (b - a)/(double)n;
    double sum = 0.0;
    
    for (int i = 0; i <= n; i++)
    {
        double x = a + i*h;
        sum += f(x);
    }
    
    return sum*h;
}


int main()
{   
    // define domain and no of grid points
    double a = -2.0;
    double b = 2.0;
    int n = 100;

    // compute riemann sum of gaussian function
    double sum = riemann_sum(gaussian, a, b, n);

    printf("riemann sum = %.16f\n", sum);
}
