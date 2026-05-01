# Modulo 08 -- Punteros

Los punteros son el concepto mas poderoso y distintivo de C. Permiten manipular direcciones de memoria directamente, lo que hace posible estructuras dinamicas, paso por referencia, callbacks y trabajo cercano al hardware.

## Archivos del modulo

- `01_punteros_basicos.c` -- Direccion de memoria, operadores & y *, puntero NULL, impresion con %p
- `02_aritmetica_punteros.c` -- Aritmetica de punteros, recorrido de arreglos, diferencia entre punteros, const
- `03_punteros_a_funciones.c` -- Punteros a funciones, patrón callback, arreglo de punteros, selector de operaciones
- `04_dobles_punteros.c` -- Puntero a puntero, modificacion de direcciones, preparacion para arreglos 2D

## Ideas clave

1. Un puntero almacena una direccion de memoria, no un valor directo
2. El operador `&` obtiene la direccion de una variable
3. El operador `*` accede al valor almacenado en esa direccion
4. `NULL` indica que un puntero no apunta a nada valido
5. Al sumar 1 a un puntero, avanza `sizeof(tipo)` bytes
6. Los punteros a funciones permiten implementar callbacks y tablas de despacho
7. Un doble puntero (`**`) permite modificar la direccion a la que apunta otro puntero

## Compilar

```bash
gcc -Wall -Wextra -std=c11 -o ejecutable archivo.c
```

## Errores comunes

- Desreferenciar un puntero NULL
- Usar punteros no inicializados
- Escribir fuera de los limites de memoria reservada
- Confundir la direccion con el valor almacenado
