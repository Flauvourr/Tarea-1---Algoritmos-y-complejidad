#pragma once

#include <iostream>

/*
    merge

    Input : Arreglo de números enteros, posición inicial del arreglo, 
            posición de la mitad del arreglo, posición final del arreglo.
    Output : No retorna, pero por ordena el arreglo por referencia.
*/
void merge(int arr[], int left, int mid, int right) {
  // Se registra el tamaño de los arreglos a la mitad izquierda y derecha.
  int n1 = mid - left + 1;
  int n2 = right - mid;

  // Sub-arreglos de la mitad izquierda y derecha del arreglo original.
  // NOTA: En este caso son dinámicos pero en C99 no es necesario.
  int* L = new int[n1];
  int* R = new int[n2];

  // Rellenar los sub-arreglos con los contenidos originales.
  for (int i = 0; i < n1; i++)
    L[i] = arr[left + i];
  for (int j = 0; j < n2; j++)
    R[j] = arr[mid + 1 + j];

  // Combina y arregla los sub-arreglos dentro del arreglo original.
  int i = 0; // Índice inicial del primer sub-arreglo.
  int j = 0; // Índice inicial del segundo sub-arreglo.
  int k = left; // Índice inicial del arreglo combinado.
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    }
    else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // Si es que existen, copiar los elementos restantes del sub-arreglo izquierdo.
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  // Si es que existen, copiar los elementos restantes del sub-arreglo derecho.
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }

  delete[] R;
  delete[] L;
}

/*
    Mergesort

    Input : Arreglo de números enteros, posición inicial del arreglo, posición final del arreglo.
    Output : No retorna, pero por ordena el arreglo por referencia.
*/
void mergeSort(int arr[], int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;  // Encuentra el punto medio del arreglo.

    // Por recursividad, sigue dividiendo las mitades de los arreglos
    // por 2 hasta que el tamaño del arreglo sea de un elemento.
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Combina dos arreglos y los ordena.
    merge(arr, left, mid, right);
  }
}