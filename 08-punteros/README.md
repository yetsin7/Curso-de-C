# Modulo 08 -- Punteros

Este modulo explica uno de los temas mas importantes de C: los punteros.

Un puntero es una variable que guarda una direccion de memoria. Esto permite trabajar directamente con los datos donde realmente viven en memoria.

Los punteros pueden parecer dificiles al inicio, pero son fundamentales para entender C de verdad.

## Objetivo del modulo

Al terminar este modulo deberias poder:

- Entender que es una direccion de memoria.
- Declarar punteros correctamente.
- Usar `&` para obtener la direccion de una variable.
- Usar `*` para acceder al valor apuntado.
- Entender que significa desreferenciar un puntero.
- Usar `NULL` para representar un puntero que no apunta a nada valido.
- Imprimir direcciones con `%p`.
- Recorrer arreglos usando punteros.
- Entender la aritmetica de punteros.
- Usar punteros a funciones.
- Entender dobles punteros.
- Reservar y liberar memoria para una matriz dinamica sencilla.

## Archivos del modulo

- `01_punteros_basicos.c`  
  Explica que es un puntero, como usar `&`, como usar `*`, que es `NULL` y como imprimir direcciones de memoria.

- `02_aritmetica_punteros.c`  
  Explica como avanza un puntero segun el tipo al que apunta, como recorrer arreglos con punteros y como funcionan los punteros `const`.

- `03_punteros_a_funciones.c`  
  Explica como guardar funciones en punteros, usar callbacks y crear una tabla de operaciones.

- `04_dobles_punteros.c`  
  Explica punteros a punteros, modificacion de direcciones y una introduccion a matrices dinamicas.

## Como estudiar este modulo

No intentes memorizar todo en una sola lectura. Los punteros se entienden mejor con practica visual y ejemplos pequenos.

Ruta recomendada:

1. Ejecuta `01_punteros_basicos.c`.
2. Observa las direcciones que imprime.
3. Cambia valores y revisa como `*puntero` modifica la variable original.
4. Estudia aritmetica de punteros con arreglos.
5. Estudia punteros a funciones solo despues de entender punteros normales.
6. Estudia dobles punteros al final.

## Como compilar

Ejemplo:

```bash
gcc -Wall -Wextra -std=c11 -o 01_basicos 01_punteros_basicos.c
```

## Como ejecutar

En Windows:

```bash
01_basicos.exe
```

En Linux o macOS:

```bash
./01_basicos
```

## Reglas de seguridad con punteros

- Nunca desreferencies un puntero `NULL`.
- Inicializa tus punteros antes de usarlos.
- No accedas fuera de los limites de un arreglo.
- Si reservas memoria con `malloc`, liberala con `free`.
- Despues de liberar memoria, evita seguir usando ese puntero.
- Usa nombres claros para saber que apunta cada puntero.

## Consejo importante

Piensa en un puntero como una direccion escrita en un papel.

El papel no es la casa. El papel solo contiene la direccion de la casa.

De la misma forma, un puntero no es el dato directamente. El puntero guarda donde esta el dato.
