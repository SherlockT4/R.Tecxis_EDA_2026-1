#include <stdio.h>

//Funcion de creación de arreglo
int makeArray(int array[])
{
    int n;
	printf("Ingresa una cantidad de elementos para tu arreglo :\n");
	scanf("%d", &n);
	//verificacion de que el dato ingresado este dentro de los parametros
	while (n<=0 || n>5)
	{
	    printf("Elemento no valido intente de nuevo\n");
	    scanf("%d", &n);
	}
	//llenado de los datos del arreglo
	printf("Tu arreglo tiene %d elementos\n", n);
	for(int i=0; i < n; i++)
	{
	    //verificacion de que el dato ingresado este dentro de los parametros 
			printf("Ingresa el elemento %i \n", i+1);
			scanf("%i", &array[i]);
	}
	return n;
}

int main (void)
{
    int array[5];
    int n = makeArray(array);
    printf("Los valores del arreglo son: \n");
	for (int i=0; i < n; i++)
	{
			printf("(%d)  ", array[i] );
	}
	printf("\nLos valores invertidos de tu arreglo son: \n");
	for (int i=n-1; i >= 0; i--)
	{
		printf("(%d)  ", array[i] );
	}
    return 0;
}
