#pragma once

#include <iostream>

using namespace std;

/*
    Bubble Sort

    Input : Arreglo de números enteros, tamaño n del arreglo.
    Output : No retorna, pero por ordena el arreglo por referencia.
*/
void bubbleSort(int arr[], int size) {
  for (int i = 0; i < size - 1; i++) {            // Cantidad de elementos ya ordenados.
    for (int j = 0; j < size - i - 1; j++) {      // Compara elementos adyacentes hasta el último no ordenado.
      if (arr[j] > arr[j + 1]) {                  // Intercambia el elemento j con el j + 1 si es que el último es menor.
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  // Imprime el arreglo ordenado en consola.
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " "
  }
  cout << "\n";
}