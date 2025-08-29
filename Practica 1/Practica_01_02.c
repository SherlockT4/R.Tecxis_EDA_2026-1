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

//Funcion de suma de elementos del arreglo
int plusArray(int array[], int n) 
{
    int plus = 0;
    for (int i = 0; i < n; i++) {
        plus += array[i];  // acumula cada elemento
    }
    return plus; // devuelve la suma total
}
//promedio de arreglo 
float averageArray(int array[], int n)
{
    int average = plusArray(array, n);
    return (float) average/n;
}
//Elemento mas grande
int findMax(int array[], int n)
{
    int maxEle = 0;
    for (int i=0; i<n; i++ )
    {
        if (array[i]>array[maxEle])
        {
            maxEle = i;
        }
    }
    return maxEle;
}
//Elemento mas chico
int findMin(int array[], int n) {
    int minEle = 0;
    for (int i = 1; i < n; i++) {
        if (array[i] < array[minEle]) {
            minEle = i;
        }
    }
    return minEle;
}

int main(void)
{
    int array[5];
    int n = makeArray(array);
    int plus = plusArray(array, n);
    float avg = averageArray(array, n);
    int posMax = findMax(array, n);
    int posMin = findMin(array, n);

	printf("Los valores del arreglo son: \n");
	for (int i=0; i < n; i++)
	{
			printf("(%d)  ", array[i] );
	}
    printf("\nLa suma de todos los elementos es de %d\n", plus);
	printf("\nEl promedio de todos los elementos es de %.2f\n", avg);
    printf("\nEl valor máximo es %d y se encuentra en la posición %d\n", array[posMax], posMax);
    printf("\nEl valor mínimo es %d y se encuentra en la posición %d\n", array[posMin], posMin);

return 0;
}
//Suma, resta, max, min, prom, posicion de max y min
