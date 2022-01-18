NAME = push_swap

SRCS_PATH = srcs/

SRCS_NAME =		get_node.c \
				init_stack.c \
				main.c \
				minmax_sort.c \
				parse_indexes.c \
				push.c \
				put_on.c \
				r_rotate.c \
				rotate.c \
				sort.c \
				stack_utils.c \
				swap.c \
				utils.c

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: ${NAME}
${NAME}: ${OBJS}
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

clean:
	@${MAKE} -C ./libft fclean
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all
