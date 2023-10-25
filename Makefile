# nombre programa

NAME = push_swap

# compilador
CC = gcc
# Opciones de compilación
CFLAGS = -g -Wall -Werror -Wextra

# Crea una biblioteca estática utilizando (ar)
# ar -> crea biblioteca
# r -> remplaza o agrega archivos a la biblioteca
# c -> crea biblioteca si no existe
# s -> agrega información de índice a la biblioteca, para acceder más rapido
LIB = ar rcs

# Define la ruta al directorio donde se encuentra libft
LIBFT_DIR = ./Libft

# Ruta completa al archivo de la libreria libft.a
LIBFT = $(LIBFT_DIR)/libft.a

# Define el archivo fuente del programa push_swap
# Agrega aquí todos tus archivos fuente

SRC = push_swap.c push_swap_check_input.c push_swap_make_list.c push_swap_utils.c\
push_swap_moves.c push_swap_3tower.c push_swap_sort_out.c\
push_swap_generic_moves.c push_swap_moves_2.c push_swap_utils_2.c

	
# Define los archivos objeto generados a partir de los fuente
OBJS = $(SRC:.c=.o)
# .SECONDARY: $(OBJS)

BOBJS = $(BONUS:.c=.o)

# Agrega los archivos objeto a la lista de archivos secundarios
all: $(NAME) $(LIBFT)

# Compila la libreria libft. -C se utiliza para cambiar de directorio
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Se utiliza el compilador (CC) con las opciones (CFLAGS) para crear
# el programa (NAME) a partir de los archivos objetos ($^)
# Especificando la ubicación de la libreria (LIBFT_DIR) y se enlaza (lft)
# -o especifica el nombre del archivo de salida
# $@ se refiere al objetivo de la regla, nombre del programa (NAME)
# "-o $@" establece el nombre del archivo de salida como el nombre del programa

# Se utiliza el compilador (CC) con las opciones (CFLAGS) para crear
# el programa (NAME) a partir de los archivos objetos ($^)
# Especificando la ubicación de la libreria (LIBFT_DIR) y se enlaza (lft)
# -o especifica el nombre del archivo de salida
# $@ se refiere al objetivo de la regla, nombre del programa (NAME)
# "-o $@" establece el nombre del archivo de salida como el nombre del programa
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(LIBFT_DIR) -lft -I push_swap.h


# Regla para compilar todos los archivos fuentes .c en archivos objetos .o
# Se utiliza el compilador (CC) con las flags (CFLAGS) para compilar cada archivo
# fuente ($<) en su archivo objeto ($@). Se especifica la ubicación de los archivos
# de inclusión de la libreria libft (-I$(LIBFT_DIR))
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I$(LIBFT_DIR)

# utiliza el comando  make  para ejecutar la regla  clean  en el directorio de la
# librería libft. Esto se utiliza para limpiar los archivos objeto generados 
# durante la compilación de la librería. 
# rm -f $(OBJS) : Aquí se utiliza el comando  rm  para eliminar los archivos objeto generados.

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

# Esta línea establece la regla  fclean  como una dependencia de la regla  clean 
# Esto significa que al ejecutar  make fclean , primero se ejecutará  make clean 
# se utiliza el comando  make  para ejecutar la regla  fclean  en el directorio de la librería libft
# tiliza para limpiar los archivos generados durante la compilación de la librería.
# utiliza el comando  rm  para eliminar el programa generado
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)


# al ejecutar  make re , primero se ejecutará  make fclean  y luego  make all .
re: fclean all

bonus: $(NAME) $(BOBJS)
	@ar rcs $(NAME) $(BOBJS)
	
.PHONY: re all clean fclean 




