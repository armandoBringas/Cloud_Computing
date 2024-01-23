#include <iostream>
#include <omp.h>
#include <stdio.h>
#include <vector>
#include "PruebaOMP.h"

#define USE_RANDOM_VALUES // Comentar para usar valores predefinidos

#ifdef USE_RANDOM_VALUES
const int N = numeroAleatorio(100, 1000);
const int CHUNK_SIZE = numeroAleatorio(10, 100);
const int MOSTRAR = numeroAleatorio(5, 20);
#else
const int N = 1000;
const int CHUNK_SIZE = 100;
const int MOSTRAR = 10;
#endif

int main()
{
    std::cout << "Sumando Arreglos en Paralelo!\n";
    std::cout << std::endl;
    std::cout << "N = " << N << std::endl;
    std::cout << "CHUNK_SIZE = " << CHUNK_SIZE << std::endl;
    std::cout << "MOSTRAR = " << MOSTRAR << std::endl;
    std::cout << std::endl;

    std::vector<float> a(N), b(N), c(N);

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

void imprimeArreglo(const std::vector<float>& d)
{
    for (int x = 0; x < MOSTRAR && x < d.size(); x++)
        std::cout << d[x] << " - ";

    std::cout << std::endl;
    std::cout << std::endl;
}

void sumaArreglosParalelo(const std::vector<float>& a, const std::vector<float>& b, std::vector<float>& c, int n, int chunk)
{
#pragma omp parallel for \
    shared(a, b, c, chunk) \
    schedule(static, chunk)
    for (int i = 0; i < n; i++)
        c[i] = a[i] + b[i];
}

int numeroAleatorio(int min_num, int max_num)
{
    // Ensure a valid range
    if (min_num >= max_num) {
        std::swap(min_num, max_num);
    }

    static bool seed_initialized = false;
    if (!seed_initialized) {
        srand(static_cast<unsigned>(time(nullptr)));
        seed_initialized = true;
    }

    return rand() % (max_num - min_num + 1) + min_num;
}
