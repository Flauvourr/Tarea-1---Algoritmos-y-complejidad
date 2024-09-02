#pragma once

#include <iostream>

using namespace std;

/*

	naiveMatMult

	Input : Matriz A nxn, Matriz B nxn.
	Output : No retorna, pero imprime la matriz A*B en consola.

	Nota: Como ejemplo, una matriz 3x3
				{
				 1 2 3,
				 4 5 6,
				 7 8 9,
				}
				En este caso ser� representada como:
				{ 1 2 3 4 5 6 7 8 9 }
				Con el elemento en la fila i columna j representado como A[n*i + j],
				n siendo el tama�o asumiento que la matriz es cuadrada.

*/
void naiveMatMult(int* A, int* B, int n) {
	// Creaci�n de la matriz A*B, representaci�n en 1D.
	int* AB = new int[n * n];

	for (int element = 0; element < n * n; element++) {
		AB[element] = 0;
	}

	// Multiplicaci�n de A*B
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				AB[n * i + j] += A[n * i + k] * B[n * k + j];	// Representaci�n 1D de la posici�n x_{a, b} de un arreglo 2D, es decir, una matriz nxn.
			}
		}
	}

	// Imprime la matriz en consola
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << AB[3 * i + j] << " ";
		}
		cout << "\n";
	}

	// Liberar memoria
	delete[] AB;
}