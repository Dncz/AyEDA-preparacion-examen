
#include <iostream>
#include <vector>

/////////////////////// FUNCIÓN DE SELECCIÓN ////////////////////////
// función de seleccion de menor a mayor
// desde la primera mitad
void seleccionSort(std::vector<int> &v, unsigned cen) {
  for (unsigned i = 0; i < v.size(); i++) {
    int min = i;
    for (unsigned j = i + 1; j < cen; j++) {
      if (v[j] < v[min]) {
        min = j;
      }
    }
    std::swap(v[i], v[min]);
  }
}


// función de seleccion de menor a mayor
// desde la segunda mitad
void seleccionSort2(std::vector<int> &v, int cen) {
  for (unsigned i = cen; i < v.size(); i++) {
    int min = i;
    for (unsigned j = i + 1; j < v.size(); j++) {
      if (v[j] < v[min]) {
        min = j;
      }
    }
    std::swap(v[i], v[min]);
  }
}

// función de seleccion de mayor a menor
// desde la primera mitad
void seleccionSort3(std::vector<int> &v, unsigned cen) {
  for (unsigned i = 0; i < v.size(); i++) {
    int min = i;
    for (unsigned j = i + 1; j < cen; j++) {
      if (v[j] > v[min])
        min = j;
    }
    std::swap(v[i], v[min]);
  }
}


// función de seleccion de mayor a menor
// desde la segunda mitad
void seleccionSort4(std::vector<int> &v, int cen) {
  for (unsigned i = cen; i < v.size(); i++) {
    int min = i;
    for (unsigned j = i + 1; j < v.size(); j++) {
      if (v[j] > v[min])
        min = j;
    }
    std::swap(v[i], v[min]);
  }
}

/////////////////////////////////////////////////////////////////////

/////////////////////// FUNCIÓN DE iNSERCCIÓN ///////////////////////
// de menor a mayor
// primera parte
void insercion(std::vector<int> &v, unsigned cen) {
  for (unsigned i = 1; i < cen; i++) {
    int key = v[i];
    int j = i - 1;
    while (j >= 0 && v[j] > key) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = key;
  }
}

// de menor a mayor
// segunda parte
void insercion2(std::vector<int> &v, unsigned cen) {
  for (unsigned i = cen; i < v.size(); i++) {
    int key = v[i];
    unsigned j = i - 1;

    while (j >= cen && v[j] > key) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = key;
  }
}

// de mayor a menor
// primera parte
void insercion3(std::vector<int> &v, unsigned cen) {
  for(unsigned i = 0; i < cen; i++) {
    int key = v[i];
    int j = i - 1;
    while (j >= 0 && v[j] < key) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = key;
  }
}

// de mayor a menor
// segunda parte
void insercion4(std::vector<int> &v, unsigned cen) {
  for (unsigned i = cen; i < v.size(); i++) {
    int key = v[i];
    unsigned j = i - 1;
    
    while (j >= cen && v[j] < key) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = key;
  }
}

/////////////////////////////////////////////////////////////////////

// quicksort, merge, mezcla de merge, shellsort

int main(void) {

  std::vector<int> v = {4, 7, 6, 5, 3, 8, 9, 10, 1, 2};
  std::cout << "Centro: " << v[v.size() / 2 -1] << std::endl;

  // seleccionSort(v, v.size() / 2);
  // seleccionSort2(v, v.size() / 2);
  // seleccionSort3(v, v.size() / 2);
  // seleccionSort4(v, v.size() / 2);

  insercion4(v, v.size() / 2);

  for(auto i : v) {
    std::cout << i << " ";
  }

  std::cout << std::endl;

}