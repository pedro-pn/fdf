SOURCES	=	ft_isalpha.c ft_tolower.c ft_toupper.c ft_isdigit.c ft_isalnum.c \
			ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
			ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c get_next_line.c ft_printf.c \
			ft_printf_utils_1.c ft_printf_hexa.c \
			ft_utoa.c ft_printf_utils_2.c \
			ft_printf_utils_3.c ft_printf_utils_4.c
SRCS_PATH = srcs
OBJS_PATH = objs
SRCS = ${addprefix ${SRCS_PATH}/, ${SOURCES}}
OBJS = ${addprefix ${OBJS_PATH}/, ${SOURCES:.c=.o}}
CC = cc
FLAGS = -Werror -Wall -Wextra
NAME = libft.a

all: ${NAME}

${OBJS_PATH}/%.o:	${SRCS_PATH}/%.c
					@ mkdir -p objs
					@ ${CC} ${FLAG} -I include/ -c -o $@ $<

${NAME}: ${OBJS}
		@ ar -rcs ${NAME} ${OBJS}

clean: 
		@ rm -rf ${OBJS_PATH}

fclean: clean
		@ rm -f ${NAME}

norma:
		@ norminette ${SRCS} includes/*

re: fclean all

.PHONY: re clean fclean all norma
