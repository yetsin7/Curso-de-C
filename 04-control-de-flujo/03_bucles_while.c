/*
 * ============================================================
 * Modulo 04 -- Control de Flujo
 * Archivo: 03_bucles_while.c
 * ============================================================
 *
 * Este archivo explica los bucles while y do-while en C.
 *
 * Un bucle while repite instrucciones mientras una condicion sea
 * verdadera.
 *
 * Un bucle do-while tambien repite instrucciones, pero garantiza que
 * el bloque se ejecute al menos una vez.
 *
 * Tambien se muestran break y continue:
 *
 *   break    termina el bucle inmediatamente.
 *   continue salta a la siguiente vuelta del bucle.
 *
 * Compilar:
 *   gcc -Wall -Wextra -std=c11 -o bucles_while 03_bucles_while.c
 *
 * Ejecutar:
 *   Windows: bucles_while.exe
 *   Linux/macOS: ./bucles_while
 */

#include <stdio.h>

int main(void) {
    printf("=== BUCLES WHILE Y DO-WHILE ===\n\n");

    /*
     * while basico.
     *
     * Mientras n sea menor o igual a 100, se suma n y luego n aumenta.
     */
    printf("Suma de 1 a 100 usando while:\n");

    int suma = 0;
    int n = 1;

    while (n <= 100) {
        suma += n;
        n++;
    }

    printf("Resultado: %d\n", suma);

    /*
     * Potencias de 2.
     *
     * Este ejemplo repite hasta que potencia pasa de 1000.
     */
    printf("\nPotencias de 2 hasta 1000:\n");

    int potencia = 1;

    while (potencia <= 1000) {
        printf("%d ", potencia);
        potencia *= 2;
    }
    printf("\n");

    /*
     * do-while.
     *
     * Este tipo de bucle ejecuta el bloque primero y revisa la condicion
     * al final.
     */
    printf("\nValidacion con do-while:\n");

    int numero = 15;

    do {
        printf("Probando numero...\n");
        numero = 5;

        if (numero < 1 || numero > 10) {
            printf("Numero invalido\n");
        }
    } while (numero < 1 || numero > 10);

    printf("Numero valido: %d\n", numero);

    /*
     * do-while con contador.
     */
    printf("\nIteraciones con do-while:\n");

    int contador = 1;

    do {
        printf("Iteracion %d\n", contador);
        contador++;
    } while (contador <= 3);

    /*
     * break.
     *
     * Se usa cuando queremos salir del bucle antes de que la condicion
     * principal termine naturalmente.
     */
    printf("\nBusqueda con break:\n");

    int valor = 1;

    while (valor <= 100) {
        if (valor % 13 == 0) {
            printf("Primer multiplo de 13 encontrado: %d\n", valor);
            break;
        }
        valor++;
    }

    /*
     * continue.
     *
     * Salta el resto del bloque y pasa a la siguiente repeticion.
     */
    printf("\nNumeros impares con continue:\n");

    int i = 1;

    while (i <= 15) {
        if (i % 2 == 0) {
            i++;
            continue;
        }

        printf("%d ", i);
        i++;
    }
    printf("\n");

    /*
     * Adivinanza simulada.
     *
     * Este ejemplo combina while, if, break y un limite de intentos.
     */
    printf("\nJuego de adivinanza simulado:\n");

    int secreto = 7;
    int intento = 1;
    int maxIntentos = 3;

    while (intento <= maxIntentos) {
        int adivinanza = 3 + intento;

        if (adivinanza == secreto) {
            printf("Adivinaste en el intento %d!\n", intento);
            break;
        }

        printf("Intento %d: probaste %d\n", intento, adivinanza);
        intento++;
    }

    if (intento > maxIntentos) {
        printf("Se acabaron los intentos. El numero era %d\n", secreto);
    }

    return 0;
}
