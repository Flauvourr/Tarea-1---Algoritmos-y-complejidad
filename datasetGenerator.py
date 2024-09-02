import numpy as np
import random

'''
    generateNormal
    
    Input: Nombre del archivo
    Output: Escribe en el archivo 49 arreglos de elementos entre el 1 y el 100.
            El step es de 500n.
'''
def generateNormal(fileName):
    with open(fileName, 'w') as file:
        for n in range(0, 50):
            size = 100 + 500*n
            array = np.random.randint(1, 101, size=size)
            file.write(' '.join(map(str, array)) + '\n')

'''
    generatePartiallyOrdered
    
    Input: Nombre del archivo
    Output: Escribe en el archivo 49 arreglos de elementos entre el 1 y el 100,
            donde el 1/3 de los elementos ya están ordenados.
'''
def generatePartiallyOrdered(fileName):
    with open(fileName, 'w') as file:
        for n in range(0, 50):
            size = 100 + 500*n
            size1 = round(size/3)
            size2 = round(size/3 * 2)
            array1 = np.random.randint(1, 101, size=size1)
            array2 = np.random.randint(1, 101, size=size2)
            array1.sort()
            array = np.concatenate((array1, array2))
            file.write(' '.join(map(str, array)) + '\n')

'''
    generateNumbers
    
    Input: Cantidad de elemento de la lista a generar.
    Output: Genera una lista de números entre el 1 y el 9 de tamaño
            del input.
'''
def generateNumbers(count):
    return [random.randint(1, 9) for _ in range(count)]

'''
    generateMatrix
    
    Input: Nombre del archivo
    Output: Escribe en el archivo matrices nxn donde el step de n es 100.
'''
def generateMatrix(filename):
    with open(filename, 'w') as file:
        n = 10
        while n < 2500:
            numbers = generateNumbers(n*n)
            file.write(' '.join(map(str, numbers)) + '\n')
            n += 100
            print(n)
            
'''
    generateStrassen
    
    Input: Nombre del archivo
    Output: Escribe en el archivo 7 matrices de tamaño nxn en 1D, donde n es
            una potencia de 2.
'''
def generateStrassen(fileName):
    with open(fileName, 'w') as file:
        for n in range(0, 8):
            size = 2**n
            array = np.random.randint(1, 101, size=size)
            file.write(' '.join(map(str, array)) + '\n')