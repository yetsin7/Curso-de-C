/*
 * Modulo 03 -- Operadores Logicos y Bitwise
 * Archivo: 03_operadores_logicos_y_bitwise.c
 *
 * Demuestra operadores logicos y operaciones a nivel de bits:
 *   - Logicos: && (AND), || (OR), ! (NOT)
 *   - Bitwise: & (AND), | (OR), ^ (XOR), ~ (NOT)
 *   - Desplazamiento: << (izquierda), >> (derecha)
 *   - Representacion binaria y manipulacion de banderas
 *
 * Compilar: gcc -Wall -Wextra -std=c11 -o 03_logicos_bitwise 03_operadores_logicos_y_bitwise.c
 */

#include <stdio.h>

/* Funcion auxiliar para mostrar un numero en binario (8 bits) */
void mostrar_binario(unsigned char num) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

int main(void) {
    /* Operadores logicos */
    printf("=== OPERADORES LOGICOS ===\n");

    int edad = 25;
    int tiene_id = 1;  /* 1 = verdadero, 0 = falso */

    /* AND logico: ambas condiciones deben ser verdaderas */
    printf("edad >= 18 && tiene_id => %d\n", edad >= 18 && tiene_id);

    /* OR logico: al menos una condicion debe ser verdadera */
    printf("edad < 18 || tiene_id => %d\n", edad < 18 || tiene_id);

    /* NOT logico: invierte el valor de verdad */
    printf("!tiene_id => %d\n", !tiene_id);

    /* Cortocircuito: si la primera condicion de && es falsa,
       no evalua la segunda. Si la primera de || es verdadera,
       tampoco evalua la segunda */
    printf("Ejemplo de cortocircuito: (0 && algo) nunca evalua 'algo'\n");

    /* Operadores bitwise (a nivel de bits) */
    printf("\n=== OPERADORES BITWISE ===\n");

    unsigned char a = 0b10101010;  /* 170 en decimal */
    unsigned char b = 0b11001100;  /* 204 en decimal */

    printf("a = ");
    mostrar_binario(a);
    printf(" (%d)\n", a);

    printf("b = ");
    mostrar_binario(b);
    printf(" (%d)\n", b);

    /* AND bitwise: 1 solo si AMBOS bits son 1 */
    printf("a & b = ");
    mostrar_binario(a & b);
    printf(" (%d)\n", a & b);

    /* OR bitwise: 1 si AL MENOS UN bit es 1 */
    printf("a | b = ");
    mostrar_binario(a | b);
    printf(" (%d)\n", a | b);

    /* XOR bitwise: 1 solo si los bits son DIFERENTES */
    printf("a ^ b = ");
    mostrar_binario(a ^ b);
    printf(" (%d)\n", a ^ b);

    /* NOT bitwise: invierte TODOS los bits */
    printf("~a    = ");
    mostrar_binario(~a);
    printf(" (%d)\n", (unsigned char)~a);

    /* Desplazamiento de bits */
    printf("\n=== DESPLAZAMIENTO DE BITS ===\n");

    unsigned char c = 0b00000001;  /* 1 */
    printf("c = ");
    mostrar_binario(c);
    printf(" (%d)\n", c);

    printf("c << 3 = ");
    mostrar_binario(c << 3);
    printf(" (%d)  -- desplazar izq multiplica por 2^n\n", c << 3);

    unsigned char d = 0b10000000;  /* 128 */
    printf("d = ");
    mostrar_binario(d);
    printf(" (%d)\n", d);

    printf("d >> 4 = ");
    mostrar_binario(d >> 4);
    printf(" (%d)  -- desplazar der divide entre 2^n\n", d >> 4);

    /* Manipulacion de banderas (flags) con bits */
    printf("\n=== MANIPULACION DE BANDERAS ===\n");

    /* Definicion de banderas como potencias de 2 */
    unsigned char LECTURA    = 0b00000001;  /* bit 0 */
    unsigned char ESCRITURA  = 0b00000010;  /* bit 1 */
    unsigned char EJECUCION  = 0b00000100;  /* bit 2 */

    unsigned char permisos = 0;  /* Sin permisos */
    printf("Permisos inicial: ");
    mostrar_binario(permisos);
    printf("\n");

    /* Activar banderas con OR */
    permisos |= LECTURA;
    permisos |= ESCRITURA;
    printf("Con lectura y escritura: ");
    mostrar_binario(permisos);
    printf(" (%d)\n", permisos);

    /* Verificar si una bandera esta activa con AND */
    printf("Tiene lectura?    %d\n", (permisos & LECTURA) != 0);
    printf("Tiene ejecucion?  %d\n", (permisos & EJECUCION) != 0);

    /* Desactivar una bandera con AND y NOT */
    permisos &= ~LECTURA;
    printf("Sin lectura: ");
    mostrar_binario(permisos);
    printf(" (%d)\n", permisos);

    return 0;
}
