/*
CÓDIGO EXTRAIDO DE LA PÁGINA: https://compgeek.co.in/strassens-algorithm/
AUTOR ANÓNIMO

CRÉDITOS TOTAL A/A LOS AUTOR(ES) POR EL CÓDIGO Y COMENTARIOS DE ESTE

Nota: Única alteración realizada fue agregar la función displayMatrix() casi al final
      de la función principal para imprimir la matriz en pantalla.

*/



// COMPUTER GEEK – compgeek.co.in
// Write a Program to multiply two matrices from Strassen’s Algorithm

#pragma once

#include <stdio.h>

#include <stdlib.h>

// Function to allocate memory for a matrix

int** allocateMatrix(int size) {

  int** matrix = (int**)malloc(size * sizeof(int*));

  for (int i = 0; i < size; i++)

    matrix[i] = (int*)malloc(size * sizeof(int));

  return matrix;

}

// Function to deallocate memory of a matrix

void deallocateMatrix(int** matrix, int size) {

  for (int i = 0; i < size; i++)

    free(matrix[i]);

  free(matrix);

}

// Function to add two matrices

void addMatrix(int** A, int** B, int** C, int size) {

  for (int i = 0; i < size; i++) {

    for (int j = 0; j < size; j++) {

      C[i][j] = A[i][j] + B[i][j];

    }

  }

}

// Function to subtract two matrices

void subtractMatrix(int** A, int** B, int** C, int size) {

  for (int i = 0; i < size; i++) {

    for (int j = 0; j < size; j++) {

      C[i][j] = A[i][j] - B[i][j];

    }

  }

}

// Function to multiply two matrices using Strassen’s Algorithm

void strassenMultiplication(int** A, int** B, int** C, int size) {

  if (size <= 4) {

    // Base case: Use naive matrix multiplication for small matrices

    for (int i = 0; i < size; i++) {

      for (int j = 0; j < size; j++) {

        C[i][j] = 0;

        for (int k = 0; k < size; k++) {

          C[i][j] += A[i][k] * B[k][j];

        }

      }

    }

    return;

  }

  int newSize = size / 2;

  // Creating submatrices

  int** A11 = allocateMatrix(newSize);

  int** A12 = allocateMatrix(newSize);

  int** A21 = allocateMatrix(newSize);

  int** A22 = allocateMatrix(newSize);

  int** B11 = allocateMatrix(newSize);

  int** B12 = allocateMatrix(newSize);

  int** B21 = allocateMatrix(newSize);

  int** B22 = allocateMatrix(newSize);

  int** C11 = allocateMatrix(newSize);

  int** C12 = allocateMatrix(newSize);

  int** C21 = allocateMatrix(newSize);

  int** C22 = allocateMatrix(newSize);

  int** P1 = allocateMatrix(newSize);

  int** P2 = allocateMatrix(newSize);

  int** P3 = allocateMatrix(newSize);

  int** P4 = allocateMatrix(newSize);

  int** P5 = allocateMatrix(newSize);

  int** P6 = allocateMatrix(newSize);

  int** P7 = allocateMatrix(newSize);

  // Dividing matrices into submatrices

  for (int i = 0; i < newSize; i++) {

    for (int j = 0; j < newSize; j++) {

      A11[i][j] = A[i][j];

      A12[i][j] = A[i][j + newSize];

      A21[i][j] = A[i + newSize][j];

      A22[i][j] = A[i + newSize][j + newSize];

      B11[i][j] = B[i][j];

      B12[i][j] = B[i][j + newSize];

      B21[i][j] = B[i + newSize][j];

      B22[i][j] = B[i + newSize][j + newSize];

    }

  }

  // Recursive calls

  strassenMultiplication(A11, B11, P1, newSize);

  strassenMultiplication(A12, B21, P2, newSize);

  strassenMultiplication(A11, B12, P3, newSize);

  strassenMultiplication(A12, B22, P4, newSize);

  strassenMultiplication(A21, B11, P5, newSize);

  strassenMultiplication(A22, B21, P6, newSize);

  strassenMultiplication(A21, B12, P7, newSize);

  // Calculating submatrices of C using Strassen’s formulas

  addMatrix(P1, P2, C11, newSize);

  addMatrix(P3, P4, C12, newSize);

  addMatrix(P5, P6, C21, newSize);

  addMatrix(P4, P5, P4, newSize);

  addMatrix(P4, P7, P4, newSize);

  subtractMatrix(C11, P4, C11, newSize);

  subtractMatrix(C11, P6, C22, newSize);

  addMatrix(P3, P5, C12, newSize);

  addMatrix(P2, P4, C21, newSize);

  // Combining submatrices to form the result matrix

  for (int i = 0; i < newSize; i++) {

    for (int j = 0; j < newSize; j++) {

      C[i][j] = C11[i][j];

      C[i][j + newSize] = C12[i][j];

      C[i + newSize][j] = C21[i][j];

      C[i + newSize][j + newSize] = C22[i][j];

    }

  }

  displayMatrix(C, size);

  // Deallocating submatrices

  deallocateMatrix(A11, newSize);

  deallocateMatrix(A12, newSize);

  deallocateMatrix(A21, newSize);

  deallocateMatrix(A22, newSize);

  deallocateMatrix(B11, newSize);

  deallocateMatrix(B12, newSize);

  deallocateMatrix(B21, newSize);

  deallocateMatrix(B22, newSize);

  deallocateMatrix(C11, newSize);

  deallocateMatrix(C12, newSize);

  deallocateMatrix(C21, newSize);

  deallocateMatrix(C22, newSize);

  deallocateMatrix(P1, newSize);

  deallocateMatrix(P2, newSize);

  deallocateMatrix(P3, newSize);

  deallocateMatrix(P4, newSize);

  deallocateMatrix(P5, newSize);

  deallocateMatrix(P6, newSize);

  deallocateMatrix(P7, newSize);

}

// Function to display a matrix

void displayMatrix(int** matrix, int size) {

  for (int i = 0; i < size; i++) {

    for (int j = 0; j < size; j++) {

      printf(" % d ", matrix[i][j]);

    }

    printf("\n");

  }

}