// Escribe un procedimiento C++ que aplique el procedimiento de ordenación
// siguiente: se aplica una iteración del método Quicksort para dividir la
// secuencia en dos partes y se ordena, la primera parte (desde ini hasta f) por inserción y la
// segunda (desde i hasta end) por selección.

#include <iostream>
#include <vector>

// desde [0, f]
void orderByInsercion(std::vector<int> &v, int f) {
  // std::cout << "f = " << f << std::endl;
  // std::cout << "v[f] = " << v[f] << std::endl;
  // std::cout << "Vector a ordenar: " << std::endl;
  // for (unsigned i = 0; i <= f; i++) {
  //   std::cout << v[i] << " ";
  // }
  // std::cout << std::endl;
  // tenía un error, al final era que se debe de hacer (en este caso) i <= f
  for (int i = 1; i <= f; i++) {
    int key = v[i];
    int j = i -1;
    while (j >= 0 && key < v[j]) {
      v[j+1] = v[j];
      j--;
    }
    v[j +1] = key;
  }
}

// desde [i, v.size()-1]
void orderBySeleccion(std::vector<int> &v, int ini) {
  for (unsigned i = ini; i < v.size() -1 ; i++) {
    int min = i;
    for (unsigned j = i + 1; j < v.size(); j++) {
      if (v[j] < v[min]) {
        min = j;
      }
    }
    std::swap(v[i], v[min]);
  }
}

// ordenado de menor a mayor
void orderByQuicksort(std::vector<int> &v) {
  // algoritmo Quicksort
  int i = 0;
  int f = v.size() - 1;
  int pivote = v[(i + f) / 2];
  std::cout << "pivote = " << pivote << std::endl;

  while(i <= f) {
    while (v[i] < pivote) i++;
    while (v[f] > pivote) f--;
    if ( i <= f) {
      std::swap(v[i], v[f]);
      i++;
      f--;
    }
  }

  std::cout << "i = " << i << ", f = " << f << std::endl;

  std::cout << "Vector ordenado por quicksort: ";
  for (unsigned i = 0; i < v.size(); i++) {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;

  if (0 <= f) {
    orderByInsercion(v, f);
    std::cout << "Vector ordenado por inserción (primera parte): ";
    for (unsigned i = 0; i < v.size(); i++) {
      std::cout << v[i] << " ";
    }
    std::cout << std::endl;
  }

  if (i < v.size()) {
    orderBySeleccion(v, i);
    std::cout << "Vector ordenado por seleccion (segunda parte): ";
    for (unsigned i = 0; i < v.size(); i++) {
      std::cout << v[i] << " ";
    }
    std::cout << std::endl;
  }
}


int main(void) {
  std::vector<int> v = {3, 4,	1, 8, 9, 7, 10, 2, 5, 6};

  orderByQuicksort(v);

  std::cout << "Vector ordenado final: ";
  for (unsigned i = 0; i < v.size(); i++) {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;



}