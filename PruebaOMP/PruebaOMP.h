#ifndef PRUEBA_OMP_H
#define PRUEBA_OMP_H

void imprimeArreglo(const std::vector<float>& d);
void sumaArreglosParalelo(const std::vector<float>& a, const std::vector<float>& b, std::vector<float>& c, int size, int chunk);
int numeroAleatorio(int min_num, int max_num);

#endif