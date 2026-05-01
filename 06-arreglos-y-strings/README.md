# Modulo 06 -- Arreglos y Strings

Este modulo explica como trabajar con colecciones de datos en C.

Hasta ahora muchas variables guardaban un solo valor. Con los arreglos puedes guardar varios valores del mismo tipo bajo un mismo nombre. Con los strings puedes trabajar con texto, que en C se representa como arreglos de caracteres terminados en `\0`.

## Objetivo del modulo

Al terminar este modulo deberias poder:

- Crear y recorrer arreglos de una dimension.
- Acceder a elementos usando indices.
- Modificar elementos dentro de un arreglo.
- Pasar arreglos como parametros a funciones.
- Crear y recorrer matrices de dos dimensiones.
- Entender que un string en C es un arreglo de caracteres.
- Usar funciones de `string.h` como `strlen`, `strcpy`, `strncpy`, `strcat` y `strcmp`.
- Manipular strings con mas seguridad usando buffers y `snprintf`.
- Construir una agenda sencilla usando arreglos y strings.

## Archivos del modulo

- `01_arreglos_unidimensionales.c`  
  Explica declaracion, inicializacion, indices, recorrido, busqueda y promedio en arreglos simples.

- `02_arreglos_multidimensionales.c`  
  Explica matrices, filas, columnas, recorrido con bucles anidados, suma y multiplicacion de matrices.

- `03_strings.c`  
  Explica strings en C, el caracter nulo `\0`, funciones de `string.h` y manejo seguro de buffers.

- `04_agenda_contactos.c`  
  Proyecto practico que usa arreglos, strings, funciones y una estructura simple para crear una agenda de contactos.

- `05_ejercicios.c`  
  Ejercicios guiados para practicar arreglos y strings.

## Como estudiar este modulo

Estudia primero los arreglos de una dimension. Luego pasa a matrices. Finalmente estudia strings, porque en C los strings son arreglos de caracteres.

Ruta recomendada:

1. Ejecuta cada archivo.
2. Observa la salida.
3. Cambia los valores de los arreglos.
4. Intenta acceder a diferentes indices.
5. Revisa cuidadosamente los limites de cada arreglo.

## Como compilar

Ejemplo:

```bash
gcc -Wall -Wextra -std=c11 -o 01_arreglos_unidimensionales 01_arreglos_unidimensionales.c
```

## Como ejecutar

En Windows:

```bash
01_arreglos_unidimensionales.exe
```

En Linux o macOS:

```bash
./01_arreglos_unidimensionales
```

## Consejo importante

En C debes tener mucho cuidado con los limites de los arreglos.

Si un arreglo tiene 5 elementos, sus indices validos son:

```c
0, 1, 2, 3, 4
```

El indice 5 ya esta fuera del arreglo. Acceder fuera de los limites puede causar errores dificiles de encontrar.
