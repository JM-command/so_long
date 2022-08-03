NAME	=	so_long
MLX		=	./mlx/
LIBFT_A	=	./libft/libft.a
LIBFT_D	=	./libft/
MLX_A	=	./mlx/libmlx.a
MLX_D	=	./mlx/
SRCS	=	so_long.c malloc_map.c parse_map.c valid_map.c valid2_map.c move.c render.c finish.c deal_key.c texture.c send_error.c render_exit.c
OBJS	=	${SRCS:.c=.o}
CC		=	~/.brew/Cellar/llvm/*/bin/clang
CFLAGS	=	-Wall -Wextra -Werror -g #-fsanitize=address -fsanitize=leak
GFLAGS 	=	-framework OpenGL -framework Appkit
RM		=	rm -f
INC		=	-I mlx/ -I libft/

.c.o:
			${CC} ${INC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
			make -C ${LIBFT_D}
			make -C ${MLX_D}
			${CC} ${OBJS} ${LIBFT_A} ${GFLAGS} ${CFLAGS} ${MLX_A} -o ${NAME} 

clean:
			make -C ${LIBFT_D} clean
			make -C ${MLX_D} clean
			${RM} -r ${OBJS}

fclean:		clean
			make -C ${LIBFT_D} fclean
			make -C ${MLX_D} clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
