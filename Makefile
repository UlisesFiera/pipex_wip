NAME 					= pipex

LIBFT					= ./libft/libft.a

CC						= gcc

STD_FLAGS				= -Wall -Wextra -Werror

SRCS					= src/main.c \
						  src/ft_free_tab.c \
						  src/ft_getenv.c \
						  src/ft_getpath.c \

OBJS					= ${SRCS:.c=.o}

REMOVE					= rm -f ${OBJS}; rm -f pipex; rm -f *.out

all:					${LIBFT} ${NAME}

${NAME}:
						${CC} ${SRCS} ${LIBFT} ${STD_FLAGS} -o ${NAME}

${LIBFT}:				
						make bonus -C ./libft

clean:
						${REMOVE}

fclean:					clean
						make fclean -C ./libft
						
re:						clean all

.PHONY:					all clean fclean re