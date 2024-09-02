#include <iostream>
#include <chrono>
#include <fstream>
#include <cmath>
#include <sstream>
#include <stdio.h>
#include <algorithm>

#include "bubble.h"
#include "introsort.h"
#include "quicksort.h"
#include "mergesort.h"

using namespace std;

int main() {
  ifstream file("normal.txt");                // Lee los datos del dataset de elementos ordenados.
  // ifstream file("ordered.txt");            // Lee los datos del dataset de elementos ordenados. Descomentar para usar.
  // ifstream file("partially_ordered.txt");  // Lee los datos del dataset de elementos parcialmente ordenados. Descomentar para usar.

  string line;
  int k = 0;
  int rowIndex = 0;

  /* 
    Leer el contenido de cada arreglo linea por linea, cada linea contiene un arreglo
    de tamaño 100 + 500*rowIndex elementos.
  */
  while (getline(file, line)) {
    int numElements = static_cast<int>(100 + 500*rowIndex);
    int* A = new int[numElements];

    stringstream ss(line);
    int number;
    int index = 0;

    // Rellenar A con los contenidos de la linea.
    while (ss >> number)
      A[index++] = number;

    auto start = chrono::high_resolution_clock::now();  // Comienza el timer.

    // bubbleSort(A, numElements);                              // Utiliza el algoritmo de BubbleSort para ordenar el arreglo "A". Descomentar para usar.
    // mergeSort(A, 0, numElements - 1);                        // Utiliza el algoritmo de MergeSort para ordenar el arreglo "A". Descomentar para usar.
    // quickSort(A, 0, numElements - 1);                        // Utiliza el algoritmo de Quicksort para ordenar el arreglo "A". Descomentar para usar.
    // introSort(A, A + 0, A + (sizeof(A) / sizeof(A[0])), 0);  // Utiliza el algoritmo de IntroSort para ordenar el arreglo "A". Descomentar para usar.

    auto end = chrono::high_resolution_clock::now();    // Termina el timer.
    chrono::duration<double> duration = end - start;

    // Imprime tiempos en pantalla.
    cout << "Tiempo de ejecución | Tamaño del arreglo n° " << 100 + 500 * rowIndex << ": " << 1000 * duration.count() << " ms\n";

    delete[] A;
    rowIndex++;
    k++;
  }

  file.close();

	return 0;
}