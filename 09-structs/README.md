# Modulo 09 -- Structs, Union y Enum

Este modulo explica como agrupar y organizar datos relacionados en C.

Hasta ahora has trabajado con variables individuales, arreglos y punteros. Con `struct`, `enum` y `union` puedes crear modelos de datos mas expresivos y programas mejor organizados.

## Objetivo del modulo

Al terminar este modulo deberias poder:

- Crear estructuras con `struct`.
- Agrupar datos relacionados en un solo tipo.
- Usar `typedef` para crear nombres de tipos mas comodos.
- Acceder a campos de un struct usando el operador punto `.`.
- Acceder a campos desde un puntero usando el operador flecha `->`.
- Pasar structs a funciones por valor y por puntero.
- Crear arreglos de structs.
- Usar `enum` para representar opciones, estados o categorias.
- Usar `union` para compartir memoria entre varios tipos posibles.
- Construir un sistema sencillo de inventario.

## Archivos del modulo

- `01_structs_basicas.c`  
  Explica definicion de structs, `typedef`, acceso a campos y arreglos de structs.

- `02_structs_y_punteros.c`  
  Explica punteros a structs, operador flecha `->` y modificacion de datos reales desde funciones.

- `03_enum_y_union.c`  
  Explica enumeraciones para estados/opciones y unions para memoria compartida.

- `04_sistema_inventario.c`  
  Mini-proyecto que usa structs, enum, arreglos, strings, funciones y punteros para crear un inventario simple.

## Como estudiar este modulo

Estudia primero `struct`. Despues aprende como pasar structs por puntero. Finalmente estudia `enum` y `union`, porque son herramientas utiles pero tienen usos mas especificos.

Ruta recomendada:

1. Ejecuta `01_structs_basicas.c`.
2. Observa como se crean y modifican campos.
3. Ejecuta `02_structs_y_punteros.c`.
4. Compara el operador `.` con el operador `->`.
5. Ejecuta `03_enum_y_union.c`.
6. Revisa como `enum` mejora la legibilidad.
7. Ejecuta `04_sistema_inventario.c` y prueba el menu.

## Como compilar

Ejemplo:

```bash
gcc -Wall -Wextra -std=c11 -o 01_structs_basicas 01_structs_basicas.c
```

## Como ejecutar

En Windows:

```bash
01_structs_basicas.exe
```

En Linux o macOS:

```bash
./01_structs_basicas
```

## Diferencia rapida

```c
producto.precio
```

Se usa cuando `producto` es una variable struct normal.

```c
producto_ptr->precio
```

Se usa cuando `producto_ptr` es un puntero a struct.

## Consejo importante

Usa `struct` cuando varios datos pertenecen a la misma cosa.

Ejemplos:

- Un estudiante tiene nombre, edad y notas.
- Un producto tiene nombre, precio y cantidad.
- Un libro tiene titulo, autor y paginas.
- Una cuenta tiene numero, titular y saldo.

Esto hace que el codigo sea mas claro, mas facil de mantener y mas parecido a los problemas reales que quieres resolver.
