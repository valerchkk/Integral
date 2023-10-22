double Integral(double (*function) (double), double start, double stop, double step)
{
    double result = function(start) + function(stop);
    for (double i = start + step; i < stop; i += step)
    {
        result += 2 * function(i);
    }
    return result * step / 2;
}