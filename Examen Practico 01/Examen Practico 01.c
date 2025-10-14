#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    int extra;
    int i;
    float *califs = NULL;
    float suma = 0.0f;
    float promedio = 0.0f;

    printf("Cuantos estudiantes deseas registrar? ");
    scanf("%d", &n);
    if (n <= 0) 
    return 0;

    califs = (float*)malloc(n * sizeof(float));
    if (califs == NULL) 
    {
        printf("Error: sin memoria.\n");
        return 1;
    }

    for (i = 0; i < n; i++) 
    {
        printf("Calificacion del estudiante %d: ", i + 1);
        scanf("%f", &califs[i]);
        suma += califs[i];
    }
    promedio = suma / n;
    printf("Promedio inicial: %.2f\n", promedio);

    printf("Deseas agregar mas estudiantes? (Ingresa 0 para no ): ");
    scanf("%d", &extra);

    if (extra > 0) {
        float *tmp = (float*)realloc(califs, (n + extra) * sizeof(float));
        if (tmp == NULL) 
        {
            printf("Error: sin memoria (realloc).\n");
            free(califs);
            return 1;
        }
        califs = tmp;

        for (i = n; i < n + extra; i++) 
        {
            printf("Calificacion del estudiante %d: ", i + 1);
            scanf("%f", &califs[i]);
            suma += califs[i];
        }
        n = n + extra;                     
        promedio = suma / n;
    }

    printf("=== Calificaciones registradas ===\n");
    for (i = 0; i < n; i++) 
    {
        printf("Estudiante %d: %.2f\n", i + 1, califs[i]);
    }
    printf("Promedio general: %.2f\n", promedio);

    free(califs);
    printf("Memoria liberada correctamente.\n");
    return 0;
}
