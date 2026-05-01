# Modulo 04 -- Control de Flujo

Este modulo explica como controlar el camino que sigue un programa mientras se ejecuta.

Hasta ahora muchos programas se ejecutaban de arriba hacia abajo. Con el control de flujo, un programa puede tomar decisiones, repetir acciones y responder de forma diferente segun los datos.

## Objetivo del modulo

Al terminar este modulo deberias poder:

- Usar `if`, `else if` y `else` para tomar decisiones.
- Usar `switch` para elegir entre varias opciones.
- Usar `for` cuando sabes cuantas veces quieres repetir algo.
- Usar `while` cuando quieres repetir algo mientras una condicion sea verdadera.
- Usar `do-while` cuando necesitas ejecutar algo al menos una vez.
- Usar `break` para salir de un bucle.
- Usar `continue` para saltar una repeticion.
- Construir un menu interactivo simple.

## Archivos del modulo

- `01_condicionales.c`  
  Explica `if`, `else if`, `else`, `switch`, operador ternario y condiciones anidadas.

- `02_bucle_for.c`  
  Explica el bucle `for`, conteos, tablas de multiplicar y bucles anidados.

- `03_bucles_while.c`  
  Explica `while`, `do-while`, `break`, `continue` y validaciones repetitivas.

- `04_menu_interactivo.c`  
  Proyecto practico que combina menus, funciones, `scanf`, `switch`, `do-while` y validaciones.

- `05_ejercicios.c`  
  Ejercicios guiados para practicar el control de flujo.

## Como estudiar este modulo

Estudia los archivos en orden. Primero entiende las decisiones con `if`, luego los bucles y finalmente el menu interactivo.

Ruta recomendada:

1. Compila cada archivo.
2. Ejecutalo.
3. Cambia los valores de prueba.
4. Observa como cambia el flujo del programa.
5. Resuelve los ejercicios sin copiar directamente las soluciones.

## Como compilar

Ejemplo:

```bash
gcc -Wall -Wextra -std=c11 -o condicionales 01_condicionales.c
```

## Como ejecutar

En Windows:

```bash
condicionales.exe
```

En Linux o macOS:

```bash
./condicionales
```

## Consejo importante

Ten cuidado con los bucles infinitos. Un bucle infinito ocurre cuando la condicion nunca deja de cumplirse.

Ejemplo peligroso:

```c
while (1) {
    printf("Esto nunca termina\n");
}
```

Los bucles infinitos a veces son utiles, pero cuando estas aprendiendo debes evitarlos hasta entender bien como detenerlos.
