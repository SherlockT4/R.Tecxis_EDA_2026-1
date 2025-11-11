#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// ----------- ESTRUCTURA DE LA PILA -----------
typedef struct {
    int datos[MAX];
    int tope;
} Pila;

// ----------- ESTRUCTURA DE LA COLA -----------
typedef struct {
    int datos[MAX];
    int frente;
    int final;
} Cola;

// ----------- FUNCIONES PARA LA PILA -----------
void inicializarPila(Pila *p) {
    p->tope = -1;
    printf("Pila inicializada vacía.\n");
}

int pilaLlena(Pila *p) {
    return p->tope == MAX - 1;
}

int pilaVacia(Pila *p) {
    return p->tope == -1;
}

void push(Pila *p, int valor) {
    if (pilaLlena(p)) {
        printf("Error: la pila está llena.\n");
        return;
    }
    p->datos[++(p->tope)] = valor;
    printf("Elemento %d apilado.\n", valor);
}

int pop(Pila *p) {
    if (pilaVacia(p)) {
        printf("Error: la pila está vacía.\n");
        return -1;
    }
    return p->datos[(p->tope)--];
}

void mostrarPila(Pila *p) {
    if (pilaVacia(p)) {
        printf("[Vacía]\n");
        return;
    }
    printf("Estado actual de la pila: ");
    for (int i = 0; i <= p->tope; i++)
        printf("%d ", p->datos[i]);
    printf("\n");
}

// ----------- FUNCIONES PARA LA COLA -----------
void inicializarCola(Cola *c) {
    c->frente = 0;
    c->final = -1;
    printf("Cola inicializada vacía.\n");
}

int colaLlena(Cola *c) {
    return c->final == MAX - 1;
}

int colaVacia(Cola *c) {
    return c->frente > c->final;
}

void enqueue(Cola *c, int valor) {
    if (colaLlena(c)) {
        printf("Error: la cola está llena.\n");
        return;
    }
    c->datos[++(c->final)] = valor;
    printf("Elemento %d encolado.\n", valor);
}

int dequeue(Cola *c) {
    if (colaVacia(c)) {
        printf("Error: la cola está vacía.\n");
        return -1;
    }
    return c->datos[(c->frente)++];
}

void mostrarCola(Cola *c) {
    if (colaVacia(c)) {
        printf("[Vacía]\n");
        return;
    }
    printf("Estado actual de la cola: ");
    for (int i = c->frente; i <= c->final; i++)
        printf("%d ", c->datos[i]);
    printf("\n");
}

// ----------- FUNCIÓN PRINCIPAL -----------
int main() {
    Pila pila;
    Cola cola;
    int n, valor;

    // ----------- PASO 1: PILA -----------
    inicializarPila(&pila);
    printf("\n¿Cuántos elementos deseas apilar? (máximo %d): ", MAX);
    printf("\n(Escribe solo numeros)\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Ingresa el valor #%d: ", i + 1);
        scanf("%d", &valor);
        push(&pila, valor);
        mostrarPila(&pila);
    }

    printf("\n¿Cuántos elementos deseas desapilar?: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x = pop(&pila);
        if (x != -1)
            printf("Elemento desapilado: %d\n", x);
        mostrarPila(&pila);
    }

    // ----------- PASO 2: COLA -----------
    inicializarCola(&cola);
    printf("\n¿Cuántos elementos deseas encolar? (máximo %d): ", MAX);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Ingresa el valor #%d: ", i + 1);
        scanf("%d", &valor);
        enqueue(&cola, valor);
        mostrarCola(&cola);
    }

    printf("\n¿Cuántos elementos deseas desencolar?: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x = dequeue(&cola);
        if (x != -1)
            printf("Elemento desencolado: %d\n", x);
        mostrarCola(&cola);
    }

    // ----------- PASO 3: COMPARACIÓN FINAL -----------
    printf("\n--- COMPARACIÓN FINAL ---\n");
    printf("Pila → LIFO (Último en entrar, primero en salir)\n");
    printf("Cola → FIFO (Primero en entrar, primero en salir)\n");

    printf("\nFin del programa.\n");
    return 0;
}
