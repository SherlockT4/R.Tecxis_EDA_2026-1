#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

void insertarInicio(struct Nodo **cabeza, int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    nuevo->dato = valor;
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
    printf("Se insertó %d al inicio de la lista.\n", valor);
}

void recorrer(struct Nodo *cabeza) {
    struct Nodo *actual = cabeza;
    if (actual == NULL) {
        printf("La lista está vacía.\n");
        return;
    }
    printf("Lista actual: ");
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

void eliminar(struct Nodo **cabeza, int valor) {
    struct Nodo *actual = *cabeza, *anterior = NULL;

    while (actual != NULL && actual->dato != valor) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        printf("El valor %d no se encontró.\n", valor);
        return;
    }

    if (anterior == NULL) { // está en la cabeza
        *cabeza = actual->siguiente;
    } else {
        anterior->siguiente = actual->siguiente;
    }

    free(actual);
    printf("Se eliminó %d de la lista.\n", valor);
}

void liberar(struct Nodo *cabeza) {
    struct Nodo *temp;
    while (cabeza != NULL) {
        temp = cabeza;
        cabeza = cabeza->siguiente;
        free(temp);
    }
    printf("Memoria liberada correctamente.\n");
}

int main() {
    struct Nodo *cabeza = NULL;
    int cantidad, valor, eliminarValor;

    printf("¿Cuántos valores deseas insertar? ");
    scanf("%d", &cantidad);

    for (int i = 0; i < cantidad; i++) {
        printf("Ingresa un valor: ");
        scanf("%d", &valor);
        insertarInicio(&cabeza, valor);
        recorrer(cabeza);
    }

    printf("\n¿Qué valor deseas eliminar? ");
    scanf("%d", &eliminarValor);
    eliminar(&cabeza, eliminarValor);
    recorrer(cabeza);

    liberar(cabeza);
    return 0;
}
