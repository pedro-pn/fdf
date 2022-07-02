SOURCES = main.c bresenham_1.c bresenham_2.c image.c read_file.c \
			events.c clean.c plot.c error.c start.c color.c utils.c color_2.c \
			menu.c rotation.c mouse.c
NAME = fdf
LIBFT = ./libft/libft.a
INCLUDES = include
SRCS_PATH = srcs
OBJS_PATH = objs
SRCS = ${addprefix ${SRCS_PATH}/, ${SOURCES}}
OBJS = ${addprefix ${OBJS_PATH}/, ${SOURCES:.c=.o}}
FLAGS = -Wall -Werror -Wextra
CC = gcc

# Colors
GREEN =	\033[0;32m
L_CYAN = \33[1;36m
L_BLUE = \33[1;34m
NC = \033[0m


all:	${NAME}

${OBJS_PATH}/%.o:	${SRCS_PATH}/%.c
					@ echo "Compiling: $<"
					@ mkdir -p objs
					@ $(CC) ${FLAGS} -I ./libft/include -I ./${INCLUDES} -Imlx_linux \
					-c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	 @ $(CC) $(OBJS) ${LIBFT} -Lmlx_linux -lmlx_Linux -lXext -lX11 -lm -o $(NAME)
	 @ echo "$(GREEN)Done!${NC}"

${LIBFT}:
		@ echo "Compiling Libft..."
		@ make -C ./libft --no-print-directory
		@ echo "Libft successfully compiled!"

clean:
		@ rm -rf ${OBJS_PATH}
		@ echo "$(L_CYAN)Objects deleted!${NC}"

fclean: clean
		@ make fclean -C ./libft --no-print-directory
		@ rm -f ${NAME}
		@ echo "${L_BLUE}Program deleted!${NC}"

re: clean all

.PHONY: all clean fclean re

norma:
		@ norminette ${SRCS} ${INCLUDES}