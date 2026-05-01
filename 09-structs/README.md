# Modulo 09 -- Structs Union y Enum

En este modulo aprenderas a agrupar datos relacionados en C usando `struct`, a compartir memoria con `union` y a dar nombres claros a constantes con `enum`.

## Archivos del modulo

- `01_structs_basicas.c` — Definicion de structs, typedef, acceso a campos y arreglos de structs
- `02_structs_y_punteros.c` — Punteros a structs, operador flecha (->) y paso por referencia
- `03_enum_y_union.c` — Enumeraciones para constantes y union para memoria compartida
- `04_sistema_inventario.c` — Mini-proyecto: sistema de inventario con structs

## Como compilar

Cada archivo se compila de forma independiente:

```
gcc -Wall -Wextra -std=c11 -o nombre_archivo nombre_archivo.c
```

## Temas cubiertos

- `struct` para agrupar datos
- `typedef` para simplificar nombres de tipos
- Acceso con `.` y `->`
- Arreglos de structs
- Punteros a structs y paso por referencia
- `enum` para estados y opciones
- `union` para memoria compartida
- Aplicacion practica: sistema de inventario
