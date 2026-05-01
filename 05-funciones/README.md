# Modulo 05 -- Funciones

Este modulo explica como organizar programas en C usando funciones.

Una funcion es un bloque de codigo con nombre que realiza una tarea especifica. Las funciones permiten dividir un programa grande en partes pequenas, claras y reutilizables.

## Objetivo del modulo

Al terminar este modulo deberias poder:

- Crear funciones propias.
- Entender que es un prototipo de funcion.
- Usar parametros para enviar datos a una funcion.
- Usar `return` para devolver resultados.
- Entender que significa `void`.
- Diferenciar paso por valor y paso por referencia usando punteros.
- Usar funciones recursivas con caso base.
- Organizar funciones relacionadas como una pequena libreria.

## Archivos del modulo

- `01_funciones_basicas.c`  
  Explica definicion de funciones, parametros, retorno, prototipos y funciones `void`.

- `02_paso_por_valor.c`  
  Explica la diferencia entre modificar una copia y modificar una variable real usando punteros.

- `03_recursividad.c`  
  Explica funciones recursivas, caso base, factorial, Fibonacci y pila de ejecucion.

- `04_libreria_matematica.c`  
  Mini-proyecto con funciones matematicas reutilizables.

- `05_ejercicios.c`  
  Ejercicios guiados para practicar funciones.

## Como estudiar este modulo

Estudia primero las funciones simples. Despues entiende paso por valor y punteros. Finalmente estudia recursividad con calma, porque es un concepto poderoso pero puede confundir al inicio.

Ruta recomendada:

1. Lee los prototipos.
2. Observa como se llama cada funcion desde `main()`.
3. Baja a la implementacion de cada funcion.
4. Cambia parametros y observa los resultados.
5. Crea tus propias funciones pequenas.

## Como compilar

Ejemplo:

```bash
gcc -Wall -Wextra -std=c11 -o 01_basicas 01_funciones_basicas.c
```

## Como ejecutar

En Windows:

```bash
01_basicas.exe
```

En Linux o macOS:

```bash
./01_basicas
```

## Consejo importante

Una buena funcion debe hacer una sola cosa claramente. Si una funcion hace demasiadas cosas, probablemente conviene dividirla en funciones mas pequenas.
