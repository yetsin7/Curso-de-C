/*
 * ============================================================
 * Modulo 03 -- Operadores
 * Archivo: 03_operadores_logicos_y_bitwise.c
 * ============================================================
 *
 * Objetivo de este archivo
 * ------------------------
 * Este programa explica dos grupos de operadores:
 *
 *   1. Operadores logicos
 *      Sirven para combinar condiciones verdaderas o falsas.
 *
 *   2. Operadores bitwise
 *      Sirven para trabajar directamente con los bits de un numero.
 *
 * ------------------------------------------------------------
 * Operadores logicos
 * ------------------------------------------------------------
 *
 *   &&  AND logico: verdadero si ambas condiciones son verdaderas.
 *   ||  OR logico:  verdadero si al menos una condicion es verdadera.
 *   !   NOT logico: invierte verdadero/falso.
 *
 * ------------------------------------------------------------
 * Operadores bitwise
 * ------------------------------------------------------------
 *
 *   &   AND bit a bit
 *   |   OR bit a bit
 *   ^   XOR bit a bit
 *   ~   NOT bit a bit
 *   <<  desplazamiento a la izquierda
 *   >>  desplazamiento a la derecha
 *
 * Estos operadores se usan mucho en sistemas, permisos, redes,
 * microcontroladores, drivers y programacion de bajo nivel.
 *
 * ------------------------------------------------------------
 * Compilar
 * ------------------------------------------------------------
 *
 *   gcc -Wall -Wextra -std=c11 -o 03_logicos_bitwise 03_operadores_logicos_y_bitwise.c
 *
 * Ejecutar en Windows:
 *
 *   03_logicos_bitwise.exe
 *
 * Ejecutar en Linux/macOS:
 *
 *   ./03_logicos_bitwise
 *
 */

#include <stdio.h>

/*
 * Funcion auxiliar para mostrar un numero en binario usando 8 bits.
 *
 * No es necesario entender funciones a profundidad todavia. Por ahora,
 * piensa en esta funcion como una herramienta que imprime ceros y unos.
 */
void mostrar_binario(unsigned char num) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

int main(void) {
    printf("=== OPERADORES LOGICOS ===\n");

    int edad = 25;
    int tiene_id = 1;

    /*
     * AND logico: &&
     *
     * Para que el resultado sea verdadero, ambas condiciones deben ser
     * verdaderas.
     */
    printf("edad >= 18 && tiene_id => %d\n", edad >= 18 && tiene_id);

    /*
     * OR logico: ||
     *
     * Para que el resultado sea verdadero, basta con que una condicion
     * sea verdadera.
     */
    printf("edad < 18 || tiene_id  => %d\n", edad < 18 || tiene_id);

    /*
     * NOT logico: !
     *
     * Invierte el valor logico.
     */
    printf("!tiene_id              => %d\n", !tiene_id);

    /*
     * Cortocircuito:
     *
     * En una expresion con &&, si la primera condicion es falsa, C no
     * necesita evaluar la segunda.
     *
     * En una expresion con ||, si la primera condicion es verdadera, C
     * tampoco necesita evaluar la segunda.
     */
    printf("C usa cortocircuito para evitar evaluaciones innecesarias.\n");

    printf("\n=== OPERADORES BITWISE ===\n");

    /*
     * Estos numeros estan escritos en binario usando el prefijo 0b.
     *
     * Cada posicion representa un bit. Un bit solo puede ser 0 o 1.
     */
    unsigned char a = 0b10101010;
    unsigned char b = 0b11001100;

    printf("a = ");
    mostrar_binario(a);
    printf(" (%u)\n", a);

    printf("b = ");
    mostrar_binario(b);
    printf(" (%u)\n", b);

    /*
     * AND bitwise:
     * El resultado tiene 1 solo donde ambos bits son 1.
     */
    printf("a & b = ");
    mostrar_binario(a & b);
    printf(" (%u)\n", (unsigned char)(a & b));

    /*
     * OR bitwise:
     * El resultado tiene 1 donde al menos uno de los bits es 1.
     */
    printf("a | b = ");
    mostrar_binario(a | b);
    printf(" (%u)\n", (unsigned char)(a | b));

    /*
     * XOR bitwise:
     * El resultado tiene 1 donde los bits son diferentes.
     */
    printf("a ^ b = ");
    mostrar_binario(a ^ b);
    printf(" (%u)\n", (unsigned char)(a ^ b));

    /*
     * NOT bitwise:
     * Invierte todos los bits: los 0 se vuelven 1 y los 1 se vuelven 0.
     */
    printf("~a    = ");
    mostrar_binario((unsigned char)~a);
    printf(" (%u)\n", (unsigned char)~a);

    printf("\n=== DESPLAZAMIENTO DE BITS ===\n");

    unsigned char c = 0b00000001;
    printf("c = ");
    mostrar_binario(c);
    printf(" (%u)\n", c);

    /*
     * Desplazar a la izquierda mueve los bits hacia la izquierda.
     * En muchos casos equivale a multiplicar por potencias de 2.
     */
    printf("c << 3 = ");
    mostrar_binario((unsigned char)(c << 3));
    printf(" (%u)\n", (unsigned char)(c << 3));

    unsigned char d = 0b10000000;
    printf("d = ");
    mostrar_binario(d);
    printf(" (%u)\n", d);

    /*
     * Desplazar a la derecha mueve los bits hacia la derecha.
     * En muchos casos equivale a dividir entre potencias de 2.
     */
    printf("d >> 4 = ");
    mostrar_binario((unsigned char)(d >> 4));
    printf(" (%u)\n", (unsigned char)(d >> 4));

    printf("\n=== MANIPULACION DE BANDERAS ===\n");

    /*
     * Una bandera es un bit usado para representar si una opcion esta
     * activada o desactivada.
     *
     * Aqui cada permiso usa un bit diferente.
     */
    unsigned char LECTURA = 0b00000001;
    unsigned char ESCRITURA = 0b00000010;
    unsigned char EJECUCION = 0b00000100;

    unsigned char permisos = 0;

    printf("Permisos iniciales: ");
    mostrar_binario(permisos);
    printf("\n");

    /* Activar banderas con OR. */
    permisos |= LECTURA;
    permisos |= ESCRITURA;

    printf("Con lectura y escritura: ");
    mostrar_binario(permisos);
    printf(" (%u)\n", permisos);

    /* Verificar banderas con AND. */
    printf("Tiene lectura?   %d\n", (permisos & LECTURA) != 0);
    printf("Tiene ejecucion? %d\n", (permisos & EJECUCION) != 0);

    /* Desactivar una bandera usando AND con NOT. */
    permisos &= (unsigned char)~LECTURA;

    printf("Despues de quitar lectura: ");
    mostrar_binario(permisos);
    printf(" (%u)\n", permisos);

    return 0;
}
