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
