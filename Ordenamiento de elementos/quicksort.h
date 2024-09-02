#pragma once

#include <iostream>

/*
    swap

    Input : Arreglo de n�meros enteros, posici�n del elemento 1 a intercambiar,
            posici�n del elemento 2 a intercambiar.
    Output : No retorna, pero intercambia dos elementos del arreglo por referencia.
*/
void swap(int arr[], int pos1, int pos2) {
  int temp = arr[pos1];
  arr[pos1] = arr[pos2];
  arr[pos2] = temp;
}

/*
    partition

    Input : Arreglo de n�meros enteros, comienzo del arreglo, final del arreglo,
            posici�n del pivote.
    Output : Retorna la posici�n del �ltimo elemento menor que el pivote.
*/
int partition(int arr[], int low, int high, int pivot) {
  int i = low;
  int j = low;

  while (i <= high) {
    // Si el elemento actual es mayor que el pivote, se ignora.
    if (arr[i] > pivot) {
      i++;
    }
    else {
      // Si el elemento actual es menor o igual que el pivote, se mueve.
      swap(arr, i, j); // Se intercambia el elemento actual con el elemento en la posici�n j.
      i++;
      j++;
    }
  }
  return j - 1;
}

/*
    quickSort

    Input : Arreglo de n�meros enteros, comienzo del arreglo, final del arreglo.
    Output : No retorna, pero por ordena el arreglo por referencia.
*/
void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pivot = arr[high]; // Elecci�n de un pivote, puede ser uno arbitrario.
    int pos = partition(arr, low, high, pivot); // Se encuentra la posici�n del pivote�.

    // De forma recursiva, ordenar los elementos a la izquierda y derecha del pivote.
    quickSort(arr, low, pos - 1);
    quickSort(arr, pos + 1, high);
  }
}