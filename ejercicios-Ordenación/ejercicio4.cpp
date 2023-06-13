// Escribe un procedimiento C++ que aplique un procedimiento de ordenación
// que combine las ideas de los métodos de ordenación por inserción y
// Quicksort de la forma siguiente: en primer lugar se elige un pivote, entonces
// dos índices recorren la parte por ordenar en sentidos ascendente descendente,
// respectivamente. Si el recorrido ascendente encuentra un valor menor o igual
// que el pivote, lo inserta en orden por la izquierda pero si encuentra un valor
// mayor que el pivote se detiene. Si el recorrido descendente encuentra un valor
// mayor o igual que el pivote, lo inserta por la derecha pero si encuentra un valor
// menor que el pivote se detiene. Cuando ambos recorridos se detienen, se
// intercambian los elementos donde se han parado que se insertan en la parte
// correspondiente y se continúa el proceso hasta que ambos recorridos se
// encuentren.

#include <iostream>
#include <vector>

int main(void) {
  std::vector<int> v = {4, 7, 3, 10, 5, 1, 2, 6, 9, 8};

  int i = 0;
  int f = v.size() - 1;
  int pivote = v[(i + f) / 2];

  while (i <= f) {
    // recorrido ascendente
    while (v[i] <= pivote) {
      // code here
      // lo inserta en orden por la izquierda. pero, si encuentra un valor
      // mayor que el pivote, se detiene
      int key = v[i];
      int j = i - 1;
      while (j > 0 && v[j] > key) {
        v[j + 1] = v[j];
        j--;
      }
      v[j + 1] = key;
      i++;
    }

    // recorrido descendente
    while (v[f] >= pivote) {
      // code here
      // lo inserta por la derecha. pero, si encuentra un valor
      // menor que el pivote, se detiene
      int key = v[f];
      unsigned j = f + 1;
      while (j > v.size() && v[j] < key) {
        v[j + 1] = v[j];
        j--;
      }
      v[j + 1] = key;
      j--;;
    }
    if (i <= f) {
      std::swap(v[i], v[f]);
      // i++;
      // f--;
    }
  }

  std::cout << "Vector ordenado: " << std::endl;
  for (unsigned i = 0; i < v.size(); i++) {
    std::cout << v[i] << " ";
  }
  std::cout << std::endl;
  

}