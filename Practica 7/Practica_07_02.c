#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

void insertarCircular(struct Nodo **cabeza, struct Nodo **ultimo, int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    nuevo->dato = valor;

    if (*cabeza == NULL) {
        *cabeza = nuevo;
        *ultimo = nuevo;
        nuevo->siguiente = *cabeza;
    } else {
        nuevo->siguiente = *cabeza;
        (*ultimo)->siguiente = nuevo;
        *cabeza = nuevo;
    }
    printf("Se insertó %d en la lista circular.\n", valor);
}

void recorrerCircular(struct Nodo *cabeza) {
    if (cabeza == NULL) {
        printf("La lista circular está vacía.\n");
        return;
    }

    struct Nodo *actual = cabeza;
    printf("Lista circular: ");
    do {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    } while (actual != cabeza);
    printf("(regresa al inicio)\n");
}

void eliminarCircular(struct Nodo **cabeza, struct Nodo **ultimo, int valor) {
    if (*cabeza == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    struct Nodo *actual = *cabeza;
    struct Nodo *anterior = *ultimo;

    do {
        if (actual->dato == valor) {
            if (actual == *cabeza) {
                *cabeza = actual->siguiente;
                (*ultimo)->siguiente = *cabeza;
            } else if (actual == *ultimo) {
                *ultimo = anterior;
                (*ultimo)->siguiente = *cabeza;
            } else {
                anterior->siguiente = actual->siguiente;
            }
            free(actual);
            printf("Se eliminó %d de la lista circular.\n", valor);
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    } while (actual != *cabeza);

    printf("El valor %d no se encontró.\n", valor);
}

int main() {
    struct Nodo *cabeza = NULL, *ultimo = NULL;
    int cantidad, valor, eliminarValor;

    printf("¿Cuántos valores deseas insertar en la lista circular? ");
    scanf("%d", &cantidad);

    for (int i = 0; i < cantidad; i++) {
        printf("Ingresa un valor: ");
        scanf("%d", &valor);
        insertarCircular(&cabeza, &ultimo, valor);
        recorrerCircular(cabeza);
    }

    printf("\n¿Qué valor deseas eliminar? ");
    scanf("%d", &eliminarValor);
    eliminarCircular(&cabeza, &ultimo, eliminarValor);
    recorrerCircular(cabeza);

    return 0;
}
