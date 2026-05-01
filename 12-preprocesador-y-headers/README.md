# Modulo 12 -- Preprocesador y Headers

El preprocesador es la primera etapa de la compilacion en C. Transforma el texto fuente antes de que el compilador analice sintaxis, tipos o genere codigo. Comprenderlo es esencial para escribir programas modulares, reutilizables y portables.

## Archivos del modulo

- `constantes.h` -- Header con macros de constantes y funciones simples
- `utilidades.h` -- Header con prototipos de funciones utilitarias
- `01_macros_y_defines.c` -- Constantes, macros funcionales y macros predefinidas
- `02_compilacion_condicional.c` -- Directivas `#ifdef`, `#if`, deteccion de plataforma
- `03_include_guards.c` -- Demostracion de proteccion contra inclusion multiple
- `04_proyecto_modular.c` -- Mini-proyecto que usa ambos headers y demuestra programacion modular

## Como compilar

```bash
# Archivos individuales
gcc -Wall -Wextra -std=c11 -o 01_macros 01_macros_y_defines.c
gcc -Wall -Wextra -std=c11 -o 02_condicional 02_compilacion_condicional.c
gcc -Wall -Wextra -std=c11 -o 03_guards 03_include_guards.c
gcc -Wall -Wextra -std=c11 -o 04_modular 04_proyecto_modular.c

# Con modo debug activado
gcc -Wall -Wextra -std=c11 -DDEBUG -o 02_condicional_debug 02_compilacion_condicional.c
```
