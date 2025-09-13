#include <stdio.h>

int main(void) {
    int x = 7; //Se crea la variable x y se le otorga el valor 7
    int *p = &x; //Se crea una variable del tipo apuntador y tiene de valor la direccion de memoria de la variable x
    int y = *p + 3; //Se crea la variable "y" y se le da el valor del contenido del apuntador y se le suma 3

    printf("1) x = %d\n", x); // Se imprime el valor de x
    printf("2) *p = %d\n", *p); //Se imprime el valor apuntado por p (es decir, el contenido de x) 
    printf("3) p = %p\n", (void*)p); //Se imprime la direccion almacenada en p
    printf("4) &x = %p\n", (void*)&x); //Se imprime la direccion de la variable x
    printf("5) y = %d\n", y);//Se imprime el valor de la variable y

    *p = 42; //Modifica el valor de la variable a la que p apunta (o sea que cambia x a 42). 
    //    El puntero no cambia lo que cambia es el contenido de x.

    printf("6) x = %d, *p = %d\n", x, *p); // se imprime el valor de x y el valor del apuntador p
    return 0;
}
