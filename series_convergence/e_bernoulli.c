// Computing e using Bernoulli method

#include <stdio.h>
#include <math.h>


// Euler number to 18 decimal places
const double E = 2.718281828459045;

double bernoulli(const double n)
{
    return pow((1.0 + 1.0/n), n);
}

    
int main() 
{
    // Define the range of n values as powers of 10 with step of 2 in exponent
    double n_values[] = {1e0, 1e2, 1e4, 1e6, 1e8, 1e10, 1e12, 1e14, 1e16, 1e18};
    int length = sizeof(n_values) / sizeof(n_values[0]);
    
    // Compute and display results in the desired format
    printf("%5s %20s %20s\n", "n", "(1+1/n)^n", "error");
    for (int i = 0; i < length; i++) 
    {
        double n = n_values[i];
        double eapprox = bernoulli(n);
        printf("%5.0e %20.15f %20.15f\n", n, eapprox, fabs(E - eapprox));
    }

    return 0;
}
