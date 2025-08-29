#include <stdio.h>

int main(void)
{
	int n;
	printf("Ingresa una cantidad de elementos para tu arreglo :\n");
	scanf("%d", &n);
	while (n<=0 || n>3)
	{
	    printf("Elemento no valido intente de nuevo\n");
	    scanf("%d", &n);
	}
	int array[3];
	printf("Tu arreglo tiene %d elementos\n", n);
	for(int i=0; i < n; i++)
	{
			printf("Ingresa el elemento %i \n", i+1);
			scanf("%i", &array[i]);
	}
	printf("Los valores del arreglo son: \n");
	for (int i=0; i < n; i++)
	{
			printf("(%i)  ", array[i] );
	}
	return 0;
}