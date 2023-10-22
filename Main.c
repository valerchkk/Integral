#include <stdio.h>
#include "Integral.h"
#include <math.h>

typedef struct
{
    double (*function)(double);
    char *description;
} Function;

int main(int argc, char *argv[])
{

    Function Array[10] = {
        {sin, "Sine"},
        {cos, "Cosine"},
        {tan, "Tangens"},
        {sinh, "Hiperbolic sine"},
        {cosh, "Hiperbolic cosine"},
        {tanh, "Hiperbolic tangens"},
        {exp, "Exponential function with base e"},
        {sqrt, "Square root"},
        {log10, "Decimal logariphm"},
        {log, "Natural logariphm"},
    };

    printf("%s", "Function integration program\nChoose function:\n");

    for (char i = 0; i < 10; i++)
    {
        printf("%d: %s\n", i, Array[i].description);
    }

    int input;
    double start, stop, step;

    printf("%s", "Your choose: ");
    if (scanf("%d", &input) == 0)
    {
        printf("%s", "Incorrect input\n");
        return 0;
    }
    else if ((input < 0) || (input > 9))
    {
        printf("%s", "Incorrect input\n");
        return 0;
    }
    printf("%s", "Input start, stop & step.\nStart: ");
    if (scanf("%lf", &start) == 0)
    {
        printf("%s", "Incorrect input\n");
        return 0;
    }
    printf("%s", "Stop: ");
    if (scanf("%lf", &stop) == 0)
    {
        printf("%s", "Incorrect input\n");
        return 0;
    }
    else if (stop < start)
    {
        printf("%s", "Incorrect input\n");
        return 0;
    }
    printf("%s", "Step: ");
    if (scanf("%lf", &step) == 0)
    {
        printf("%s", "Incorrect input\n");
        return 0;
    }
    else if (step == 0)
    {
        printf("%s", "Incorrect input\n");
        return 0;
    }
    printf("%s%lf\n", "Result: ", Integral(Array[input].function, start, stop, step));

    return 0;
}