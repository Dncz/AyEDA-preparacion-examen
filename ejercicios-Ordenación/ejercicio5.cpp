// Se pide ordenar un vector en el combine las ideas de los métodos de ordenación de quicksort
// y mergesort. Primero se calcula el pivote, luego, cuando se recorre de manera ascendente
// se usa el algoritmo de quicksort y cuando se recorre de manera descendente se usa el
// algoritmo de mergesort. Cuando ambos recorridos se detienen, se intercambian los
// elementos donde se han parado que se insertan en la parte correspondiente y se
// continúa el proceso hasta que ambos recorridos se encuentren.

// idea:
// se parte el vector en dos mitades: desde 0 hasta el pivote y desde el pivote hasta el final
// las partes de ordenan con merge sort de menor a mayor. luego, se unen las dos partes (usando mezcla)

#include <iostream>
#include <vector>

void mezcla(std::vector<int> &v, int ini, int cen, int fin) {
  int i = ini;
  int j = cen + 1; 
  int k = ini;
  // std::cout << "i= " << ini << ", j = " << j << ", k = " << k << std::endl;

  std::vector<int> aux(fin + 1);
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

};


void merge(std::vector<int>& v, int ini, int fin) {
  if (ini < fin) {
    int center = (ini + fin) / 2;
    merge(v, ini, center);
    merge(v, center +1, fin);
    mezcla(v, ini, center, fin);
  }
}


int main(void) {
  std::vector<int> v = {4, 7, 6, 5, 3, 8, 9, 10, 1, 2};
  unsigned i = 0;
  unsigned f = v.size() -1;
  int pivote = v[(i + f) /2];
  std::cout << "Pivote= " << pivote << std::endl;

  while (i <= f) {
    // recorrido ascendente
    while (v[i] < pivote) i++;
    // recorrido descendente
    while (v[f] > pivote) f--;

    if (i <= f) {
      std::swap(v[i], v[f]);
      i++;
      f--;
    }
  }

  std::cout << "Se aplica quicksort" << std::endl; 
  for (auto i : v) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  if (0 <= f) {
    std::cout << "Se aplica merge desde ini = 0, f = " << f << std::endl;
    merge(v, 0, f);
    for (auto i : v) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }

  if (i < v.size()) {
    std::cout << "Se aplica merge desde i = " << i << " , end = " << v.size() << std::endl;
    merge(v, i, v.size()-1);
    for (auto i : v) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
  
  return 0;
}