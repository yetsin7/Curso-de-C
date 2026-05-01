# ==============================================================================
# Makefile - Curso de Programacion en C
# ==============================================================================
# Autor: Curso-de-C
# Descripcion: Makefile global para compilar, ejecutar y limpiar todos los
#              modulos del curso de programacion en C.
# Uso: make help  (para ver todos los comandos disponibles)
# ==============================================================================

# Compilador y banderas por defecto
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Extension de ejecutable para Windows
EXT = .exe

# Directorios de modulos
MOD01 = 01-introduccion
MOD02 = 02-variables-y-tipos
MOD03 = 03-operadores
MOD04 = 04-control-de-flujo
MOD05 = 05-funciones
MOD06 = 06-arreglos-y-strings
MOD07 = 07-proyecto-fundamentos
MOD08 = 08-punteros
MOD09 = 09-structs
MOD10 = 10-manejo-de-archivos
MOD11 = 11-memoria-dinamica
MOD12 = 12-preprocesador-y-headers
MOD13 = 13-arquitectura-y-buenas-practicas
MOD14 = 14-proyecto-final-pro

# ==============================================================================
# Archivos fuente por modulo
# ==============================================================================

# Modulo 01: Introduccion a C
SRCS_M01 = $(MOD01)/01_estructura_basica.c \
           $(MOD01)/02_compilar_y_ejecutar.c \
           $(MOD01)/03_primeras_variables.c \
           $(MOD01)/04_calculadora_simple.c \
           $(MOD01)/05_ejercicios.c

# Modulo 02: Variables y tipos de datos
SRCS_M02 = $(MOD02)/01_tipos_enteros.c \
           $(MOD02)/02_tipos_flotantes.c \
           $(MOD02)/03_booleanos_y_caracteres.c \
           $(MOD02)/04_conversor_unidades.c \
           $(MOD02)/05_ejercicios.c

# Modulo 03: Operadores
SRCS_M03 = $(MOD03)/01_operadores_aritmeticos.c \
           $(MOD03)/02_operadores_comparacion.c \
           $(MOD03)/03_operadores_logicos_y_bitwise.c \
           $(MOD03)/04_calculadora_impuestos.c \
           $(MOD03)/05_ejercicios.c

# Modulo 04: Control de flujo
SRCS_M04 = $(MOD04)/01_condicionales.c \
           $(MOD04)/02_bucle_for.c \
           $(MOD04)/03_bucles_while.c \
           $(MOD04)/04_menu_interactivo.c \
           $(MOD04)/05_ejercicios.c

# Modulo 05: Funciones
SRCS_M05 = $(MOD05)/01_funciones_basicas.c \
           $(MOD05)/02_paso_por_valor.c \
           $(MOD05)/03_recursividad.c \
           $(MOD05)/04_libreria_matematica.c \
           $(MOD05)/05_ejercicios.c

# Modulo 06: Arreglos y strings
SRCS_M06 = $(MOD06)/01_arreglos_unidimensionales.c \
           $(MOD06)/02_arreglos_multidimensionales.c \
           $(MOD06)/03_strings.c \
           $(MOD06)/04_agenda_contactos.c \
           $(MOD06)/05_ejercicios.c

# Modulo 07: Proyecto fundamentos
SRCS_M07 = $(MOD07)/01_calculadora_propina.c \
           $(MOD07)/02_adivinanza_numero.c

# Modulo 08: Punteros
SRCS_M08 = $(MOD08)/01_punteros_basicos.c \
           $(MOD08)/02_aritmetica_punteros.c \
           $(MOD08)/03_punteros_a_funciones.c \
           $(MOD08)/04_dobles_punteros.c

# Modulo 09: Structs
SRCS_M09 = $(MOD09)/01_structs_basicas.c \
           $(MOD09)/02_structs_y_punteros.c \
           $(MOD09)/03_enum_y_union.c \
           $(MOD09)/04_sistema_inventario.c

# Modulo 10: Manejo de archivos
SRCS_M10 = $(MOD10)/01_escritura_archivos.c \
           $(MOD10)/02_lectura_archivos.c \
           $(MOD10)/03_archivos_binarios.c \
           $(MOD10)/04_registro_notas.c

# Modulo 11: Memoria dinamica
SRCS_M11 = $(MOD11)/01_malloc_y_free.c \
           $(MOD11)/02_calloc_y_realloc.c \
           $(MOD11)/03_lista_enlazada.c \
           $(MOD11)/04_arreglo_dinamico.c

# Modulo 12: Preprocesador y headers
SRCS_M12 = $(MOD12)/01_macros_y_defines.c \
           $(MOD12)/02_compilacion_condicional.c \
           $(MOD12)/03_include_guards.c \
           $(MOD12)/04_proyecto_modular.c

# Modulo 13: Arquitectura y buenas practicas
SRCS_M13 = $(MOD13)/01_estructura_proyecto.c \
           $(MOD13)/02_manajo_errores.c \
           $(MOD13)/03_debugging.c \
           $(MOD13)/04_gestor_tareas.c

# Modulo 14: Proyecto final profesional
SRCS_M14 = $(MOD14)/01_sistema_biblioteca.c

# Todos los archivos fuente
ALL_SRCS = $(SRCS_M01) $(SRCS_M02) $(SRCS_M03) $(SRCS_M04) \
           $(SRCS_M05) $(SRCS_M06) $(SRCS_M07) $(SRCS_M08) \
           $(SRCS_M09) $(SRCS_M10) $(SRCS_M11) $(SRCS_M12) \
           $(SRCS_M13) $(SRCS_M14)

# Todos los ejecutables
ALL_EXES = $(patsubst %.c,%$(EXT),$(ALL_SRCS))

# ==============================================================================
# Targets principales
# ==============================================================================

