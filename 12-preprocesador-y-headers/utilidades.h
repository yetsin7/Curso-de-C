/*
 * ============================================================
 * Modulo 12 -- Preprocesador y Headers
 * Archivo: utilidades.h
 * ============================================================
 *
 * Este header declara prototipos de funciones utilitarias.
 *
 * Un prototipo le dice al compilador:
 *
 *   - como se llama la funcion
 *   - que tipo devuelve
 *   - que parametros recibe
 *
 * El codigo real de la funcion puede estar en el mismo archivo .c o en
 * otro archivo .c. El header permite que varios archivos conozcan esas
 * funciones sin duplicar su implementacion.
 */

#ifndef UTILIDADES_H
#define UTILIDADES_H

/*
 * Imprime un separador visual en consola.
 */
void imprimir_separador(void);

/*
 * Muestra informacion de depuracion con archivo y linea.
 */
void log_debug(const char *archivo, int linea, const char *mensaje);

/*
 * Calcula el factorial de n usando recursion.
 */
long factorial(int n);

/*
 * Determina si un numero es primo.
 *
 * Devuelve 1 si es primo y 0 si no lo es.
 */
int es_primo(int n);

#endif /* UTILIDADES_H */
