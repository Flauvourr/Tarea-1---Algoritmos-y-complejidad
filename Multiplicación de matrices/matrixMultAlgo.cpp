#include <iostream>
#include <chrono>
#include <fstream>
#include <cmath>
#include <sstream>
#include <stdio.h>
#include <algorithm>

#include "naive.h"
#include "transpose.h"
#include "strassen.h"

using namespace std;

int main() {
  ifstream file("naive-transpose.txt");     // Dataset para los algoritmos Naive y Transpose.
  // ifstream file("strassen.txt"); // Dataset para el algoritmo de Strassen. Descomentar para usar.
  string line;
  int lineNumber = 1;

  while (getline(file, line)) {
    // Calculate the expected size for the array
    int expectedSize = (10 + 100 * lineNumber) * (10 + 100 * lineNumber); // EXtraer datos para el algoritmo de Naive y Transpose.
    // int expectedSize = (pow(2, lineNumber)) * (pow(2, lineNumber));    // EXtraer datos para el algoritmo de Strassen. Descomentar para usar.

    // Dynamically allocate array
    int* temp = new int[expectedSize];

    istringstream iss(line);
    int number;
    int index = 0;
    






    /*
    
      Parte necesaria para que el algoritmo de Strassen extraido de https://compgeek.co.in/strassens-algorithm/
      funcione. Código también extraido de la página pero modificado para convertir una matriz 1D a una 2D.

    */

    // int size = (pow(2, lineNumber));  // Size of the matrices

    // int** A = allocateMatrix(size);

    // int** B = allocateMatrix(size);

    // int** C = allocateMatrix(size);

    // Initializing matrices A(4×4) and B(4×4)

    // for (int i = 0; i < size; i++) {
    //   for (int j = 0; j < size; j++) {
    //     A[i][j] = temp[size * i + j];
    //     B[i][j] = temp[size * i + j];
    //   }
    // }

    /*
      Cronometrar el algoritmo de Strassen en matrices nxn.
      DESCOMENTAR para utilizar.
    */

    // auto start = chrono::high_resolution_clock::now();
    // strassenMultiplication(A, B, C, size);
    // auto end = chrono::high_resolution_clock::now();

    /*
      Cronometrar el algoritmo de Strassen en matrices nxn.
      DESCOMENTAR para utilizar.
    */

    // chrono::duration<double> elapsed = end - start;
    // cout << "Time taken: " << 1000 * elapsed.count() << " ms" << endl;

    // Liberar memoria

    // deallocateMatrix(A, size);

    // deallocateMatrix(B, size);

    // deallocateMatrix(C, size);

    /*

        Parte necesaria para que el algoritmo de Strassen extraido de https://compgeek.co.in/strassens-algorithm/
        funcione. Código también extraido de la página pero modificado para convertir una matriz 1D a una 2D.

    */







    /*
      Cronometrar algoritmos de multiplicación matrices nxn.
      DESCOMENTAR para utilizar.
    */

    // auto start = chrono::high_resolution_clock::now();
  
    // naiveMatMult(A, A, (10 + 100 * lineNumber));
		// transposeNaiveMatMult(A, A, (10 + 100 * lineNumber));

    // auto end = chrono::high_resolution_clock::now();

    // chrono::duration<double> elapsed = end - start;
    // cout << "Time taken: " << 1000 * elapsed.count() << " ms" << endl;

    /*
      Cronometrar algoritmos de multiplicación matrices nxn.
      DESCOMENTAR para utilizar.
    */







    delete[] temp; // Clean up allocated memory
    lineNumber++;
  }

  file.close();
  
	return 0;
}

//// Output the A (or process them as needed)
//cout << "Line " << lineNumber << ": ";
//for (int i = 0; i < expectedSize; ++i) {
//  cout << A[i] << ' ';
//}
//cout << '\n';