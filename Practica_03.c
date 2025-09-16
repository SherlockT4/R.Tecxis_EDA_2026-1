#include <stdio.h>
#include <string.h>

#define NUM_DIR   2
#define NAME_LEN  20
#define MIN_YEAR  1888
#define MAX_YEAR  2025

struct pelicula {
    char nameMovie[NAME_LEN];             // título
    char genreMovie[NAME_LEN];            // género
    char direction[NUM_DIR][NAME_LEN];    // directores
    int  age;                             // año (sug: rename a 'anio' o 'releaseYear')
    int  numDirectores;                   // 0..NUM_DIR
};

/* --------- Prototipos --------- */
int  leerCadena(const char *prompt, char *dest, size_t tam);
int  leerEntero(const char *prompt, int *out);
void limpiarRestanteLinea(void);

int  giveName(struct pelicula *p);
int  giveGender(struct pelicula *p);
int  giveAge(struct pelicula *p, int minY, int maxY);
int  giveNumDirectors(struct pelicula *p, int maxDirs);
int  giveDirectors(struct pelicula *p);

void printMovie(const struct pelicula *p);

/* --------- Implementación utilitaria --------- */
void limpiarRestanteLinea(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}
}

int leerCadena(const char *prompt, char *dest, size_t tam) {
    printf("%s", prompt);
    if (!fgets(dest, (int)tam, stdin)) return 0;

    size_t len = strlen(dest);
    if (len && dest[len - 1] == '\n') 
    {
        dest[len - 1] = '\0';                // recorta '\n'
    } else if (len == tam - 1) {
        // línea posiblemente truncada: barrer resto
        limpiarRestanteLinea();
    }

    return dest[0] != '\0';                   // 1 si no está vacía
}

int leerEntero(const char *prompt, int *out) {
    char buf[64];
    printf("%s", prompt);
    if (!fgets(buf, sizeof buf, stdin)) return 0;
    return sscanf(buf, "%d", out) == 1;       // 1 si hubo entero
}

/* --------- “Funciones por campo” --------- */
int giveName(struct pelicula *p) {
    while (!leerCadena("Nombre de la pelicula: ", p->nameMovie, NAME_LEN)) {
        puts("Entrada vacia. Intenta de nuevo.");
    }
    return 1;
}

int giveGender(struct pelicula *p) {
    while (!leerCadena("Genero: ", p->genreMovie, NAME_LEN)) {
        puts("Entrada vacia. Intenta de nuevo.");
    }
    return 1;
}

int giveAge(struct pelicula *p, int minY, int maxY) {
    int tmp;
    for (;;) {
        if (!leerEntero("Anio de estreno: ", &tmp)) {
            puts("Debes escribir un numero.");
            continue;
        }
        if (tmp < minY || tmp > maxY) {
            printf("Anio fuera de rango (%d..%d). Intenta de nuevo.\n", minY, maxY);
            continue;
        }
        p->age = tmp;
        return 1;
    }
}

int giveNumDirectors(struct pelicula *p, int maxDirs) {
    int tmp;
    for (;;) {
        if (!leerEntero("Numero de directores: ", &tmp)) {
            puts("Debes escribir un numero.");
            continue;
        }
        if (tmp < 0 || tmp > maxDirs) {
            printf("Debe estar entre 0 y %d. Intenta de nuevo.\n", maxDirs);
            continue;
        }
        p->numDirectores = tmp;
        return 1;
    }
}

int giveDirectors(struct pelicula *p) {
    for (int d = 0; d < p->numDirectores; d++) 
    {
        char prompt[64];
        snprintf(prompt, sizeof prompt, "Director %d: ", d + 1);
        while (!leerCadena(prompt, p->direction[d], NAME_LEN)) {
            puts("Entrada vacia. Intenta de nuevo.");
        }
    }
    return 1;
}

/* --------- Impresión --------- */
void printMovie(const struct pelicula *p) {
    printf("Pelicula: %s\n", p->nameMovie);
    printf("Genero:   %s\n", p->genreMovie);
    printf("Anio:     %d\n", p->age);
    printf("Directores (%d):\n", p->numDirectores);
    for (int i = 0; i < p->numDirectores; i++) {
        printf("  - %s\n", p->direction[i]);
    }
    puts("");
}

/* --------- main --------- */
int main(void) {
    int mN;

    /* Cuántas películas vas a capturar (15..100) */
    for (;;) {
        if (!leerEntero("Cantidad de peliculas (15..100): ", &mN)) {
            puts("Debes escribir un numero.");
            continue;
        }
        if (mN < 15 || mN > 100) {
            puts("Cantidad invalida. Intenta de nuevo.");
            continue;
        }
        break;
    }

    struct pelicula videoteca[mN];
    memset(videoteca, 0, sizeof videoteca);

    /* Captura */
    for (int i = 0; i < mN; i++) {
        printf("\n=== Captura de pelicula %d de %d ===\n", i + 1, mN);
        giveName(&videoteca[i]);
        giveGender(&videoteca[i]);
        giveAge(&videoteca[i], MIN_YEAR, MAX_YEAR);
        giveNumDirectors(&videoteca[i], NUM_DIR);
        giveDirectors(&videoteca[i]);
    }

    /* Mostrar (última a primera, estilo pila) */
    puts("\n-------- Contenido de la videoteca ---------");
    for (int i = 0; i < mN; i++) {
        printMovie(&videoteca[i]);
    }

    return 0;
}
