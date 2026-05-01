/*
 * Modulo 09 — Structs y Punteros
 * Archivo: 02_structs_y_punteros.c
 *
 * Demuestra:
 *   - Puntero a struct con operador flecha (->)
 *   - Pasar struct por puntero a funciones
 *   - Modificar campos a traves de punteros
 *
 * Compilar: gcc -Wall -Wextra -std=c11 -o 02_structs_y_punteros 02_structs_y_punteros.c
 */

#include <stdio.h>
#include <string.h>

/* Estructura para un punto en 2D */
typedef struct {
    float x;
    float y;
} Punto;

/* Estructura para una cuenta bancaria */
typedef struct {
    int numero;
    char titular[50];
    float saldo;
} Cuenta;

/* Prototipos */
void moverPunto(Punto *p, float dx, float dy);
void imprimirPunto(const Punto *p);
void depositar(Cuenta *c, float monto);
void retirar(Cuenta *c, float monto);
void imprimirCuenta(const Cuenta *c);

int main(void) {
    printf("=== STRUCTS Y PUNTEROS ===\n\n");

    /* --- 1. Puntero a struct y operador -> --- */
    Punto p = {3.0f, 4.0f};
    Punto *ptr = &p;

    printf("Punto original: ");
    imprimirPunto(&p);

    /* Acceder con -> a traves del puntero */
    printf("Via puntero -> x: %.1f, y: %.1f\n", ptr->x, ptr->y);

    /* --- 2. Modificar campos via puntero --- */
    printf("\n=== MOVER PUNTO ===\n");
    moverPunto(&p, 2.5f, -1.0f);
    printf("Punto despues de mover: ");
    imprimirPunto(&p);

    /* --- 3. Cuenta bancaria — operaciones con punteros --- */
    printf("\n=== CUENTA BANCARIA ===\n");

    Cuenta miCuenta = {1001, "Carlos Ruiz", 500.0f};
    imprimirCuenta(&miCuenta);

    depositar(&miCuenta, 200.0f);
    printf("Deposito de 200.00\n");
    imprimirCuenta(&miCuenta);

    retirar(&miCuenta, 150.0f);
    printf("Retiro de 150.00\n");
    imprimirCuenta(&miCuenta);

    /* Intentar retirar mas del saldo */
    retirar(&miCuenta, 9999.0f);
    printf("Intento de retiro invalido (saldo insuficiente)\n");
    imprimirCuenta(&miCuenta);

    /* --- 4. Arreglo de structs y punteros --- */
    printf("\n=== ARREGLO CON PUNTEROS ===\n");

    Punto triangulo[3] = {{0, 0}, {4, 0}, {2, 3}};

    for (int i = 0; i < 3; i++) {
        printf("Vertice %d: ", i + 1);
        imprimirPunto(&triangulo[i]);
    }

    /* Mover todo el triangulo */
    for (int i = 0; i < 3; i++) {
        moverPunto(&triangulo[i], 1.0f, 1.0f);
    }

    printf("\nTriangulo trasladado (dx=1, dy=1):\n");
    for (int i = 0; i < 3; i++) {
        printf("Vertice %d: ", i + 1);
        imprimirPunto(&triangulo[i]);
    }

    return 0;
}

/* Desplaza el punto sumando dx y dy */
void moverPunto(Punto *p, float dx, float dy) {
    p->x += dx;
    p->y += dy;
}

/* Imprime coordenadas de un punto */
void imprimirPunto(const Punto *p) {
    printf("(%.1f, %.1f)\n", p->x, p->y);
}

/* Suma monto al saldo de la cuenta */
void depositar(Cuenta *c, float monto) {
    if (monto > 0) {
        c->saldo += monto;
    }
}

/* Resta monto del saldo si hay fondos suficientes */
void retirar(Cuenta *c, float monto) {
    if (monto > 0 && monto <= c->saldo) {
        c->saldo -= monto;
    } else {
        printf("  [ERROR] Saldo insuficiente o monto invalido\n");
    }
}

/* Imprime datos de la cuenta bancaria */
void imprimirCuenta(const Cuenta *c) {
    printf("  Cuenta #%d | Titular: %-15s | Saldo: $%.2f\n",
           c->numero, c->titular, c->saldo);
}
