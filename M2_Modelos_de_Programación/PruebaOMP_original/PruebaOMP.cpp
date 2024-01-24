#include <iostream>
#include <omp.h>

#define N 1000
#define chunk 500
#define mostrar 50

void imprimeArreglo(float* d);


int main()
{
    std::cout << "Sumando Arreglos en Paralelo!\n";
    float a[N], b[N], c[N];
    int i;

    for (int i = 0; i < N; i++)
    {
        a[i] = (i + 25) * 48.6; // i * 10;
        b[i] = (i + 77) * 150.7; // (i + 3) * 3.7;
    }

    int pedazos = chunk;

#pragma omp parallel for \
    shared(a, b, c, pedazos) private(i) \
    schedule(static, pedazos)
    for (int i = 0; i < N; i++)
        c[i] = a[i] + b[i];


    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
    imprimeArreglo(a);

    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
    imprimeArreglo(b);

    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl;
    imprimeArreglo(c);

    return 0;
}

void imprimeArreglo(float* d)
{
    for (int x = 0; x < mostrar; x++)
        std::cout << d[x] << " - ";
    std::cout << std::endl;
}