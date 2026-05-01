# Modulo 03 -- Operadores

Este modulo explica los operadores de C. Un operador es un simbolo que permite realizar una accion sobre uno o mas valores.

Los operadores son fundamentales porque permiten hacer calculos, comparar datos, combinar condiciones y manipular informacion a nivel de bits.

## Objetivo del modulo

Al terminar este modulo deberias poder:

- Usar operadores aritmeticos para sumar, restar, multiplicar y dividir.
- Entender la diferencia entre division entera y division con decimales.
- Usar el operador modulo para obtener residuos.
- Usar asignacion compuesta como `+=`, `-=`, `*=` y `/=`.
- Usar incremento y decremento con `++` y `--`.
- Comparar valores con `==`, `!=`, `>`, `<`, `>=` y `<=`.
- Entender la diferencia entre `=` y `==`.
- Usar operadores logicos como `&&`, `||` y `!`.
- Conocer operadores a nivel de bits como `&`, `|`, `^`, `~`, `<<` y `>>`.
- Aplicar operadores en un proyecto practico.

## Archivos del modulo

- `01_operadores_aritmeticos.c`  
  Explica suma, resta, multiplicacion, division, modulo, asignacion compuesta, incremento y decremento.

- `02_operadores_comparacion.c`  
  Explica operadores de comparacion, el error comun entre `=` y `==`, y el operador ternario.

- `03_operadores_logicos_y_bitwise.c`  
  Explica operadores logicos y operadores a nivel de bits con ejemplos visuales en binario.

- `04_calculadora_impuestos.c`  
  Proyecto practico que combina operadores aritmeticos, comparaciones, logica y ternarios para calcular descuentos e impuestos.

- `05_ejercicios.c`  
  Ejercicios para practicar los operadores del modulo.

## Como estudiar este modulo

Estudia los archivos en orden. Este modulo tiene conceptos que parecen pequenos, pero son la base de casi toda la logica de programacion.

Ruta recomendada:

1. Ejecuta cada archivo.
2. Observa la salida.
3. Cambia los valores iniciales.
4. Vuelve a compilar.
5. Comprueba como cambia el resultado.

## Como compilar

Ejemplo:

```bash
gcc -Wall -Wextra -std=c11 -o 01_aritmeticos 01_operadores_aritmeticos.c
```

## Como ejecutar

En Windows:

```bash
01_aritmeticos.exe
```

En Linux o macOS:

```bash
./01_aritmeticos
```

## Consejo importante

No confundas asignacion con comparacion:

```c
x = 5;   // asigna 5 a x
x == 5;  // compara si x vale 5
```

Ese error es muy comun al empezar en C. Compilar con `-Wall -Wextra` ayuda a detectarlo.
