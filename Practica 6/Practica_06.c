#include <stdio.h>
#define MAX 5

// ======== COLA CIRCULAR ======== //
typedef struct {
    int datos[MAX];
    int frente;
    int final;
    int size;
} ColaCircular;

void inicializarColaCircular(ColaCircular *c) {
    c->frente = 0;
    c->final = 0;
    c->size = 0;
    printf("Cola circular inicializada\n");
}

int isEmptyCircular(ColaCircular *c) {
    return c->size == 0;
}

int isFullCircular(ColaCircular *c) {
    return c->size == MAX;
}

void enqueue(ColaCircular *c, int valor) {
    if (isFullCircular(c)) {
        printf("Error: la cola circular está llena.\n");
        return;
    }
    c->datos[c->final] = valor;
    c->final = (c->final + 1) % MAX;
    c->size++;
}

int dequeue(ColaCircular *c) {
    if (isEmptyCircular(c)) {
        printf("Error: la cola circular está vacía.\n");
        return -1;
    }
    int valor = c->datos[c->frente];
    c->frente = (c->frente + 1) % MAX;
    c->size--;
    return valor;
}

int peekCircular(ColaCircular *c) {
    if (isEmptyCircular(c)) return -1;
    return c->datos[c->frente];
}

void printQueue(ColaCircular *c) {
    printf("Estado de la cola circular: ");
    for (int i = 0; i < c->size; i++) {
        int index = (c->frente + i) % MAX;
        printf("%d ", c->datos[index]);
    }
    printf("\n");
}

// ======== COLA DOBLE (DEQUE) ======== //
typedef struct {
    int datos[MAX];
    int front;
    int size;
} Deque;

void inicializarDeque(Deque *d) {
    d->front = 0;
    d->size = 0;
    printf("Deque inicializado\n");
}

int isEmptyDeque(Deque *d) {
    return d->size == 0;
}

int isFullDeque(Deque *d) {
    return d->size == MAX;
}

int rearIndex(Deque *d) {
    return (d->front + d->size - 1) % MAX;
}

void insert_front(Deque *d, int valor) {
    if (isFullDeque(d)) {
        printf("Error: deque lleno.\n");
        return;
    }
    d->front = (d->front - 1 + MAX) % MAX;
    d->datos[d->front] = valor;
    d->size++;
}

void insert_rear(Deque *d, int valor) {
    if (isFullDeque(d)) {
        printf("Error: deque lleno.\n");
        return;
    }
    int rear = (d->front + d->size) % MAX;
    d->datos[rear] = valor;
    d->size++;
}

int delete_front(Deque *d) {
    if (isEmptyDeque(d)) {
        printf("Error: deque vacío.\n");
        return -1;
    }
    int valor = d->datos[d->front];
    d->front = (d->front + 1) % MAX;
    d->size--;
    return valor;
}

int delete_rear(Deque *d) {
    if (isEmptyDeque(d)) {
        printf("Error: deque vacío.\n");
        return -1;
    }
    int rear = rearIndex(d);
    int valor = d->datos[rear];
    d->size--;
    return valor;
}

void printDeque(Deque *d) {
    printf("Estado del deque: ");
    for (int i = 0; i < d->size; i++) {
        int index = (d->front + i) % MAX;
        printf("%d ", d->datos[index]);
    }
    printf("\n");
}

// ======== PROGRAMA PRINCIPAL ======== //
int main() {
    ColaCircular cola;
    Deque deque;
    
    // --- Cola Circular ---
    inicializarColaCircular(&cola);
    enqueue(&cola, 5);
    enqueue(&cola, 10);
    enqueue(&cola, 15);
    printQueue(&cola);
    
    printf("Elemento desencolado: %d\n", dequeue(&cola));
    printQueue(&cola);
    
    enqueue(&cola, 20);
    enqueue(&cola, 25);
    enqueue(&cola, 30);
    printQueue(&cola);
    
    // --- Deque ---
    inicializarDeque(&deque);
    insert_front(&deque, 10);
    insert_rear(&deque, 15);
    insert_rear(&deque, 20);
    insert_front(&deque, 30);
    insert_rear(&deque, 40);
    printDeque(&deque);
    
    printf("Eliminado del frente: %d\n", delete_front(&deque));
    printf("Eliminado del final: %d\n", delete_rear(&deque));
    printDeque(&deque);
    
    return 0;
}
