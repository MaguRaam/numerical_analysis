#include <stdio.h>
#include <math.h>

// Forward difference of a function
double forward_diff(double (*f)(double), double x, double h)
{
    return (f(x + h) - f(x))/h;
}


int main()
{
    double x = 1.0;
    double h = 1.0;

    printf("%s %20s %20s %20s %20s\n", "h", "Numerical Derivative",
        "Analytical Derivative", "Error", "Error Estimate");

    for (int i = 1; i < 20; i++)
    {
        h *= 0.1;
        double numerical_derivative = forward_diff(exp, x, h);
        double analytical_derivative = exp(x);
        double error = fabs(numerical_derivative - analytical_derivative);
        double error_estimate = fabs(0.5*(exp(x + h)*h));

        printf("%e %20.16f %20.16f %20.16f %20.16f\n", h, numerical_derivative,
            analytical_derivative, error, error_estimate);
    }
}