# Modulo 05 -- Funciones

Las funciones permiten dividir un programa en piezas reutilizables con una responsabilidad clara. Son esenciales para escribir codigo modular, legible y facil de mantener.

## Archivos del modulo

- `01_funciones_basicas.c` — Definicion, parametros, retorno y prototipos
- `02_paso_por_valor.c` — Paso por valor vs paso por referencia (punteros)
- `03_recursividad.c` — Funciones recursivas: factorial, Fibonacci y la pila de ejecucion
- `04_libreria_matematica.c` — Mini-proyecto: libreria de funciones matematicas
- `05_ejercicios.c` — Ejercicios practicos para repasar todo el modulo

## Como compilar

Cada archivo `.c` tiene su propio `main()` y se compila de forma independiente:

```bash
gcc -Wall -Wextra -std=c11 -o salida archivo.c
```
