// Escribe un procedimiento en C++ que ordene de menor a mayor por el
// método de ordenación por inserción los elementos de las posiciones impares
// entre sí, y luego ordene de mayor a menor por el método de ordenación por
// selección los elementos de las posiciones pares, y finalmente mezcle ambas
// partes

#include <iostream>
#include <vector>

// ordenado de menor a mayor
// posiciones impares
void orderByInsercion(std::vector<int> &v) {
  for(unsigned i = 1; i < v.size(); i+=2) {
    int key = v[i];
    int j = i;
    while (j > 1 && v[j - 2] > key) {
      v[j] = v[j - 2];
      j-=2;
    }
    v[j] = key;
  }
}

// odeando de mayor a menor
// posiciones pares
void orderBySeleccion(std::vector<int> &v) {
  for (unsigned i = 0; i < v.size(); i+=2) {
    unsigned min = i;
    for (unsigned j = i +2; j < v.size(); j +=2) {
      // de mayor a menor: v[j] > v[min]
      if (v[j] > v[min]) {
        min = j;
      }
    }
    std::swap(v[i], v[min]);
  }
}

// mezcla que ordena de menor a mayor
void mezcla(std::vector<int> &v) {
  int i = 0; // para las posiciónes pares
  if (v.size() % 2 == 0) i = v.size() - 2; // si el tamaño del vector es par
  // si el tamaño del vector es impar (para que no se salga del vector en la siguiente iteración)
  else i = v.size() - 1;

  int j = 1; // para las posiciones impares
  int k = 0;
  std::vector<int> aux(v.size() + 1);

  while( i >= 0 && j <= v.size()) {
    if (v[i] < v[j]) {
      aux[k] = v[i];
      i-=2;
    } else {
      aux[k] = v[j];
      j+=2;
    }
    k++;
  }

  if (i < 0) {
    while (j <= v.size()) {
      aux[k] = v[j];
      j+=2;
      k++;
    }
  } else {
    while (i >= 0) {
      aux[k] = v[i];
      i-=2;
      k++;
    }
  }

  for (unsigned i = 0; i < v.size(); i++) {
    v[i] = aux[i];
  }

}


int main() {
  std::vector<int> v = {9, 2, 10, 8, 4, 1, 5, 3, 6, 7};
  // valores en posiciones pares: 9, 10, 4, 5, 6
  // valores en posiciones impares: 2, 8, 1, 3, 7

  std::cout << "Vector ordenado de menor a mayor por inserción en posiciones impares" << std::endl;
  orderByInsercion(v);
  for (unsigned i = 0; i < v.size(); i++) {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;
  // resultado esperado: 9 1 10 2 4 3 5 7 6 8

  std::cout << "Vector ordenado de mayor a menor por selección en posiciones pares" << std::endl;
  orderBySeleccion(v);
  for (unsigned i = 0; i < v.size(); i++) {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;
  // resultado esperado:  10 1 9 2 6 3 5 7 4 8

  std::cout << "Vector ordenado de menor a mayor por mezcla" << std::endl;
  mezcla(v);
  for (unsigned i = 0; i < v.size(); i++) {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;
}