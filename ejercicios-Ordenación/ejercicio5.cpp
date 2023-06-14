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

