
# Ordenación por inserción

```cpp
template<class Key>
void orderByInsertionSort(std::vector<Key> &v, int size) {
  // std::cout << BLUE << "Vector original - orderByInsertionSort( " << RESET; printVector(v); std::cout << ", size= " << size << ") " << std::endl;
  int i, j;
  int aux;
  for (i = 1; i < size; ++i) {
    aux = v[i];
    j = i - 1;
    while (j >= 0 && aux < v[j]) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = aux;
    // std::cout << "i= " << i << std::endl;
    // printVector(v); std::cout << std::endl;
  }
  // std::cout << CYAN << "Vector ordenado: " << RESET; printVector(v) ; std::cout << std::endl;
}

orderByInsertionSort(this->sequence_vector, this->size_abs);
```

# ordenación por selección (año 21-22)
```cpp
template<class Key>
void orderBySelection(std::vector<Key> &v, int size) {
  std::cout << "\n\tTRAZA" << std::endl;
  for (int i = 0; i < size - 1; i++) {
    std::cout << "Iteración: " << i << std::endl;
    int min = i;
    std::cout << "min = " << i << std::endl;
    Key x;
    for (int j = i + 1; j < size; j++) {
      if (v[j] < v[min]) {
        std::cout << "Si " << v[j] << " < " << v[min] << ", entonces min = " << j << std::endl;
        min = j;
      } else {
        std::cout << "Como " << v[j] << " >= " << v[min] << ", no se cambia" << std::endl;
      }
    }
    std::cout << "Se intercambia " << v[min] << "con " << v[i] << std::endl;
    x = v[min];
    v[min] = v[i];
    v[i] = x;
    std::cout << std::endl;
  }
}
```

# Ordenación por heapsort
```cpp
template<class Key>
void down(int i, std::vector<Key> &v, int size) {
  std::cout << "dow( it= " << i << ", "; printVector(v); std::cout << ", size= " << size << ") " << std::endl;
  int h;
  Key aux;
  while ( (2 * i) <= size ) {
    int h1 = 2 * i;
    int h2 = h1 + 1;
    if (h1 == size) {
      h = h1;
    } else if (v[h1] > v[h2]) {
      h = h1;
    } else {
      h = h2;
    }

    if (v[h] <= v[i]) {
      break;
    } else {
      aux = v[i];
      v[i] = v[h];
      v[h] = aux;
      i = h;
    }
  }
}

template <class Key>
void orderByHeapSort(std::vector<Key> &vector, int size) {
  std::cout << BLUE << "Vector original - orderByHeapSort( " << RESET; printVector(vector); std::cout << ", size= " << size << ") " << std::endl;
  std::cout << "\n\tTRAZA" << std::endl;
  Key aux;
  // instrucciones
  std::cout << "Instrucciones: " << std::endl;
  std::cout << "padre= " << size / 2 << std::endl;
  for (int i = (size -1) / 2; i >= 0; i--) {
    std::cout << "Iteración: " << i << std::endl;
    down(i, vector, size);
  }
  std::cout << std::endl;
  // extracciones
  std::cout << "Extracciones: " << std::endl;
  for (int i = size ; i >= 0; i--) {
    std::cout << "Iteración: " << i << std::endl;
    aux = vector[0];
    vector[0] = vector[i];
    vector[i] = aux;
    down(0, vector, i - 1);
  }
  std::cout << CYAN << "Vector ordenado: " << RESET; printVector(vector) ; std::cout << std::endl;
}

orderByHeapSort(this->sequence_, this->size_abs);
```

# ordenación por radixsort
```cpp
template<class Key>
void RorderByRadixSort(std::vector<Key> &vector, int size) {
  std::cout << BLUE << "Vector original - orderByRadixSort( " << RESET; printVector(vector); std::cout << ", size= " << size << ") " << std::endl;
  int digits = 0;
  for(int i = 1; kMinimunNumber / i > 0; i *= 10) {
    std::cout << "Dígito: " << digits << std::endl;
    digits++;
    std::vector<Key> aux(size);
    int count[10] = {0};
    for(int j = 0; j < size; j++) {
      int digit = (vector[j] / i) % 10;
      count[digit]++;
    }
    for(int j = 1; j < 10; j++) {
      count[j] += count[j - 1];
    }
    for(int j = size - 1; j >= 0; j--) {
      int digit = (vector[j] / i) % 10;
      aux[count[digit] - 1] = vector[j];
      count[digit]--;
    }
    for (int k = 0; k < size; k++) {
      vector[k] = aux[k];
    }
    std::cout << "vector: "; printVector(vector); std::cout << std::endl;
  }
  std::cout << CYAN << "Vector ordenado: " << RESET; printVector(vector); std::cout << std::endl;

}

orderByRadixSort(this->sequence_, this->size_abs);
```

