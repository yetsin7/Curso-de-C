# Checklist de Fundamentos de C

Usa esta lista para verificar que realmente dominas los conceptos basicos antes de continuar con temas mas avanzados.

La idea no es marcar casillas por marcar. La idea es comprobar que puedes leer, compilar, modificar y explicar tus propios programas.

## 1. Compilacion y ejecucion

- [ ] Puedo abrir una terminal en la carpeta del archivo `.c`.
- [ ] Puedo compilar usando `gcc -Wall -Wextra -std=c11`.
- [ ] Entiendo que compilar convierte el codigo fuente en un ejecutable.
- [ ] Puedo ejecutar el programa en mi sistema operativo.
- [ ] El programa compila sin errores.
- [ ] El programa compila sin advertencias importantes.
- [ ] Se revisar la salida del programa y confirmar si tiene sentido.

## 2. Estructura basica de un programa

- [ ] Entiendo para que sirve `#include <stdio.h>`.
- [ ] Entiendo que `main()` es el punto de entrada del programa.
- [ ] Entiendo que las instrucciones dentro de `main()` se ejecutan en orden.
- [ ] Entiendo para que sirve `return 0`.
- [ ] Puedo escribir un programa pequeno desde cero.

## 3. Variables y tipos de datos

- [ ] Puedo declarar variables con nombres claros.
- [ ] Puedo inicializar variables antes de usarlas.
- [ ] Se cuando usar `int` para numeros enteros.
- [ ] Se cuando usar `float` o `double` para numeros decimales.
- [ ] Se usar `char` para caracteres.
- [ ] Se usar `bool` para verdadero o falso.
- [ ] Entiendo que cada tipo ocupa memoria.
- [ ] Puedo usar `sizeof` para ver el tamano de un tipo.

## 4. Operadores

- [ ] Puedo usar operadores aritmeticos para hacer calculos.
- [ ] Entiendo la diferencia entre division entera y division con decimales.
- [ ] Puedo usar el operador modulo para obtener residuos.
- [ ] Puedo comparar valores con `==`, `!=`, `>`, `<`, `>=` y `<=`.
- [ ] No confundo asignacion `=` con comparacion `==`.
- [ ] Puedo combinar condiciones con `&&`, `||` y `!`.
- [ ] Entiendo el operador ternario en casos simples.

## 5. Control de flujo

- [ ] Puedo usar `if`, `else if` y `else` para tomar decisiones.
- [ ] Puedo usar `switch` para seleccionar entre varias opciones.
- [ ] Puedo usar `for` cuando conozco la cantidad de repeticiones.
- [ ] Puedo usar `while` cuando quiero repetir mientras una condicion se cumpla.
- [ ] Puedo usar `do-while` cuando el bloque debe ejecutarse al menos una vez.
- [ ] Entiendo para que sirven `break` y `continue`.
- [ ] Puedo evitar bucles infinitos accidentales.

## 6. Funciones

- [ ] Puedo crear una funcion con parametros.
- [ ] Puedo crear una funcion que devuelva un valor.
- [ ] Puedo crear una funcion `void`.
- [ ] Entiendo que una funcion debe tener una responsabilidad clara.
- [ ] Puedo usar prototipos de funciones.
- [ ] Entiendo la diferencia entre paso por valor y paso por referencia.
- [ ] Puedo modificar una variable real usando punteros en una funcion sencilla.

## 7. Arreglos y strings

- [ ] Puedo crear un arreglo de enteros.
- [ ] Entiendo que los indices empiezan en 0.
- [ ] Puedo recorrer un arreglo usando `for`.
- [ ] Puedo pasar un arreglo a una funcion.
- [ ] Puedo trabajar con una matriz sencilla.
- [ ] Entiendo que un string en C termina con `\0`.
- [ ] Puedo usar funciones basicas de `string.h`.
- [ ] Entiendo por que debo cuidar el tamano de los buffers.

## 8. Buenas practicas

- [ ] Uso nombres descriptivos para variables y funciones.
- [ ] Mantengo la indentacion ordenada.
- [ ] Escribo comentarios cuando ayudan a entender el codigo.
- [ ] No dejo variables sin usar.
- [ ] No dejo codigo muerto.
- [ ] Cada archivo del curso puede compilarse por separado.
- [ ] Puedo explicar en voz alta que hace mi programa.

## Resultado esperado

Si puedes marcar la mayoria de estas casillas, ya tienes una base solida para avanzar a punteros, structs, archivos y memoria dinamica.

Si varias casillas te causan duda, vuelve a los modulos anteriores y practica con ejemplos pequenos antes de continuar.
