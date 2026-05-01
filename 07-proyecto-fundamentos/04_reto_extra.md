# Reto Extra: Sistema de Notas

Este reto sirve para comprobar si ya puedes unir varios fundamentos de C en un solo programa.

Vas a crear un programa llamado `reto_sistema_notas.c` que gestione las notas de varios estudiantes y genere un reporte final.

## Objetivo del reto

El objetivo no es solo que el programa funcione. Tambien debe estar ordenado, ser facil de leer y usar funciones para separar la logica.

Este reto combina:

- variables
- constantes con `#define`
- arreglos
- bucles
- condicionales
- funciones
- salida formateada con `printf`

## Requisitos principales

Tu programa debe hacer lo siguiente:

1. Guardar las notas de 5 estudiantes en un arreglo.
2. Calcular el promedio general del grupo.
3. Encontrar la nota mas alta.
4. Encontrar la nota mas baja.
5. Clasificar cada nota usando esta escala:

| Nota | Categoria |
|---|---|
| 90 a 100 | A |
| 80 a 89 | B |
| 70 a 79 | C |
| 60 a 69 | D |
| Menor que 60 | F |

6. Imprimir un reporte formateado con toda la informacion.

## Ejemplo de salida esperada

```txt
=== REPORTE DE NOTAS ===

Estudiante 1: 85.0 -> B
Estudiante 2: 92.5 -> A
Estudiante 3: 78.0 -> C
Estudiante 4: 65.0 -> D
Estudiante 5: 55.0 -> F

-------------------------
Promedio general: 75.1
Nota mas alta: 92.5 (Estudiante 2)
Nota mas baja: 55.0 (Estudiante 5)
=========================
```

## Funciones recomendadas

Puedes organizar tu programa con funciones como estas:

```c
double calcular_promedio(const double notas[], int cantidad);
int indice_nota_mas_alta(const double notas[], int cantidad);
int indice_nota_mas_baja(const double notas[], int cantidad);
char clasificar_nota(double nota);
void imprimir_reporte(const double notas[], int cantidad);
```

No tienes que usar exactamente esos nombres, pero si es recomendable separar el trabajo en funciones pequenas.

## Pistas

- Usa `#define CANTIDAD_ESTUDIANTES 5` para evitar numeros magicos.
- Usa un arreglo `double notas[]` para guardar notas con decimales.
- Usa un `for` para recorrer todas las notas.
- Usa `if`, `else if` y `else` para clasificar.
- Guarda los indices de la nota mayor y menor, no solo sus valores.
- Compila seguido para detectar errores temprano.

## Comando de compilacion

```bash
gcc -Wall -Wextra -std=c11 reto_sistema_notas.c -o sistema_notas
```

## Ejecucion

En Windows:

```bash
sistema_notas.exe
```

En Linux o macOS:

```bash
./sistema_notas
```

## Bonus opcional

Cuando termines la version basica, intenta agregar estas mejoras:

- Contar cuantos estudiantes hay en cada categoria: A, B, C, D y F.
- Calcular el porcentaje de estudiantes aprobados.
- Ordenar las notas de mayor a menor antes de imprimirlas.
- Permitir que el usuario escriba las notas con `scanf`.
- Validar que cada nota este entre 0 y 100.

## Criterio para saber si lo hiciste bien

Tu programa esta bien encaminado si:

- Compila sin errores.
- Usa funciones.
- No repite codigo innecesariamente.
- Usa nombres claros.
- El reporte final es facil de leer.
- Puedes explicar que hace cada parte del codigo.
