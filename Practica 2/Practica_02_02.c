#include <stdio.h>

int a[3] = {10,20,30}; // Se declara un arreglo de 3 enteros con valores iniciales 10, 20 y 30.
int *p = a; // Se declara un puntero a entero que almacena la dirección del primer elemento del arreglo (a[0]).
int main (void)
{
    // Primer recorrido usando aritmética de punteros
    for (int i=0; i<3; i++) // Bucle que recorre de i=0 a i=2
    {
      printf("%d ", *(p+i)); // Imprime el valor que se obtiene desplazando p 'i' posiciones y desreferenciando (equivalente a a[i]).
    }
    
    // Otra forma de recorrer el arreglo usando incremento de puntero
    for(int i=0; i<3; i++) // Bucle que recorre de i=0 a i=2
    {
      printf("%d ", *p); // Imprime el valor apuntado actualmente por p.
      p++; // Avanza el puntero a la siguiente posición del arreglo (siguiente entero en memoria).
    }
    return 0;
}
