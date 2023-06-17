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

void mergeSort(std::vector<int>& v, int ini, int fin) {

}



int main(void) {
  std::vector<int> v = {4, 7, 6, 5, 3, 8, 9, 10, 1, 2};
  int i = 0;
  int f = v.size() -1;
  int pivote = v[(i + f) /2];
  std::cout << pivote << std::endl;



  
  return 0;
}