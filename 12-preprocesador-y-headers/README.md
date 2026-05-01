# Modulo 12 -- Preprocesador y Headers

Este modulo explica el preprocesador de C y el uso de archivos header `.h`.

El preprocesador es una etapa que ocurre antes de la compilacion real. Trabaja sobre el texto del codigo fuente y puede reemplazar macros, incluir archivos, activar o desactivar bloques de codigo y proteger headers contra inclusion multiple.

## Objetivo del modulo

Al terminar este modulo deberias poder:

- Entender que hace el preprocesador.
- Crear constantes con `#define`.
- Crear macros funcionales.
- Usar macros predefinidas como `__FILE__`, `__LINE__`, `__DATE__` y `__TIME__`.
- Usar `#ifdef`, `#ifndef`, `#if`, `#elif`, `#else` y `#endif`.
- Compilar con macros definidas desde la terminal usando `-D`.
- Crear headers `.h`.
- Usar include guards para evitar inclusion multiple.
- Separar prototipos, constantes e implementaciones.
- Entender la base de la programacion modular en C.

## Archivos del modulo

- `constantes.h`  
  Header con constantes, macros funcionales y proteccion contra inclusion multiple.

- `utilidades.h`  
  Header con prototipos de funciones utilitarias.

- `01_macros_y_defines.c`  
  Explica `#define`, macros funcionales, macros multilinea, `#undef` y macros predefinidas.

- `02_compilacion_condicional.c`  
  Explica compilacion condicional, modo debug, deteccion de plataforma y macros definidas por linea de comandos.

- `03_include_guards.c`  
  Explica include guards y muestra como usar headers propios sin problemas de inclusion multiple.

- `04_proyecto_modular.c`  
  Mini-proyecto que usa `constantes.h` y `utilidades.h` para demostrar programacion modular.

## Como estudiar este modulo

Estudia primero las macros simples. Luego aprende la compilacion condicional. Despues revisa los headers y termina con el proyecto modular.

Ruta recomendada:

1. Lee `constantes.h` y `utilidades.h`.
2. Ejecuta `01_macros_y_defines.c`.
3. Ejecuta `02_compilacion_condicional.c` en modo normal.
4. Compila `02_compilacion_condicional.c` con `-DDEBUG`.
5. Ejecuta `03_include_guards.c`.
6. Ejecuta `04_proyecto_modular.c`.

## Como compilar

Archivos individuales:

```bash
gcc -Wall -Wextra -std=c11 -o 01_macros 01_macros_y_defines.c
gcc -Wall -Wextra -std=c11 -o 02_condicional 02_compilacion_condicional.c
gcc -Wall -Wextra -std=c11 -o 03_guards 03_include_guards.c
gcc -Wall -Wextra -std=c11 -o 04_modular 04_proyecto_modular.c
```

Compilar con modo debug activado:

```bash
gcc -Wall -Wextra -std=c11 -DDEBUG -o 02_condicional_debug 02_compilacion_condicional.c
```

Compilar con una macro personalizada:

```bash
gcc -Wall -Wextra -std=c11 -DNIVEL_OPT=3 -o 02_condicional 02_compilacion_condicional.c
```

## Como ejecutar

En Windows:

```bash
01_macros.exe
02_condicional.exe
02_condicional_debug.exe
03_guards.exe
04_modular.exe
```

En Linux o macOS:

```bash
./01_macros
./02_condicional
./02_condicional_debug
./03_guards
./04_modular
```

## Include guards

Un include guard tiene esta forma:

```c
#ifndef MI_HEADER_H
#define MI_HEADER_H

/* contenido del header */

#endif
```

Esto evita que el mismo header se procese mas de una vez.

## Consejo importante

No abuses de las macros. Una macro no es una funcion normal: el preprocesador reemplaza texto antes de compilar. Por eso los parentesis son muy importantes.

Ejemplo recomendado:

```c
#define SQUARE(x) ((x) * (x))
```

Evita esto:

```c
#define SQUARE(x) x * x
```

La segunda version puede fallar con expresiones como `SQUARE(2 + 3)`.