# Target por defecto: compila todo
.PHONY: all help clean run mod01 mod02 mod03 mod04 mod05 mod06 mod07 \
        mod08 mod09 mod10 mod11 mod12 mod13 mod14

all: $(ALL_EXES)
	@echo "=== Compilacion completada: todos los modulos ==="

# Muestra ayuda con todos los comandos disponibles
help:
	@echo "========================================================"
	@echo "  Makefile - Curso de Programacion en C"
	@echo "========================================================"
	@echo ""
	@echo "Comandos disponibles:"
	@echo "  make all              - Compila todos los modulos"
	@echo "  make clean            - Elimina todos los archivos .exe"
	@echo "  make run MODULE=<n>   - Compila y ejecuta un modulo"
	@echo "                        Ejemplo: make run MODULE=01-introduccion"
	@echo ""
	@echo "Targets por modulo:"
	@echo "  make mod01            - Modulo 01: Introduccion a C"
	@echo "  make mod02            - Modulo 02: Variables y tipos de datos"
	@echo "  make mod03            - Modulo 03: Operadores"
	@echo "  make mod04            - Modulo 04: Control de flujo"
	@echo "  make mod05            - Modulo 05: Funciones"
	@echo "  make mod06            - Modulo 06: Arreglos y strings"
	@echo "  make mod07            - Modulo 07: Proyecto fundamentos"
	@echo "  make mod08            - Modulo 08: Punteros"
	@echo "  make mod09            - Modulo 09: Structs"
	@echo "  make mod10            - Modulo 10: Manejo de archivos"
	@echo "  make mod11            - Modulo 11: Memoria dinamica"
	@echo "  make mod12            - Modulo 12: Preprocesador y headers"
	@echo "  make mod13            - Modulo 13: Arquitectura y buenas practicas"
	@echo "  make mod14            - Modulo 14: Proyecto final profesional"
	@echo ""
	@echo "Ejemplos de uso:"
	@echo "  make all                           - Compilar todo"
	@echo "  make mod01                         - Compilar modulo 01"
	@echo "  make run MODULE=01-introduccion    - Compilar y ejecutar modulo 01"
	@echo "  make clean                         - Limpiar ejecutables"
	@echo "========================================================"

# ==============================================================================
# Targets por modulo (compilacion individual)
# ==============================================================================

# Modulo 01: Introduccion a C
mod01: $(patsubst %.c,%$(EXT),$(SRCS_M01))
	@echo "=== Modulo 01 compilado ==="

# Modulo 02: Variables y tipos de datos
mod02: $(patsubst %.c,%$(EXT),$(SRCS_M02))
	@echo "=== Modulo 02 compilado ==="

# Modulo 03: Operadores
mod03: $(patsubst %.c,%$(EXT),$(SRCS_M03))
	@echo "=== Modulo 03 compilado ==="

# Modulo 04: Control de flujo
mod04: $(patsubst %.c,%$(EXT),$(SRCS_M04))
	@echo "=== Modulo 04 compilado ==="

# Modulo 05: Funciones
mod05: $(patsubst %.c,%$(EXT),$(SRCS_M05))
	@echo "=== Modulo 05 compilado ==="

# Modulo 06: Arreglos y strings
mod06: $(patsubst %.c,%$(EXT),$(SRCS_M06))
	@echo "=== Modulo 06 compilado ==="

# Modulo 07: Proyecto fundamentos
mod07: $(patsubst %.c,%$(EXT),$(SRCS_M07))
	@echo "=== Modulo 07 compilado ==="

# Modulo 08: Punteros
mod08: $(patsubst %.c,%$(EXT),$(SRCS_M08))
	@echo "=== Modulo 08 compilado ==="

# Modulo 09: Structs
mod09: $(patsubst %.c,%$(EXT),$(SRCS_M09))
	@echo "=== Modulo 09 compilado ==="

# Modulo 10: Manejo de archivos
mod10: $(patsubst %.c,%$(EXT),$(SRCS_M10))
	@echo "=== Modulo 10 compilado ==="

# Modulo 11: Memoria dinamica
mod11: $(patsubst %.c,%$(EXT),$(SRCS_M11))
	@echo "=== Modulo 11 compilado ==="

# Modulo 12: Preprocesador y headers
mod12: $(patsubst %.c,%$(EXT),$(SRCS_M12))
	@echo "=== Modulo 12 compilado ==="

# Modulo 13: Arquitectura y buenas practicas
mod13: $(patsubst %.c,%$(EXT),$(SRCS_M13))
	@echo "=== Modulo 13 compilado ==="

# Modulo 14: Proyecto final profesional
mod14: $(patsubst %.c,%$(EXT),$(SRCS_M14))
	@echo "=== Modulo 14 compilado ==="

# ==============================================================================
# Regla de compilacion generica
# ==============================================================================

# Compila cualquier archivo .c a su ejecutable correspondiente
%$(EXT): %.c
	@echo "Compilando: $<"
	@$(CC) $(CFLAGS) -o $@ $<

# ==============================================================================
# Target para compilar y ejecutar un modulo especifico
# ==============================================================================

# Uso: make run MODULE=01 FILE=01_estructura_basica
# Compila y ejecuta un archivo especifico del modulo
run:
	@echo "=== Ejecutando: $(MODULE)/$(FILE) ==="
	@$(MAKE) $(MODULE)/$(FILE)$(EXT)
	@echo ""
	@echo "=== Salida del programa ==="
	@$(MODULE)/$(FILE)$(EXT)

# ==============================================================================
# Limpieza
# ==============================================================================

# Elimina todos los archivos .exe generados
clean:
	@echo "=== Limpiando archivos ejecutables ==="
	@-del /Q /S *.exe 2>nul
	@echo "=== Limpieza completada ==="
