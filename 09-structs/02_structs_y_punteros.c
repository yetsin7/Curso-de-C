/*
 * ============================================================
 * Modulo 09 -- Structs, Union y Enum
 * Archivo: 02_structs_y_punteros.c
 * ============================================================
 *
 * Este archivo explica como usar punteros con structs.
 *
 * Cuando pasas un struct completo a una funcion, C crea una copia.
 * Si el struct es grande, esa copia puede ser costosa.
 *
 * Por eso muchas veces se pasa la direccion del struct usando un puntero.
 * Asi la funcion puede leer o modificar el struct original.
 *
 * Operadores importantes:
 *
 *   .   accede a campos de una variable struct normal.
 *   ->  accede a campos usando un puntero a struct.
 *
 * Compilar:
 *   gcc -Wall -Wextra -std=c11 -o 02_structs_y_punteros 02_structs_y_punteros.c
 *
 * Ejecutar:
 *   Windows: 02_structs_y_punteros.exe
 *   Linux/macOS: ./02_structs_y_punteros
 */

#include <stdio.h>
#include <string.h>

/*
 * Punto representa una coordenada en dos dimensiones.
 */
typedef struct {
    float x;
    float y;
} Punto;

/*
 * Cuenta representa una cuenta bancaria sencilla.
 */
typedef struct {
    int numero;
    char titular[50];
    float saldo;
} Cuenta;

void moverPunto(Punto *p, float dx, float dy);
void imprimirPunto(const Punto *p);
void depositar(Cuenta *c, float monto);
void retirar(Cuenta *c, float monto);
void imprimirCuenta(const Cuenta *c);

int main(void) {
    printf("=== STRUCTS Y PUNTEROS ===\n\n");

    /*
     * p es una variable struct normal.
     * ptr guarda la direccion de p.
     */
    Punto p = {3.0f, 4.0f};
    Punto *ptr = &p;

    printf("Punto original: ");
    imprimirPunto(&p);

    /*
     * ptr->x significa lo mismo que (*ptr).x.
     *
     * El operador flecha es mas comodo y legible.
     */
    printf("Via puntero -> x: %.1f, y: %.1f\n", ptr->x, ptr->y);

    printf("\n=== MOVER PUNTO ===\n");

    /*
     * Enviamos la direccion de p para que la funcion modifique el punto real.
     */
    moverPunto(&p, 2.5f, -1.0f);

    printf("Punto despues de mover: ");
    imprimirPunto(&p);

    printf("\n=== CUENTA BANCARIA ===\n");

    Cuenta miCuenta = {1001, "Carlos Ruiz", 500.0f};

    imprimirCuenta(&miCuenta);

    depositar(&miCuenta, 200.0f);
    printf("Deposito de 200.00\n");
    imprimirCuenta(&miCuenta);

    retirar(&miCuenta, 150.0f);
    printf("Retiro de 150.00\n");
    imprimirCuenta(&miCuenta);

    retirar(&miCuenta, 9999.0f);
    printf("Intento de retiro invalido\n");
    imprimirCuenta(&miCuenta);

    printf("\n=== ARREGLO CON PUNTEROS ===\n");

    Punto triangulo[3] = {{0, 0}, {4, 0}, {2, 3}};

    for (int i = 0; i < 3; i++) {
        printf("Vertice %d: ", i + 1);
        imprimirPunto(&triangulo[i]);
    }

    /*
     * Mover todos los puntos del triangulo.
     */
    for (int i = 0; i < 3; i++) {
        moverPunto(&triangulo[i], 1.0f, 1.0f);
    }

    printf("\nTriangulo trasladado:\n");

    for (int i = 0; i < 3; i++) {
        printf("Vertice %d: ", i + 1);
        imprimirPunto(&triangulo[i]);
    }

    return 0;
}

/*
 * Mueve un punto sumando dx a x y dy a y.
 */
void moverPunto(Punto *p, float dx, float dy) {
    p->x += dx;
    p->y += dy;
}

/*
 * Imprime un punto.
 *
 * Usa const porque esta funcion no debe modificar el punto.
 */
void imprimirPunto(const Punto *p) {
    printf("(%.1f, %.1f)\n", p->x, p->y);
}

/*
 * Deposita dinero en una cuenta si el monto es positivo.
 */
void depositar(Cuenta *c, float monto) {
    if (monto > 0) {
        c->saldo += monto;
    }
}

/*
 * Retira dinero si el monto es positivo y hay saldo suficiente.
 */
void retirar(Cuenta *c, float monto) {
    if (monto > 0 && monto <= c->saldo) {
        c->saldo -= monto;
    } else {
        printf("  [ERROR] Saldo insuficiente o monto invalido\n");
    }
}

/*
 * Imprime los datos de una cuenta.
 */
void imprimirCuenta(const Cuenta *c) {
    printf("  Cuenta #%d | Titular: %-15s | Saldo: $%.2f\n",
           c->numero, c->titular, c->saldo);
}
