// Computing e using Bernoulli method

#include <stdio.h>
#include <math.h>


// Euler number to 18 decimal places
const double E = 2.718281828459046;

double euler(int n)
{
    double sum = 1.0;
    double i_factorial = 1.0;
    
    for (int i = 1; i <= n; i++)
    {
        // compute factorial of i
        i_factorial = i_factorial*i;
    
        sum += 1.0/i_factorial;
    }
    
    return sum;
}


int main()
{    
    // print header
    printf("%2s %20s %20s %20s\n", "n", "e_approx", "e", "error");
 
    for (int n = 0; n <= 20; n+=2)
    {
        double eapprox = euler(n);
        printf("%2d %20.15f %20.15f %20.15f\n", n, eapprox, E, fabs(E - eapprox));
    }
    
}
