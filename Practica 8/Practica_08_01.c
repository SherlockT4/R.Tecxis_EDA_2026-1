#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};

void insertarInicio(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->dato = valor;
    nuevo->anterior = NULL;
    nuevo->siguiente = *inicio;

    if (*inicio != NULL) {
        (*inicio)->anterior = nuevo;
    }

    *inicio = nuevo;
}

void insertarFinal(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    if (*inicio == NULL) {
        nuevo->anterior = NULL;
        *inicio = nuevo;
        return;
    }

    struct Nodo *temp = *inicio;

    while (temp->siguiente != NULL) {
        temp = temp->siguiente;
    }

    temp->siguiente = nuevo;
    nuevo->anterior = temp;
}

void recorrerAdelante(struct Nodo *inicio) {
    struct Nodo *temp = inicio;
    printf("Lista adelante: ");
    while (temp != NULL) {
        printf("%d ", temp->dato);
        temp = temp->siguiente;
    }
    printf("\n");
}

void recorrerAtras(struct Nodo *inicio) {
    if (inicio == NULL) return;

    struct Nodo *temp = inicio;

    while (temp->siguiente != NULL) {
        temp = temp->siguiente;
    }

    printf("Lista atras: ");
    while (temp != NULL) {
        printf("%d ", temp->dato);
        temp = temp->anterior;
    }
    printf("\n");
}

void eliminar(struct Nodo **inicio, int valor) {
    struct Nodo *temp = *inicio;

    while (temp != NULL && temp->dato != valor) {
        temp = temp->siguiente;
    }

    if (temp == NULL) {
        printf("No se encontro el valor.\n");
        return;
    }

    if (temp->anterior != NULL) {
        temp->anterior->siguiente = temp->siguiente;
    } else {
        *inicio = temp->siguiente;
    }

    if (temp->siguiente != NULL) {
        temp->siguiente->anterior = temp->anterior;
    }

    free(temp);
}

void liberar(struct Nodo *inicio) {
    struct Nodo *temp;
    while (inicio != NULL) {
        temp = inicio;
        inicio = inicio->siguiente;
        free(temp);
    }
    printf("Memoria liberada.\n");
}

int main() {
    struct Nodo *inicio = NULL;
    int n, valor;

    printf("Cuantos valores deseas insertar al inicio: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valor: ");
        scanf("%d", &valor);
        insertarInicio(&inicio, valor);
    }

    recorrerAdelante(inicio);

    printf("Cuantos valores deseas insertar al final: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valor: ");
        scanf("%d", &valor);
        insertarFinal(&inicio, valor);
    }

    recorrerAdelante(inicio);
    recorrerAtras(inicio);

    printf("Que valor quieres eliminar: ");
    scanf("%d", &valor);
    eliminar(&inicio, valor);

    recorrerAdelante(inicio);

    liberar(inicio);

    return 0;
}
