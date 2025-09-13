#include <stdio.h>

int main(void) 
{
    int numeros[4] = {5, 10, 15, 20}; // Se declara un arreglo de 4 enteros con valores iniciales 5, 10, 15 y 20.
    int *p = numeros; // Se declara un puntero a entero que almacena la dirección del primer elemento del arreglo (numeros[0]).

    printf("1) numeros[2] = %d\n", numeros[2]); // Imprime el valor del elemento en el índice 2 del arreglo (15).
    printf("2) *(p+2) = %d\n", *(p+2)); // Imprime el valor obtenido al desplazar p dos posiciones y desreferenciar (también 15).
    printf("3) *p = %d\n", *p); // Imprime el valor apuntado actualmente por p (5).

    p++; // Avanza el puntero p para que ahora apunte al segundo elemento del arreglo (numeros[1]).

    printf("4) *p = %d\n", *p); // Imprime el valor apuntado actualmente por p (10).
    
    return 0;
}
