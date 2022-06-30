SOURCES = main.c bresenham_1.c bresenham_2.c image.c read_file.c \
			events.c clean.c plot.c error.c start.c color.c utils.c color_2.c \
			menu.c rotation.c
NAME = fdf
LIBFT = ./libft/libft.a
INCLUDES = include
SRCS_PATH = srcs
OBJS_PATH = objs
SRCS = ${addprefix ${SRCS_PATH}/, ${SOURCES}}
OBJS = ${addprefix ${OBJS_PATH}/, ${SOURCES:.c=.o}}
FLAGS = -Wall -Werror -Wextra -g
CC = gcc
#-D X=${X_AMB} -D Y=${Y_AMB} -D XK=${XK_AMB} -D YK=${YK_AMB}

all:	${NAME}

${OBJS_PATH}/%.o:	${SRCS_PATH}/%.c
					@ mkdir -p objs
					@ $(CC) ${FLAGS} -I./libft/include -I./${INCLUDES} -I/usr/include -Imlx_linux -O3\
					-c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	 @ $(CC) $(OBJS) ${LIBFT} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

${LIBFT}:
		make -C ./libft

clean:
		@ rm -rf ${OBJS_PATH}

fclean: clean
		make fclean -C ./libft
		rm -f ${NAME}

re: clean all

.PHONY: all clean fclean re

norma:
		@ norminette ${SRCS} ${INCLUDES}