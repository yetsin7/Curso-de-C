# Modulo 01 -- Introduccion a C

Este modulo es la puerta de entrada al lenguaje C. Esta pensado para una persona que nunca ha programado o que todavia no entiende bien como un archivo de codigo se convierte en un programa que la computadora puede ejecutar.

Aqui aprenderas lo mas importante antes de avanzar: que es un programa en C, como se compila, como se ejecuta, que es una variable y como mostrar informacion en la consola.

## Objetivo del modulo

Al terminar este modulo deberias poder:

- Reconocer la estructura basica de un programa en C.
- Entender para que sirve `#include <stdio.h>`.
- Entender que la ejecucion empieza en `main()`.
- Usar `printf()` para mostrar texto y valores.
- Crear variables basicas con `int`, `float`, `double` y `char`.
- Compilar un archivo `.c` usando `gcc`.
- Ejecutar el programa generado en Windows, Linux o macOS.

## Archivos del modulo

- `01_estructura_basica.c`  
  Explica la estructura minima de un programa en C: librerias, `main()`, `printf()` y `return 0`.

- `02_compilar_y_ejecutar.c`  
  Explica que significa compilar, que es un ejecutable y como usar comandos basicos de GCC.

- `03_primeras_variables.c`  
  Introduce las primeras variables y los tipos basicos: `int`, `float`, `double` y `char`.

- `04_calculadora_simple.c`  
  Une variables, operaciones matematicas y `printf()` en una calculadora sencilla.

- `05_ejercicios.c`  
  Contiene ejercicios guiados para practicar lo aprendido en el modulo.

## Como estudiar este modulo

Estudia los archivos en orden. No saltes directamente a los ejercicios si todavia no entiendes los archivos anteriores.

Ruta recomendada:

1. Lee el archivo completo.
2. Compilalo.
3. Ejecutalo.
4. Cambia un valor pequeno.
5. Vuelve a compilar.
6. Observa que cambio en la salida.

Ese proceso es importante porque programar no es solo leer: tambien hay que probar, equivocarse y corregir.

## Como compilar un archivo

Ejemplo con el primer archivo:

```bash
gcc -Wall -Wextra -std=c11 -o estructura_basica 01_estructura_basica.c
```

## Como ejecutar

En Windows:

```bash
estructura_basica.exe
```

En Linux o macOS:

```bash
./estructura_basica
```

## Consejo importante

Usa siempre:

```bash
-Wall -Wextra
```

Estas opciones hacen que el compilador te avise sobre posibles errores. Al principio pueden parecer molestas, pero ayudan mucho a aprender correctamente.
