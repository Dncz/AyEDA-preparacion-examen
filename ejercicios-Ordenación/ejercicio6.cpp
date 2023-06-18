// Implementa un programa en C++ que 
// utilice el algoritmo de ordenación por Inserción para ordenar la primera mitad del vector
// y el algoritmo de ordenación por Selección para ordenar la segunda mitad del vector

#include <iostream>
#include <vector>

void insertion(std::vector<int> &v, int end) {
  for (int i = 1; i <= end; i++) {
    int key = v[i];
    int j = i - 1;
    // de menor a mayor
    while (j >= 0 && v[j] > key) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = key;
  }
}

void selection(std::vector<int> &v, int ini) {
  std::cout << "ini: " << ini << std::endl;
  // de menor a mayor
  for (unsigned int i = ini; i < v.size(); i++) {
    int min = i;
    for (unsigned int j = i + 1; j < v.size(); j++) {
      if (v[j] < v[min]) {
        min = j;
      }
    }
    std::swap(v[i], v[min]);
  }
}

// mezcla en ambos partes de menor a mayor
void mezcla(std::vector<int> &v, unsigned cen) {
  unsigned i = 0;
  unsigned j = cen + 1;
  unsigned k = 0;

  std::vector<int> aux(v.size() + 1);

  while (i <= cen && j <= v.size()) {
    if (v[i] < v[j]) {
      aux[k] = v[i];
      i++;
    } else {
      aux[k] = v[j];
      j++;
    }
    k++;
  }

  if (i > cen) {
    while (j <= v.size()) {
      aux[k] = v[j];
      j++;
      k++;
    }
  } else {
    while (i <= cen) {
      aux[k] = v[i];
      i++;
      k++;
    }
  }

  for (unsigned i = 0; i < v.size(); i++) {
    v[i] = aux[i];
  }

}


int main(void) {

  std::vector<int> v = {4, 7, 6, 5, 3, 8, 9, 10, 1, 2};
  int center = v.size() / 2;
  std::cout << "center: " << center << std::endl;
  // primera mitad con inserccion
  insertion(v, center - 1);
  std::cout << "Vector después de insercción: " << std::endl;
  for (auto i : v) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  // segunda mita con selccion
  selection(v, center);
  std::cout << "Vector después de selección: " << std::endl; 
  for (auto i : v) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  // FALTA MEZCLAR LAS DOS MITADES
  mezcla(v, (v.size() / 2) - 1);

  std::cout << "Vector mezclado:" << std::endl;
  for(auto i : v) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  return 0;
}