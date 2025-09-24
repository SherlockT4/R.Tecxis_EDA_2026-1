#include <stdio.h>
#include <string.h>

#define TAM 64
#define MEDTAM 32

struct Movie
{
	char nameMovie[TAM];        //Nombre de la pelicula
	char nameDirectors[3][TAM]; //Nombre de los directores de la pelicula
	int releaseYear;            //AC1o de estreno de la pelicula
	int numberDirectors;        //Numero de directores de la pelicula
};

struct Genre {
	int  id;
	char name[TAM];
};

int main()
{
	char buf[64];
	int year = 0 ;
	int numberMovies = 0;
	int buscador = 0;
	const struct Genre genderMovie[] = {
		{1,"Accion"}, {2,"Comedia"}, {3,"Drama"}, {4,"Fantasia"},
		{5,"Ciencia Ficcion"}, {6,"Terror"}, {7,"Musical"},
		{8,"Suspense (Thriller)"}, {9,"Aventura"},
		{10,"Documental"}, {11,"Misterio"}, {12,"Western"}
	};
	const int GENRE_COUNT = (int)(sizeof genderMovie / sizeof genderMovie[0]);

	printf("Ingresa un numero de peliculas para tu videoteca (1..5):\n");
	while (1) {
		if (!fgets(buf, sizeof buf, stdin))
			return 1;
		if (sscanf(buf, "%d", &numberMovies) == 1 && numberMovies > 0 && numberMovies <= 5)
			break;
		puts("Elemento no valido, intenta de nuevo:");
	}

	struct Movie videoteca[numberMovies];
	for (int i = 0; i < numberMovies; i++)
	{
		//Titulo de la pelicula
		printf("\nEscribe el titulo de la pelicula %d\n", i+1);
		fgets(videoteca[i].nameMovie, sizeof(videoteca[i].nameMovie), stdin);
		videoteca[i].nameMovie[strcspn(videoteca[i].nameMovie, "\n")] = '\0';

		//AC1o de estreno de la pelicula
		puts("\nEscribe el año de estreno de la pelicula");
		while (1) {
			if (!fgets(buf, sizeof buf, stdin)) return 1;
			if (sscanf(buf, "%d", &year) == 1 && year >= 1888 && year <= 2025) {
				videoteca[i].releaseYear = year;
				break;                             // b sal de este while cuando sea vC!lido
			}
			puts("Año invalido o fuera de rango (1888..2025). \nIntenta de nuevo:");
		}

		//Genero de la pelicula
		printf("Aqui esta el menu de genero de peliculas\n");
		for (int i = 0; i < GENRE_COUNT; i++) {
			printf(" [%d] %s\n", genderMovie[i].id, genderMovie[i].name);
		}
		// leer y validar (1..12)
		do {
			printf("Elige un genero (1..%d): ", GENRE_COUNT);
			if (scanf("%d", &buscador) != 1) return 1;   // entrada no-numC)rica
			if (buscador < 1 || buscador > GENRE_COUNT) puts("Opcion invalida. Intenta de nuevo.");
		} while (buscador < 1 || buscador > GENRE_COUNT);
		int idx = buscador - 1; // C-ndice 0..11

		//numero de directores de la pelicula
		puts("\nEscribe el numero de directores que hicieron la pelicula \n(Maximo 3)");
		while (1) {
			if (!fgets(buf, sizeof buf, stdin)) return 1;
			if (sscanf(buf, "%d", &videoteca[i].numberDirectors) == 1 && videoteca[i].numberDirectors >= 1 && videoteca[i].numberDirectors <= 3) {
				break;
			}
			puts("Demasiados directores \nIntenta de nuevo:\n");
		}

		//Nombre de los directores
		for (int j = 0; j < videoteca[i].numberDirectors; j++)
		{
			printf("\nEscribe el nombre del director %d de la pelicula\n", j+1 );
			fgets(videoteca[i].nameDirectors[j], sizeof(videoteca[i].nameDirectors[j]), stdin);
			videoteca[i].nameDirectors[j][strcspn(videoteca[i].nameDirectors[j], "\n")] = '\0';
		}
	}
	puts("\n====== Tu videoteca actual es ======\n");
	for (int i = 0; i < numberMovies; i++)
	{
		printf("El titulo de la pelicula %d es: %s\n", i+1, videoteca[i].nameMovie);
		printf("El aC1o de estreno es: %d\n", videoteca[i].releaseYear);
		int idx = buscador - 1; // C-ndice 0..11
		printf("El genero de la pelicula es: %s\n", genderMovie[idx].name);
		if (videoteca[i].numberDirectors == 1)
		{
			printf("La pelicula %s tiene un dierctor\n", videoteca[i].nameMovie);
			printf ("El director se llama: %s\n", videoteca[i].nameDirectors[0]);
		}
		else
		{
			printf("La pelicula %s tiene %d dierctores\n", videoteca[i].nameMovie, videoteca[i].numberDirectors);
			for (int j = 0; j < videoteca[i].numberDirectors; j++)
			{
				printf ("El director %d se llama: %s\n", j+1, videoteca[i].nameDirectors[j] );
			}
		}
		puts("");
	}
	puts ("Orden inverso \n");
	for (int i = numberMovies-1; i >= 0; i--)
	{
		printf("El titulo de la pelicula %d es: %s\n", i+1, videoteca[i].nameMovie);
		printf("El aC1o de estreno es: %d\n", videoteca[i].releaseYear);
		int idx = buscador - 1; // C-ndice 0..11
		printf("El genero de la pelicula es: %s\n", genderMovie[idx].name);
		if (videoteca[i].numberDirectors == 1)
		{
			printf("La pelicula %s tiene un dierctor\n", videoteca[i].nameMovie);
			printf ("El director se llama: %s\n", videoteca[i].nameDirectors[0]);
		}
		else
		{
			printf("La pelicula %s tiene %d dierctores\n", videoteca[i].nameMovie, videoteca[i].numberDirectors);
			for (int j = 0; j < videoteca[i].numberDirectors; j++)
			{
				printf ("El director %d se llama: %s\n", j+1, videoteca[i].nameDirectors[j] );
			}
		}
		puts("");
	}
	return 0;
}