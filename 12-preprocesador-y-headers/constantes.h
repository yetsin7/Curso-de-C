/*
 * constantes.h -- Constantes y macros del modulo 12
 * Contiene defines, macros funcionales y proteccion contra inclusion multiple.
 */

#ifndef CONSTANTES_H
#define CONSTANTES_H

/* Constantes numericas fundamentales */
#define PI          3.14159265358979
#define MAX_SIZE    100
#define MIN_SIZE    1
#define VERSION     1

/* Macros funcionales -- los parentesis son esenciales */
#define MIN(a, b)   ((a) < (b) ? (a) : (b))
#define MAX(a, b)   ((a) > (b) ? (a) : (b))
#define SQUARE(x)   ((x) * (x))

/* Macro de conversion */
#define CELSIUS_A_FAHRENHEIT(c)  ((c) * 9.0 / 5.0 + 32.0)

#endif /* CONSTANTES_H */
