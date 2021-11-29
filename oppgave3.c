#include <stdlib.h>
#include <stdio.h>
#include <math.h>


void random_array(double *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        A[i] = rand()%1000;
        A[i] = (double)A[i];
    }
}


double gjennomsnitt(double *A, int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
    }

    return sum / n;
}

double standardavvik(double* A, int n)
{
    double sum = 0;
    double snitt = gjennomsnitt(A, n);
    
    for (int i = 0; i < 0; i++)
    {
        double mellom = A[i] - snitt;
        sum += mellom * mellom;
    }

    return sum;
    //return sqrt(sum) / 2;
}

void sorter(double* A, int n)
{
    double temp;
    int sorted = 0;

    while(!sorted)
    {   
        sorted = 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (A[i] > A[i+1])
            {
                sorted = 0;
                temp = A[i+1];
                A[i+1] = A[i];
                A[i] = temp;
            }
        }
    }
}

int main()
{
    int n = 1000;
    double *A = malloc(sizeof(double) * n);

    random_array(A, n);

    printf("gjennomsnitt: %f\n", gjennomsnitt(A, n));

    for (int i = 0; i < 20; i++)
    {
        printf("%d->", (int)A[i]);
    }
    printf("\n\n");
    sorter(A, n);

    for (int i = 0; i < 20; i++)
    {
        printf("%d->", (int)A[i]);
    }
    printf("\n");
}
