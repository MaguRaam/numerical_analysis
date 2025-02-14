//Compute sqrt using the Babylonian method

#include <stdio.h>
#include <math.h>

double update(double x)
{
    return 0.5*(x + 2.0/x);
}

int main()
{
    // initial guess
    double x0 = 1.5;
    
    // no of iteration
    int niter = 10;
    
    // sqrt(2.0)
    double sqrt2 = sqrt(2.0);
    
    for (int iter = 1; iter < niter; iter++)
    {
        x0 = update(x0);
        printf("%.16f %.16f %.16f\n", sqrt2, x0, fabs(sqrt2 - x0));
    }
    
}
