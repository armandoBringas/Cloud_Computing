#include <iostream>
#include <omp.h>
#include "PruebaOMP.h"

#define N 1000
#define CHUNK_SIZE 100
#define MOSTRAR 10


int main()
{
    std::cout << "Sumando Arreglos en Paralelo!\n";

    float a[N], b[N], c[N];

    for (int i = 0; i < N; i++)
    {
        a[i] = i * 10;
        b[i] = (i + 3) * 3.7;
    }

    sumaArreglosParalelo(a, b, c, N, CHUNK_SIZE);

    std::cout << "Imprimiendo los primeros " << MOSTRAR << " valores del arreglo a: " << std::endl;
    imprimeArreglo(a);

    std::cout << "Imprimiendo los primeros " << MOSTRAR << " valores del arreglo b: " << std::endl;
    imprimeArreglo(b);

    std::cout << "Imprimiendo los primeros " << MOSTRAR << " valores del arreglo c: " << std::endl;
    imprimeArreglo(c);

    return 0;
}

void imprimeArreglo(float* d)
{
    for (int x = 0; x < MOSTRAR; x++)
        std::cout << d[x] << " - ";
    std::cout << std::endl;
}

void sumaArreglosParalelo(float* a, float* b, float* c, int size, int chunk)
{
    int i = 0;

    #pragma omp parallel for \
    shared(a, b, c, size) private(i) \
    schedule(static, chunk)
    for (int i = 0; i < size; i++)
        c[i] = a[i] + b[i];
}
