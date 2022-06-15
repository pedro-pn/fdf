SOURCES = main.c bresenham_1.c bresenham_2.c my_mlx_pixel_put.c
NAME = fdf.out
LIBFT = ./libft/libft.a
SRCS_PATH = srcs
OBJS_PATH = objs
SRCS = ${addprefix ${SRCS_PATH}/, ${SOURCES}}
OBJS = ${addprefix ${OBJS_PATH}/, ${SOURCES:.c=.o}}
FLAGS = -Wall -Werror -Wextra -g
CC = gcc

all:	${NAME}

${OBJS_PATH}/%.o:	${SRCS_PATH}/%.c
					@ mkdir -p objs
					$(CC) ${FLAGS} -I./libft/include -I./include -I/usr/include -Imlx_linux -O3\
					-c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) ${LIBFT} -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

${LIBFT}:
		make -C ./libft

clean:
		rm -rf ${OBJS_PATH}

fclean: clean
		make fclean -C ./libft
		rm -f ${NAME}
