// Approximate a function using Taylor polynomials

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// linspace function
void linspace(double xmin, double xmax, int N, double* x)
{
    // compute step size
    const double h = (xmax - xmin)/(N - 1);
   
    // compute grid points
    for (int i = 0; i < N; ++i)
    {
        x[i] = xmin + i*h;    
    }  
}

double taylor_polynomial_exp(double x, int degree) 
{
 
    // Initialize the polynomial result to 1 (the constant term)
    double result = 1.0;

    // Compute the polynomial in reverse order using Horner's rule
    for (int i = degree; i > 0; i--) 
    {
        result = 1.0 + x * result / i;
    }

    return result;
}


int main()
{
    // no of data points
    const int N = 10;
    const double xmin = 0.0, xmax = 1.0;
   
    // allocate memory for x, y, yapprox
    double* x = malloc(N * sizeof(double));
    double* y = malloc(N * sizeof(double));
    double* yapprox = malloc(N * sizeof(double));

    // create grid points
    linspace(xmin, xmax, N, x);
    
    // compute and store exp function and Taylor polynomial 
    for (int i = 0; i < N; ++i)
    {
        y[i] = exp(x[i]);
        yapprox[i] = taylor_polynomial_exp(x[i], 15);
    }
    
    // open a file
    FILE* f = fopen("data.txt", "w");
    
    // write x and y data
    for (int i = 0; i < N; ++i)
    {
        fprintf(f, "%.16f %.16f %.16f %.16f\n", x[i], y[i], yapprox[i], fabs(y[i] - yapprox[i]));  
    } 
    
    
   
    // release memory
    free(x);
    free(y);
    free(yapprox);
    fclose(f);
}


