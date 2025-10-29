#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 4

//Use la ayuda de Chat GPT para la creación de estas funciones auxiliares y que mi codigo tenga menos riesgos de romperse
// Función auxiliar para limpiar el búfer de entrada
void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Función auxiliar para convertir una cadena a minúsculas
void converMinus(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int main()
{
	//Variables del primer ejemplo
	int *apuntadorUno, cantElemenUno, contElemenUno, validoUno;
	char resUno[TAM];

	//Variables del segundo ejemplo
	int *apuntadorDos, cantElemenDos, contElemenDos, validoDos;
	char resDos[TAM];

//*
	//Principio, use ayuda de chat gpt para evitar que se creC)n ciclos infinitos al usar caracteres distintos de un entero
	do {
		printf("Anota el numero de elementos que deseas asignar en la memoria\nEstos seran parte del arreglo 1 usando Malloc\n");
		validoUno = scanf("%d", &cantElemenUno);
		limpiarBuffer();
		if (validoUno != 1 ) {
			printf("Error: debes ingresar un numero entero.\n");
		}
	} while (validoUno != 1 || cantElemenUno <= 0);

	//Creacion de del arreglo dinamico usando Malloc
	apuntadorUno = (int *) malloc (cantElemenUno * sizeof(int));
	if( NULL == apuntadorUno )
	{
		printf( "Error asignando memoria\n" );
		exit( 1 );
	}
	//Creacion del arreglo dinamico dos usando Calloc
	do {
		printf("Anota el numero de elementos que deseas asignar en la memoria\nEstos seran parte del arreglo 2 usando Calloc\n");
		validoDos = scanf("%d", &cantElemenDos);
		limpiarBuffer();
		if (validoDos != 1|| cantElemenDos <= 0) {
			printf("Error: debes ingresar un numero entero.\n");
		}
	} while (validoDos != 1 || cantElemenDos <= 0);
	apuntadorDos = (int *) calloc (cantElemenDos, sizeof(int));
	if( NULL == apuntadorDos )
	{
		printf( "Error asignando memoria\n" );
		free(apuntadorUno);
		exit( 1 );
	}

	//Impresion de los valores iniciales del arreglo con Malloc
	puts("Ejemplo Malloc");
	printf("Estos son los datos que contiene cada elemento de tu primer arreglo\n");
	for(int i=0; i < cantElemenUno; i++)
	{
		printf ("Posicion [%d] elemento: %d\n", i, apuntadorUno[i]);
	}

	//Impresion de los valores iniciales del arreglo con Calloc
	puts("\nEjemplo Calloc");
	printf("Estos son los datos que contiene cada elemento antes de ser manipulado\n");
	for(int i=0; i < cantElemenDos; i++)
	{
		printf ("Posicion [%d] elemento: %d\n", i, apuntadorDos[i]);
	}

	//Contenido del arreglo 1 usando Malloc
	printf("\nEscribe el contenido de tu primer arreglo\n");
	for(int i=0; i < cantElemenUno; i++)
	{
		printf("Elemento: %d\n", i+1);
		scanf("%d", &contElemenUno);
		apuntadorUno[i] = contElemenUno;
	}
	limpiarBuffer();

	//Contenido del arreglo 2 usando Calloc
	printf("\nEscribe el contenido de tu segundo arreglo\n");
	for(int i=0; i < cantElemenDos; i++)
	{
		printf("Elemento: %d\n", i+1);
		scanf("%d", &contElemenDos);
		apuntadorDos[i] = contElemenDos;
	}
	limpiarBuffer();

	//Impresion del arreglo 1 con Malloc
	puts("\nEstos son los elementos del primer arreglo");
	for(int i=0; i < cantElemenUno; i++)
	{
		printf ("Posicion %d elemento %d del primer arreglo\n", i+1, apuntadorUno[i]);
	}

	//Impresion del arreglo 2 usando Calloc
	puts("\nEstos son los elementos del segundo arreglo");
	for(int i=0; i < cantElemenDos; i++)
	{
		printf ("Posicion %d elemento %d del segundo arreglo\n", i+1, apuntadorDos[i]);
	}
//*/
	//Agregar nuevos datos con Realloc en el arreglo Malloc
	printf("\n¿Quieres agregar mas datos en el primer arreglo (Malloc)? (si/no)\n");
    if (fgets(resUno, sizeof(resUno), stdin) != NULL) {
        resUno[strcspn(resUno, "\n")] = '\0'; // Eliminar el salto de línea
        converMinus(resUno); // Convertir a minúsculas
        if (strcmp(resUno, "si") == 0) {
            int nueElemen;
            do {
                printf("¿Cuantos elementos mas quieres agregar?\n");
                validoUno = scanf("%d", &nueElemen);
                limpiarBuffer();
                if (validoUno != 1 || nueElemen <= 0) {
                    printf("Error: debes ingresar un número entero positivo.\n");
                }
            } while (validoUno != 1 || nueElemen <= 0);
            
            size_t nueTama = cantElemenUno + nueElemen;
            int *temp = (int *)realloc(apuntadorUno, nueTama * sizeof(int));
            
            if (temp != NULL) {
                apuntadorUno = temp;
                printf("Memoria reasignada con éxito. Nuevo tamaño: %zu elementos.\n", nueTama);
                
                // Llenar los nuevos elementos
                for (size_t i = cantElemenUno; i < nueTama; i++) {
                    printf("Introduce el elemento %zu: ", i + 1);
                    scanf("%d", &apuntadorUno[i]);
                }
                limpiarBuffer();
                
                cantElemenUno = nueTama;
                
                printf("\nElementos del primer arreglo (después de realloc):\n");
                for (size_t i = 0; i < cantElemenUno; i++) {
                    printf("Posicion %zu: %d\n", i + 1, apuntadorUno[i]);
                }
            } else {
                printf("Error al reasignar memoria. Se mantiene el arreglo original.\n");
            }
        }else if (strcmp(resUno, "no") == 0) {
            printf("Ha respondido 'no'. Pasando al siguiente.\n");
        } else {
            printf("Respuesta no válida. Se interpreta como 'no'.\n");
        }
    } else {
        printf("Error al leer la entrada para el arreglo 1.\n");
    }

	//Agregar nuevos datos con Realloc en el arreglo Calloc
	printf("\n¿Quieres agregar mas datos en el segundo arreglo (Calloc)? (si/no)\n");
    if (fgets(resDos, sizeof(resDos), stdin) != NULL) {
        resDos[strcspn(resDos, "\n")] = '\0'; // Eliminar el salto de línea
        converMinus(resDos); // Convertir a minúsculas
        if (strcmp(resDos, "si") == 0) {
            int nueElemen;
            do {
                printf("¿Cuantos elementos mas quieres agregar?\n");
                validoDos = scanf("%d", &nueElemen);
                limpiarBuffer();
                if (validoDos != 1 || nueElemen <= 0) {
                    printf("Error: debes ingresar un número entero positivo.\n");
                }
            } while (validoDos != 1 || nueElemen <= 0);
            
            size_t nueTama = cantElemenDos + nueElemen;
            int *temp = (int *)realloc(apuntadorDos, nueTama * sizeof(int));
            
            if (temp != NULL) {
                apuntadorDos = temp;
                printf("Memoria reasignada con éxito. Nuevo tamaño: %zu elementos.\n", nueTama);
                
                // Llenar los nuevos elementos
                for (size_t i = cantElemenDos; i < nueTama; i++) {
                    printf("Introduce el elemento %zu: ", i + 1);
                    scanf("%d", &apuntadorDos[i]);
                }
                limpiarBuffer();
                
                cantElemenDos = nueTama;
                
                printf("\nElementos del primer arreglo (después de realloc):\n");
                for (size_t i = 0; i < cantElemenDos; i++) {
                    printf("Posicion %zu: %d\n", i + 1, apuntadorDos[i]);
                }
            } else {
                printf("Error al reasignar memoria. Se mantiene el arreglo original.\n");
            }
        }else if (strcmp(resDos, "no") == 0) {
            printf("Ha respondido 'no'. Pasando al siguiente.\n");
        } else {
            printf("Respuesta no válida. Se interpreta como 'no'.\n");
        }
    } else {
        printf("Error al leer la entrada para el arreglo 1.\n");
    }
//*
	//Liberacion de la memoria
	free(apuntadorUno);
	free(apuntadorDos);
	printf("\nMemoria liberada exitosamente para ambos arreglos");
//*/
	return 0;
}
