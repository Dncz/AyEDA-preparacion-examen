// SE PIDE CREAR UNA FUNCIÓN QUE ORDENE UN ARRAY
// DONDE LA PRIMERA ITERACIÓN USARÁ QUICKSORT
// Y EL RESTO USARÁ INSERTION SORT
// 
// EXPLICACIÓN: la idea es calcular el pivote con quicksort
// y luego ordenar desde 0 hasta el pivote con insertion sort
// y desde el pivote hasta el final con insertion sort
// la ordenación es por la derecha y por la izquierda...
//
// según copilot:
// EXPLICACIÓN: https://www.youtube.com/watch?v=COk73cpQbFQ
// EXPLICACIÓN: https://www.youtube.com/watch?v=ROalU379l3U
// EXPLICACIÓN: https://www.youtube.com/watch?v=JU767SDMDvA
// 

#include <iostream>
#include <vector>

void orderByInsertionSort(std::vector<int> &v, int start, int end) {
  for (int i = start + 1; i < end; i++) {
    int key = v[i];
    int j = i - 1;
    while (j >= start && v[j] > key) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = key;
  }
}


void orderByQuickSort(std::vector<int> &v, int ini, int end) {

  int i = ini;
  int f = end;
  int p = v[(i + f) / 2] ;
  // std::cout << "Valores\n i (ini) = " 
  //           << i << std::endl
  //           << "f (end) = " << f << std::endl
  //           << "p (v[(i + f) / 2]) = " << p << std::endl;
  while (i <= f) {
  // std::cout << "Mientras que i <= f" << std::endl
  //           << "i = " << i << ", f = " << f << std::endl;
    while (v[i] < p) {
      // std::cout << "Mientras que v[i] < p" << std::endl
      //       << "v[i] = " << v[i] << ", p = " << p << std::endl;
      i++;
      // std::cout << "se incrementa i: " << i << std::endl;
    }
    while (v[f] > p) {
      // std::cout << "Mientras que v[f] > p" << std::endl
      //       << "v[f] = " << v[f] << ", p = " << p << std::endl;
      f--;
      // std::cout << "se descrementa f: " << f << std::endl;
    }
    if (i <= f) {
      // std::cout << "si i = " << i << ", f = " << f << std::endl;
      // std::cout << "Se intercambia v[i] = " << v[i] << " con v[f]" << v[f] << std::endl;
      std::swap(v[i], v[f]);
      i++; 
      f--;
    }
  }
  // if (ini < f) orderByQuickSort(v, ini, f);
  // if (i < end) orderByQuickSort(v, i, end);
}

int main () {
  std::cout << "Ejercicio de polimorfismo - examen Mayo 22-23\n";
  // elementos desordenados
  // std::vector<int> v = { 1, 6, 2, 4, 7, 5, 3};
  std::vector<int> v = {3, 4,	1, 8, 9, 7, 10, 2, 5, 6};
  
  // primera iteración con quicksort
  int pivote = v[v.size() / 2];
  std::cout << "pivote = " << pivote << std::endl;
  // primero tengo que hacer el algoritmo de quicksort
  // para que así tenga los valores a la izq del pivote
  // menores que el pivote y los de la derecha mayores que el pivote
  // y luego ordenar con insertion sort
  //
  orderByQuickSort(v, 0, v.size() - 1);
  for (auto i : v) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  // primer subvector con insertion sort
  orderByInsertionSort(v, 0, pivote);
  // segundo subvector con insertion sort
  orderByInsertionSort(v, pivote, v.size());

  for (auto i : v) {
    std::cout << i << " ";
  }

}