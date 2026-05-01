/*
 * utilidades.h -- Prototipos de funciones utilitarias del modulo 12
 * Declara funciones que se implementan en otros archivos .c
 */

#ifndef UTILIDADES_H
#define UTILIDADES_H

/* Imprime un separador visual en consola */
void imprimir_separador(void);

/* Muestra informacion de depuracion con archivo y linea */
void log_debug(const char *archivo, int linea, const char *mensaje);

/* Calcula el factorial de n (recursivo) */
long factorial(int n);

/* Determina si un numero es primo */
int es_primo(int n);

#endif /* UTILIDADES_H */
