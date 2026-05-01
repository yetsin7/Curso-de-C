# Modulo 11 -- Memoria Dinamica

La memoria dinamica permite reservar espacio en el **heap** durante la ejecucion del programa. Esto es esencial para trabajar con estructuras de tamaño variable, listas enlazadas y datos cuyo tamaño no se conoce en tiempo de compilacion.

## Archivos del modulo

- `01_malloc_y_free.c` -- Fundamentos de malloc, sizeof, verificacion de NULL y free
- `02_calloc_y_realloc.c` -- calloc vs malloc, realloc seguro y arreglos que crecen
- `03_lista_enlazada.c` -- Implementacion de lista enlazada con gestion de memoria
- `04_arreglo_dinamico.c` -- Mini-proyecto: estructura reutilizable de arreglo dinamico

## Conceptos clave

### malloc y free

```c
int *arr = malloc(10 * sizeof(int));
if (arr == NULL) { /* siempre verificar */ }
free(arr);
arr = NULL;
```

### calloc y realloc

```c
int *zeros = calloc(10, sizeof(int));   /* inicializa en cero */
int *temp = realloc(arr, 20 * sizeof(int));  /* redimensiona */
```

### Errores comunes

- No verificar si malloc/calloc/realloc devolvieron NULL
- Olvidar liberar memoria (memory leak)
- Usar punteros despues de liberarlos (dangling pointer)
- Liberar la misma memoria dos veces (double free)

## Compilar

Cada archivo se compila de forma independiente:

```bash
gcc -Wall -Wextra -std=c11 -o programa 01_malloc_y_free.c
```
