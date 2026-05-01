/*
 * ============================================================
 * Modulo 12 -- Preprocesador y Headers
 * Archivo: constantes.h
 * ============================================================
 *
 * Este header contiene constantes y macros reutilizables.
 *
 * Un archivo .h normalmente se usa para declarar cosas que otros archivos
 * .c pueden incluir con #include.
 *
 * En este caso guardamos:
 *
 *   - constantes con #define
 *   - macros funcionales
 *   - una proteccion contra inclusion multiple
 *
 * La proteccion evita que el mismo header sea incluido mas de una vez en
 * el mismo archivo fuente.
 */

#ifndef CONSTANTES_H
#define CONSTANTES_H

/*
 * Constantes numericas.
 *
 * El preprocesador reemplaza estos nombres antes de que el compilador
 * procese el codigo.
 */
#define PI          3.14159265358979
#define MAX_SIZE    100
#define MIN_SIZE    1
#define VERSION     1

/*
 * Macros funcionales.
 *
 * Los parentesis son importantes para evitar errores con expresiones.
 */
#define MIN(a, b)   ((a) < (b) ? (a) : (b))
#define MAX(a, b)   ((a) > (b) ? (a) : (b))
#define SQUARE(x)   ((x) * (x))

/*
 * Macro de conversion de temperatura.
 */
#define CELSIUS_A_FAHRENHEIT(c)  ((c) * 9.0 / 5.0 + 32.0)

#endif /* CONSTANTES_H */
