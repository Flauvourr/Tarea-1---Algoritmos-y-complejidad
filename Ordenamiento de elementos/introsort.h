/*

CÓDIGO Y COMENTARIOS EXTRAIDOS DE LA URL: Introsort code https://www.naukri.com/code360/library/internal-implementation-of-stdsort
POR EL AUTOR Rhythm Jain.

EXTRAIDO EL 28/07/2024.

TODOS LOS CRÉDITOS VAN PARA EL AUTOR.

*/

#pragma once

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// Function that performs insertion sort on given array "a" from index left to right.
void InsertionSort(int arr[], int left, int right)
{
  // element at index `left` is already sorted so 
  //start from the second element in the subarray
  for (int i = left + 1; i <= right; i++)
  {
    int value = arr[i];
    int j = i;


    while (j > left && arr[j - 1] > value)
    {
      arr[j] = arr[j - 1];
      j--;
    }

    //array is shifted to the right by one value.

    arr[j] = value;
  }
}

// Function that partition the Array
int partition(int arr[], int left, int right)
{
  // Picking the rightmost array element as a pivot.
  int pivot = arr[right];

  // elements less than the pivot will be pushed to the left of `pivotIndex`
  // elements greater than the pivot will be pushed to the right of `pivotIndex`
  int pivotIndex = left;

  //whenever we find an element less than or equal to the pivot, `pivotIndex`
  // is incremented by one, and that element is placed before the pivot.
  for (int i = left; i < right; i++)
  {
    if (arr[i] <= pivot)
    {
      swap(arr[i], arr[pivotIndex]);
      pivotIndex++;
    }
  }

  // swap `pivotIndex` with pivot
  swap(arr[pivotIndex], arr[right]);

  // return `pivotIndex` 
  return pivotIndex;
}

//Rearrange element with respect to pivot(Random)
int randPartition(int arr[], int left, int right)
{
  // choose a random index between `[left, right]`
  int pivotIndex = rand() % (right - left + 1) + left;

  // swap the right element with the element present at a random index
  swap(arr[pivotIndex], arr[right]);

  // calling the partition procedure
  return partition(arr, left, right);
}

// Function that performs perform heapsort
void heapSort(int* left, int* right)
{
  make_heap(left, right);
  sort_heap(left, right);
}

//introsort Function
void introSort(int arr[], int* left, int* right, int maxdepth)
{
  // performing insertion sort if partition size smaller(say 16)
  if ((right - left) < 16) {
    InsertionSort(arr, left - arr, right - arr);
  }
  // perform heapsort if the maximum depth is 0
  else if (maxdepth == 0) {
    heapSort(left, right + 1);
  }
  else {
    // else perform Quicksort
    int pivot = randPartition(arr, left - arr, right - arr);
    introSort(arr, left, arr + pivot - 1, maxdepth - 1);
    introSort(arr, arr + pivot + 1, right, maxdepth - 1);
  }
}