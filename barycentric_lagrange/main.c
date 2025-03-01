// Barycentric lagrange interpolation of Runge function

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// linspace function
void linspace(double xmin, double xmax, double *x, int N)
{
    // compute step size
    const double h = (xmax - xmin) / (N - 1);

    // compute grid points
    for (int i = 0; i < N; ++i)
    {
        x[i] = xmin + i * h;
    }
}

// Evaluate given function at grid points
void evaluate_function(double (*f)(double), const double *x, double *y, int N)
{
    for (int i = 0; i < N; ++i)
        y[i] = f(x[i]);
}

// Compute Barycentric weights
void compute_barycentric_weights(const double *x, double *w, int N)
{
    for (int i = 0; i < N; ++i)
    {
        double denominator = 1.0;
        for (int j = 0; j < i; ++j)
        {
            denominator *= x[i] - x[j];
        }
        for (int j = i + 1; j < N; ++j)
        {
            denominator *= x[i] - x[j];
        }
        w[i] = 1.0 / denominator;
    }
}

// Lagrange interpolation using Barycentric formula
double interpolate_barycentric_lagrange(const double *x, const double *y, const double *w, int N, double x_eval)
{
    // TODO Handle the case when x[i] == xval, the code will fail!

    double numerator = 0.0;
    double denominator = 0.0;

    for (int i = 0; i < N; ++i)
    {
        double coeff = w[i] / (x_eval - x[i]);
        numerator += coeff * y[i];
        denominator += coeff;
    }

    return numerator/denominator;
}

// Runge function
double runge_function(double x)
{
    return 1.0 / (1.0 + x * x);
}

// Unit function
double unit_function(double x)
{
    return 1.0;
}

int main()
{
    // No of grid points/ degree of polynomial and interpolation points
    const int N = 20;
    const int N_interp = 1000;

    // Create equally spaced grid points
    const double xmin = -5.0, xmax = 5.0;
    double *x = malloc(N * sizeof(double));
    linspace(xmin, xmax, x, N);

    // Compute function values at grid points
    double *y = malloc(N * sizeof(double));
    evaluate_function(runge_function, x, y, N);

    // Compute barycentric weights
    double *w = malloc(N * sizeof(double));
    compute_barycentric_weights(x, w, N);

    // Create Interpolation grid points
    double *x_interp = malloc(N_interp * sizeof(double));
    linspace(xmin - 0.01, xmax + 0.01, x_interp, N_interp);

    // Interpolate using Barycentric Lagrange
    double *y_interp = malloc(N_interp * sizeof(double));
    for (int i = 0; i < N_interp; ++i)
        y_interp[i] = interpolate_barycentric_lagrange(x, y, w, N, x_interp[i]);

    // Write interpolated data to file
    FILE* file = fopen("data.txt", "w");
    
    // write x and y data
    for (int i = 0; i < N_interp; ++i)
        fprintf(file, "%24.16f %24.16f %24.16f %24.16f \n", x_interp[i], y_interp[i], runge_function(x_interp[i]), fabs(y_interp[i] - runge_function(x_interp[i])));

    // release memory
    free(x);
    free(y);
    free(w);
    free(x_interp);
    free(y_interp);
}