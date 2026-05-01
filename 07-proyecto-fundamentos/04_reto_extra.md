# Reto Extra: Sistema de Notas

Crea un programa completo que gestione las notas de estudiantes.

## Requisitos

Tu programa debe:

1. **Almacenar** las notas de 5 estudiantes en un arreglo
2. **Calcular** el promedio general del grupo
3. **Determinar** quien tiene la nota mas alta y la mas baja
4. **Clasificar** las notas segun la siguiente escala:
   - **A**: 90-100
   - **B**: 80-89
   - **C**: 70-79
   - **D**: 60-69
   - **F**: menor a 60
5. **Imprimir** un reporte formateado con toda la informacion

## Ejemplo de salida esperada

```
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

## Pistas

- Usa arreglos para almacenar las notas
- Usa bucles para recorrer el arreglo
- Usa condicionales para clasificar las notas
- Usa funciones para separar la logica (calcular promedio, clasificar, etc.)
- Usa `#define` para la cantidad de estudiantes

## Comando de compilacion

```bash
gcc -Wall -Wextra -std=c11 reto_sistema_notas.c -o sistema_notas
```

## Bonus (opcional)

- Agrega un contador de estudiantes por cada categoria (A, B, C, D, F)
- Calcula el porcentaje de aprobados (nota >= 60)
- Ordena las notas de mayor a menor antes de imprimir
