# Documentacion de C

C es un lenguaje de programacion de proposito general, compilado y de bajo nivel.
Fue creado por Dennis Ritchie en los anos 70 en Bell Labs. Sirve para escribir
sistemas operativos, compiladores, drivers, software embebido y cualquier programa
que necesite control directo sobre la memoria y el hardware.

## Documentacion recomendada

- [cppreference - lenguaje C](https://en.cppreference.com/w/c/language)
  Es la referencia tecnica mas completa para sintaxis, tipos y reglas del lenguaje.
- [Documentacion de GCC](https://gcc.gnu.org/onlinedocs/)
  GCC es uno de los compiladores mas usados para C en Linux y otros sistemas.

## Temas principales que debes estudiar

1. Tipos de datos:
   definen como se almacenan los valores en memoria (int, float, char, etc.).
2. Operadores:
   permiten realizar calculos, comparaciones y manipulacion de bits.
3. Control de flujo:
   estructuras como if, switch, for y while que deciden que codigo ejecutar.
4. Funciones:
   bloques reutilizables de codigo con parametros y valores de retorno.
5. Arreglos y strings:
   colecciones ordenadas de datos del mismo tipo y manejo de texto.
6. Punteros:
   variables que guardan direcciones de memoria, clave para el poder de C.
7. Structs y enums:
   tipos personalizados para agrupar datos relacionados.
8. Manejo de archivos:
   lectura y escritura de archivos desde tu programa.
9. Memoria dinamica:
   asignacion y liberacion de memoria en tiempo de ejecucion con malloc y free.
10. Preprocesador:
    directivas como #define, #include y #ifdef que se ejecutan antes de compilar.
11. Headers y modularidad:
    separacion de codigo en archivos .h y .c para proyectos escalables.
12. Buenas practicas:
    Makefiles, debugging, testing y arquitectura de proyectos en C.

## Orden recomendado

1. [Sintaxis base de C](https://en.cppreference.com/w/c/language)
   Aqui entiendes la estructura basica del lenguaje y sus reglas.
2. [Tipos y conversiones](https://en.cppreference.com/w/c/language/conversion)
   Aprendes como C maneja valores, tamanos y conversiones entre tipos.
3. [Funciones](https://en.cppreference.com/w/c/language/function_definition)
   Sirven para dividir un programa en partes reutilizables y organizadas.
4. [Punteros](https://en.cppreference.com/w/c/language/pointer)
   Los punteros guardan direcciones de memoria, una de las partes mas importantes
   y delicadas de C.
5. [Memoria dinamica](https://en.cppreference.com/w/c/memory)
   Explica malloc, calloc, realloc y free para manejar memoria en tiempo de ejecucion.
6. [Manejo de archivos](https://en.cppreference.com/w/c/io)
   C permite leer y escribir archivos de forma directa con stdio.

## Ejemplo basico

```c
#include <stdio.h>

int main(void) {
    int edad = 25;
    float altura = 1.75;
    char nombre[] = "Nicaragua";

    printf("Hola, %s!\n", nombre);
    printf("Edad: %d anos\n", edad);
    printf("Altura: %.2f metros\n", altura);

    return 0;
}

```