# ordenación por mergesort
```cpp
template <class Key>
void mezcla(std::vector<Key> &v, int ini, int cen, int fin) {
  int i = ini;
  int j = cen + 1; 
  int k = ini;
  std::cout << "i= " << ini << ", j = " << j << ", k = " << k << std::endl;

  std::vector<Key> aux(fin + 1);
  while ((i <= cen) && (j <= fin)){
    if (v[i] < v[j]){

      aux[k] = v[i];
      i++;
    } else{
      aux[k] = v[j];
      j++;
    }
    k++;
  }
  if (i > cen) {
    while (j <= fin){
      aux[k] = v[j];
      j++; 
      k++;
    }
  } else {
    while (i <= cen) {
      aux[k] = v[i] ;
      i++; 
      k++;
    }
  }
  for (int k = ini; k <= fin; k++)
    v[k] = aux[k] ;

  std::cout << "(vector mezcla: "; printVector(v); std::cout << ")\n";
};

template <class Key>
void orderByMergeSort(std::vector<Key> &v, int ini, int fin) {
  if (ini < fin) {
    int cen = (ini + fin) / 2;
    std::cout << "cen= " << cen << std::endl;
    orderByMergeSort(v, ini, cen);
    orderByMergeSort(v, cen + 1, fin);
    mezcla(v, ini, cen, fin);
  };
  std::cout << CYAN << "Vector ordenado: " << RESET; printVector(v) ; std::cout << std::endl;
};

orderByMergeSort(this->sequence_, 0, this->size_abs - 1);
```

# ordenacion shellsort
```cpp
template<class Key>
void deltaSort(int delta, std::vector<Key> &v, int size) {
  for (int i = delta; i < size; i++) {
    std::cout << "Iteración: " << i << std::endl;
    Key x = v[i];
    std::cout << "x = v[i] = " << x << std::endl;
    int j = i ;
    std::cout << "j = " << i << std::endl;
    while ((j >= delta) && (x < v[j - delta])) {
      std::cout << "Mientras j >= delta y x < v[j - delta]" << std::endl;
      v[j] = v[j - delta];
      j = j - delta ;
      std::cout << "v[j] = " << v[j] << std::endl;
      std::cout << "j = " << j << std::endl;
    }
    v[j] = x ;
    std::cout << "Vector: "; printVector(v); std::cout << std::endl;
  }
}

template<class Key>
void orderByShellSort(std::vector<Key> &v, int size) {
  std::cout << BLUE << "Vector original - orderByShellSort( " << RESET; printVector(v); std::cout << ", size= " << size << ") " << std::endl;
  int delta = size;
  while (delta > 1) {
    delta = delta / 2 ;
    std::cout << "\n\tDelta = " << delta << std::endl;
    deltaSort(delta, v, size);
    std::cout << std::endl;
  }
  std::cout << CYAN << "Vector ordenado: " << RESET; printVector(v) ; std::cout << std::endl;
}

orderByShellSort(this->sequence_, this->size_abs);
```

# ordenación quicksort (año 21-22)
```cpp
template<class Key>
void orderByQuickSort(std::vector<Key> &v, int ini, int end) {
  int i = ini;
  int f = end;
  int p = v[(i + f) / 2] ;
  std::cout << "Valores\n i (ini) = " 
            << i << std::endl
            << "f (end) = " << f << std::endl
            << "p (v[(i + f) / 2]) = " << p << std::endl;
  while (i <= f) {
  std::cout << "Mientras que i <= f" << std::endl
            << "i = " << i << ", f = " << f << std::endl;
    while (v[i] < p) {
      std::cout << "Mientras que v[i] < p" << std::endl
            << "v[i] = " << v[i] << ", p = " << p << std::endl;
      i++;
      std::cout << "se incrementa i: " << i << std::endl;
    }
    while (v[f] > p) {
      std::cout << "Mientras que v[f] > p" << std::endl
            << "v[f] = " << v[f] << ", p = " << p << std::endl;
      f--;
      std::cout << "se descrementa f: " << f << std::endl;
    }
    if (i <= f) {
      std::cout << "si i = " << i << ", f = " << f << std::endl;
      std::cout << "Se intercambia v[i] = " << v[i] << " con v[f]" << v[f] << std::endl;
      std::swap(v[i], v[f]);
      i++; 
      f--;
    }
  }
   if (ini < f) orderByQuickSort(v, ini, f);
   if (i < end) orderByQuickSort(v, i, end);
}

orderByQuickSort(this->vSequence_, 0, (this->size_abs - 1));
```