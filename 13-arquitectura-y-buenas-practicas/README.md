# Modulo 13 -- Arquitectura y Buenas Practicas

Este modulo explica como escribir programas en C mas ordenados, mantenibles y faciles de depurar.

Hasta ahora has aprendido conceptos individuales: variables, funciones, punteros, structs, archivos y memoria dinamica. En este modulo se trabaja la forma de organizar esos conocimientos para construir programas mas profesionales.

## Objetivo del modulo

Al terminar este modulo deberias poder:

- Separar un programa en secciones logicas.
- Distinguir entre capa de datos, capa de logica y capa de presentacion.
- Usar funciones con una sola responsabilidad clara.
- Crear nombres descriptivos para variables, structs y funciones.
- Validar parametros antes de usarlos.
- Usar codigos de retorno para manejar errores.
- Usar `perror` cuando fallan operaciones del sistema.
- Activar o desactivar logs con `-DDEBUG`.
- Usar macros de debugging.
- Construir un mini-proyecto con buenas practicas.

## Archivos del modulo

- `01_estructura_proyecto.c`  
  Explica como organizar un programa en capas simples: datos, logica y presentacion.

- `02_manajo_errores.c`  
  Explica codigos de retorno, validaciones defensivas, mensajes con `perror` y manejo de errores.  
  Nota: el nombre del archivo contiene `manajo`, pero el tema correcto es manejo de errores.

- `03_debugging.c`  
  Explica macros de depuracion, compilacion condicional con `DEBUG`, aserciones y estrategias para diagnosticar problemas.

- `04_gestor_tareas.c`  
  Mini-proyecto que combina arquitectura limpia, manejo de errores, `enum`, structs y modo debug.

## Como estudiar este modulo

Este modulo no se enfoca solo en que el programa funcione. Se enfoca en que el codigo sea entendible, mantenible y seguro.

Ruta recomendada:

1. Ejecuta `01_estructura_proyecto.c` y observa como esta dividido.
2. Ejecuta `02_manajo_errores.c` y revisa como se manejan errores.
3. Ejecuta `03_debugging.c` en modo normal.
4. Compila `03_debugging.c` con `-DDEBUG` y compara la salida.
5. Ejecuta `04_gestor_tareas.c`.
6. Compila `04_gestor_tareas.c` con `-DDEBUG` y observa los logs.

## Como compilar

Modo normal:

```bash
gcc -Wall -Wextra -std=c11 01_estructura_proyecto.c -o 01_estructura
gcc -Wall -Wextra -std=c11 02_manajo_errores.c -o 02_manajo_errores
gcc -Wall -Wextra -std=c11 03_debugging.c -o 03_debugging
gcc -Wall -Wextra -std=c11 04_gestor_tareas.c -o 04_gestor_tareas
```

Modo debug:

```bash
gcc -Wall -Wextra -std=c11 -DDEBUG 03_debugging.c -o 03_debugging
gcc -Wall -Wextra -std=c11 -DDEBUG 04_gestor_tareas.c -o 04_gestor_tareas
```

## Como ejecutar

En Windows:

```bash
01_estructura.exe
02_manajo_errores.exe
03_debugging.exe
04_gestor_tareas.exe
```

En Linux o macOS:

```bash
./01_estructura
./02_manajo_errores
./03_debugging
./04_gestor_tareas
```

## Buenas practicas clave

### 1. Una funcion debe tener una responsabilidad clara

Evita funciones enormes que hacen todo. Es mejor dividir el programa en funciones pequenas.

### 2. Valida antes de usar

Antes de usar punteros, archivos, indices o memoria dinamica, verifica que sean validos.

### 3. Usa nombres descriptivos

Un nombre como `producto_valor_total` explica mejor su proposito que un nombre como `calc`.

### 4. Separa logica de presentacion

No mezcles calculos importantes con impresiones de consola si puedes evitarlo.

### 5. Compila con advertencias

Usa siempre:

```bash
-Wall -Wextra
```

Las advertencias ayudan a detectar errores antes de que se vuelvan problemas grandes.

## Consejo importante

Un programa profesional no solo debe funcionar. Tambien debe ser facil de leer, facil de modificar y facil de depurar.
