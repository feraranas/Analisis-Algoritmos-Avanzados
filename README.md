# Máximo número de compañeros

Considere una matriz en la que cada celda represente a un usuario de Facebook. Si el usuario es mexicano, su celda contiene un 1 y, si no es mexicano, su celda contiene un 0. Si dos usuarios en la matriz están uno al lado del otro horizontalmente, vertical o diagonalmente, significa que son amigos en Facebook.

Si dos usuarios mexicanos son amigos en Facebook, entonces son parte de la misma región mexicana. Dos usuarios mexicanos que no son amigos aún pueden ser parte de la misma región mexicana  a través de una serie de otros amigos. Si no hay una secuencia de amistades que conecte a dos usuarios mexicanos, entonces no son parte de la misma región mexicana.

Por ejemplo, hay tres regiones mexicanas máximas en la siguiente matriz de 5 * 5:

1 0 0 0 1
1 0 1 1 0
0 0 1 1 0
0 0 0 0 1
1 0 0 0 1

El tamaño máximo de una región mexicana es el número de usuarios en esa región. En este ejemplo, la región ubicada en la parte superior izquierda tiene el tamaño 2, la región de la derecha tiene el tamaño 7 y la región en la parte inferior izquierda tiene el tamaño 1.

Dada una matriz R*C, su tarea es encontrar el tamaño de la región mexicana más grande.

La primera línea contiene un solo entero T, el número de casos de prueba. Cada caso de prueba comienza con una línea que contiene el entero único R, luego una línea que contiene el entero único CC, luego R más líneas, la i-ésima de las cuales contiene la i-ésima fila de la matriz que consta de enteros separados por espacios CC que son todos 0 o 1.

Para el iésimo caso de prueba, imprima "Caso #i:" seguido del tamaño de la región mexicana máxima más grande.

##### Consideraciones:
1. Los valores de la matriz son solo 1's y 0's.
2. La estructura de la matriz se representa mediante filas y columnas con un arreglo de arreglos (vector de vectores).

_Código:_ 
- C++ [Maximo numero de compañeros.cpp](../maximo-numero-companeros/maximo-numero-companeros.cpp)
- C [Maximo numero de compañeros.c](../maximo-numero-companeros/maximo-numero-companeros.c)
- Python [Maximo numero de compañeros.py](../maximo-numero-companeros/maximo-numero-companeros.py)
- Racket [Maximo numero de compañeros.rkt](../maximo-numero-companeros/maximo-numero-companeros.rkt)
