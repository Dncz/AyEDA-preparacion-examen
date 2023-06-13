// Escribe un procedimiento en C++ que ordene la primera mitad de la secuencia o
// vector por el método de selección de menor a mayor, luego ordene la segunda mitad
// también por el método de inserción, pero de mayor a menor, y finalmente mezcle
// ambas mitades de forma que el vector quede ordenado de mayor a menor ordenada.

#include <iostream>
#include <vector>

// ordenado de menor a mayor
void orderBySleccion(std::vector<int> &v, int end) {
  int min = 0;
  // int aux;
  for (unsigned i = 0; i < v.size(); i++) {
    min = i;
    for (int j = i + 1; j < end; j++) {
      // de menor a mayor: v[j] < v[min]
      if (v[j] < v[min]) {
        min = j;
      }
    }
    std::swap(v[i], v[min]);
  }

}

// ordenado de mayor a menor
void orderByInsercion(std::vector<int> &v, int start, int end) {
  for (int i = start + 1; i < end; i++) {
    int key = v[i];
    int j = i - 1;
    // ordenar de mayor a menor: v[j] < key
    // ordenar de menor a mayor: v[j] > key
    while (j >=start && v[j] < key) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = key;
  }
}

// mezcla que ordena de mayor a menor
void mezcla(std::vector<int> &v, int cen) {
  // i va desde el centro hasta 0
  int i = cen;
  // j va desde el centro + 1 hasta el final
  int j = cen + 1;
  int k = 0;
  std::vector<int> aux(v.size() + 1);

  // se compara el elemento de la izquierda con el de la derecha
  while ( i >=0 && j <= v.size()) {
    // se copia el mayor en el vector auxiliar
    if (v[i] > v[j]) {
      // std::cout << "si: v[i] = " << v[i] << " > v[j] = " << v[j] << std::endl;
      // si el elemento de la primera mitad es mayor que el de la segunda
      aux[k] = v[i];
      i--;
    } else {
      // std::cout << "else: v[i] = " << v[i] << " < v[j] = " << v[j] << std::endl;
      // si el elemento de la segunda mitad es mayor que el de la primera mitad
      aux[k] = v[j];
      j++;
    }
    k++;
  }

  // std::cout << "Después del while: " << std::endl;
  // for (unsigned i = 0; i < aux.size(); i++) {
  //   std::cout << aux[i] << " ";
  // }
  // std::cout << std::endl;

  // se copia el resto de elementos
  // en este caso i < 0 porque i se descrementa en el while
  if (i < 0) {
    // se copia el resto de elementos de la segunda mitad
    while (j <= v.size()) {
      aux[k] = v[j];
      j++;
      k++;
    }
  } else {
    // se copia el resto de elementos de la primera mitad
    while (i <= cen) {
      aux[k] = v[i];
      i--;
      k++;
    }
  }

  // se copia el vector auxiliar en el vector original
  for (unsigned i = 0; i < v.size(); i++) {
    v[i] = aux[i];
  }
  
}

int main() {

  std::vector<int> v = {4, 7, 6, 5, 3, 8, 9, 10, 1, 2};
  // método de seleccion (menor a mayor)
  orderBySleccion(v, v.size() / 2);
  std::cout << "Primera mitrad ordenada: " << std::endl;
  for (unsigned i = 0; i < v.size()/2; i++) {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;

  // método de inserción (mayor a menor)
  orderByInsercion(v, v.size()/2, v.size());
  std::cout << "Segunda mitad ordenada: " << std::endl;
  for (unsigned i = v.size()/2; i < v.size(); i++) {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;

  std::cout << "vector con las dos mitades ordenadas: " << std::endl;
  for (unsigned i = 0; i < v.size(); i++) {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;

  // mezclar ambas mitades
  mezcla(v, (v.size()/2)-1);
  std::cout << "Vector mezclado: " << std::endl;
  for (unsigned i = 0; i < v.size(); i++) {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;
  
}