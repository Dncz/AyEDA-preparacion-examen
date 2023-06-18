
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

/////////////////////// FUNCIÓN DE QUICKSORT ///////////////////////
void quicksort(std::vector<int> &v, int ini, int fin) {
  int i = ini;
  int f = fin;
  int pivote = v[(i + f) / 2];

  while (i <= f) {
    // recorrido descendente
    while (v[i] < pivote) i++;
    // recorrido ascendente
    while (v[f] > pivote) f--;

    if (i <= f) {
      std::swap(v[i], v[f]);
      i++;
      f--;
    }
  }

  if (ini <= f) quicksort(v, ini, f);
  if (i < fin) quicksort(v, i, fin);
}

/////////////////////////////////////////////////////////////////////

/////////////////////// FUNCIÓN DE SHELLSORT ///////////////////////
void deltaMethod(std::vector<int> &v, int delta) {
  for (unsigned i = delta; i < v.size(); i++) {
    int key = v[i];
    unsigned j = i;
    while ( j >= delta && key < v[j - delta] ) {
      v[j] = v[j - delta];
      j = j - delta;
    }
    v[j] = key;
  }
}

void shellsort(std::vector<int> &v) {
  int delta = v.size();
  while (delta > 1) {
    delta = delta / 2;
    deltaMethod(v, delta);
  }
}
/////////////////////////////////////////////////////////////////////

/////////////////////// FUNCIÓN DE MEZCLA ///////////////////////
// mezcla de menor a mayor
void mezcla(std::vector<int> &v, unsigned cen) {
  unsigned i = 0;
  unsigned j = cen + 1;
  unsigned k = 0;

  std::vector<int> aux(v.size() + 1);

  while (i <= cen &&j <= v.size()) {
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
/////////////////////////////////////////////////////////////////////

int main(void) {

  std::vector<int> v = {4, 7, 6, 5, 3, 8, 9, 10, 1, 2};
  std::cout << "Centro: " << v[v.size() / 2 -1] << std::endl;

  seleccionSort(v, v.size() / 2);
  seleccionSort2(v, v.size() / 2);
  // seleccionSort3(v, v.size() / 2);
  // seleccionSort4(v, v.size() / 2);

  // insercion4(v, v.size() / 2);
  // quicksort(v, 0, v.size()- 1);
  // shellsort(v);
  mezcla(v, (v.size() / 2) - 1);

  for(auto i : v) {
    std::cout << i << " ";
  }

  std::cout << std::endl;

}