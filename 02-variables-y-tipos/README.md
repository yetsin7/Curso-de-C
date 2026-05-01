# Modulo 02 -- Variables y Tipos de Datos

Este modulo explica con mas detalle los tipos de datos fundamentales en C.

En programacion, una variable es un espacio de memoria con nombre. Ese espacio guarda un valor mientras el programa se esta ejecutando. El tipo de dato le dice al compilador que clase de valor puede guardar esa variable y cuanta memoria necesita.

## Objetivo del modulo

Al terminar este modulo deberias poder:

- Entender que es una variable y por que necesita un tipo.
- Usar tipos enteros como `char`, `short`, `int`, `long` y `long long`.
- Diferenciar entre tipos `signed` y `unsigned`.
- Usar tipos decimales como `float`, `double` y `long double`.
- Entender por que los numeros decimales pueden tener pequenas diferencias de precision.
- Usar `bool` para representar verdadero o falso.
- Usar `char` para representar caracteres.
- Usar `sizeof` para ver cuantos bytes ocupa un tipo.
- Usar un cast para convertir manualmente un valor de un tipo a otro.

## Archivos del modulo

- `01_tipos_enteros.c`  
  Explica los tipos enteros, sus tamanos, sus limites y la diferencia entre `signed` y `unsigned`.

- `02_tipos_flotantes.c`  
  Explica `float`, `double`, `long double`, precision decimal y valores maximos.

- `03_booleanos_y_caracteres.c`  
  Explica `bool`, `true`, `false`, `char`, codigos numericos de caracteres y conversiones de tipo.

- `04_conversor_unidades.c`  
  Proyecto practico que usa varios tipos de datos para convertir temperatura, longitud y peso.

- `05_ejercicios.c`  
  Ejercicios guiados para practicar enteros, flotantes, booleanos, caracteres y casts.

## Como estudiar este modulo

Estudia los archivos en orden. Cada archivo toma un concepto y lo explica con ejemplos.

Ruta recomendada:

1. Lee los comentarios del archivo.
2. Compila el programa.
3. Ejecutalo y observa la salida.
4. Cambia algunos valores.
5. Vuelve a compilar y compara los resultados.

No memorices todos los limites de cada tipo. Lo importante es entender que cada tipo tiene un rango y un tamano.

## Como compilar

Ejemplo:

```bash
gcc -Wall -Wextra -std=c11 -o 01_tipos_enteros 01_tipos_enteros.c
```

## Como ejecutar

En Windows:

```bash
01_tipos_enteros.exe
```

En Linux o macOS:

```bash
./01_tipos_enteros
```

## Consejo importante

Cuando tengas duda sobre el tamano de un tipo, usa `sizeof`. Cuando tengas duda sobre sus limites, revisa las librerias `limits.h` y `float.h`.

Este modulo es clave porque todo programa en C trabaja con datos, y cada dato ocupa memoria.
