# Modulo 11 -- Memoria Dinamica

Este modulo explica como reservar y liberar memoria manualmente en C.

La memoria dinamica permite pedir memoria durante la ejecucion del programa. Esto es necesario cuando no sabes de antemano cuantos datos vas a manejar o cuando necesitas estructuras que crecen, como listas enlazadas o arreglos dinamicos.

## Stack y heap

En C es importante distinguir dos zonas de memoria:

- **Stack**: memoria automatica usada por variables locales normales. Se libera sola cuando termina la funcion.
- **Heap**: memoria reservada manualmente con funciones como `malloc`, `calloc` y `realloc`. Debe liberarse manualmente con `free`.

## Objetivo del modulo

Al terminar este modulo deberias poder:

- Entender que es memoria dinamica.
- Reservar memoria con `malloc`.
- Reservar memoria inicializada en cero con `calloc`.
- Cambiar el tamano de un bloque con `realloc`.
- Liberar memoria con `free`.
- Verificar si una reserva de memoria fallo.
- Evitar memory leaks.
- Evitar dangling pointers.
- Entender una lista enlazada simple.
- Crear un arreglo dinamico reutilizable.

## Archivos del modulo

- `01_malloc_y_free.c`  
  Explica los fundamentos de `malloc`, `sizeof`, verificacion de `NULL`, `free` y asignacion posterior a `NULL`.

- `02_calloc_y_realloc.c`  
  Explica la diferencia entre `calloc` y `malloc`, el patron seguro de `realloc` y arreglos que crecen dinamicamente.

- `03_lista_enlazada.c`  
  Implementa una lista enlazada simple con nodos reservados dinamicamente.

- `04_arreglo_dinamico.c`  
  Mini-proyecto que implementa una estructura reutilizable de arreglo dinamico con capacidad, tamano y crecimiento automatico.

## Como estudiar este modulo

Este modulo requiere cuidado. No avances demasiado rapido. Ejecuta cada archivo y lee bien los comentarios.

Ruta recomendada:

1. Estudia `01_malloc_y_free.c` hasta entender `malloc` y `free`.
2. Estudia `02_calloc_y_realloc.c` para entender inicializacion y redimensionamiento.
3. Estudia `03_lista_enlazada.c` para ver memoria dinamica aplicada a nodos.
4. Estudia `04_arreglo_dinamico.c` para ver un mini-proyecto reutilizable.

## Como compilar

Ejemplo:

```bash
gcc -Wall -Wextra -std=c11 -o 01_malloc_y_free 01_malloc_y_free.c
```

Tambien puedes compilar los demas asi:

```bash
gcc -Wall -Wextra -std=c11 -o 02_calloc_y_realloc 02_calloc_y_realloc.c
gcc -Wall -Wextra -std=c11 -o 03_lista_enlazada 03_lista_enlazada.c
gcc -Wall -Wextra -std=c11 -o 04_arreglo_dinamico 04_arreglo_dinamico.c
```

## Como ejecutar

En Windows:

```bash
01_malloc_y_free.exe
02_calloc_y_realloc.exe
03_lista_enlazada.exe
04_arreglo_dinamico.exe
```

En Linux o macOS:

```bash
./01_malloc_y_free
./02_calloc_y_realloc
./03_lista_enlazada
./04_arreglo_dinamico
```

## Errores comunes

### No verificar malloc, calloc o realloc

```c
int *datos = malloc(10 * sizeof(int));

if (datos == NULL) {
    return 1;
}
```

### Olvidar liberar memoria

Si reservas memoria y nunca llamas a `free`, produces una fuga de memoria.

```c
free(datos);
datos = NULL;
```

### Usar memoria despues de liberarla

Esto se llama dangling pointer.

```c
free(datos);
datos = NULL;
```

### Usar realloc de forma insegura

Evita esto:

```c
datos = realloc(datos, nuevo_tamano);
```

Mejor usa un temporal:

```c
int *temp = realloc(datos, nuevo_tamano);

if (temp != NULL) {
    datos = temp;
}
```

## Consejo importante

Cada vez que uses `malloc`, `calloc` o `realloc`, piensa tambien donde vas a usar `free`.

Una buena regla mental es:

> Si reservas memoria, tambien eres responsable de liberarla.
