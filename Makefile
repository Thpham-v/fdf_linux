NAME			=	fdf
MLX_DIR			=	./minilibx_macos/
SRC_DIR			=	./src/
INC_DIR			=	./inc/
SRCS			=	fdf.c			\
					fdf_utils.c		\
					fdf_utils_2.c	\
					get_next_line_utils.c	\
					get_next_line.c			\
					ft_split.c
SRC_BASENAME	=	$(addprefix $(SRC_DIR), $(SRCS))		
OBJS			=	$(SRC_BASENAME:.c=.o)
CC				=	gcc -fsanitize=address
FLAGS			=	-Wall -Werror -Wextra -I $(MLX_DIR) -I $(INC_DIR)

.c.o		:
				$(CC) $(FLAGS) -Imlx -c $< -o $@

all			:	$(NAME)

$(NAME)		:	$(OBJS)
			make -C $(MLX_DIR)
			$(CC) $(FLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS) -L $(MLX_DIR)
			@echo [$(NAME)] : Created !

clean		:
			rm -rf $(OBJS)
			make clean -C $(MLX_DIR)
			@echo "[OBJS] Deleted"

fclean		:	clean
			rm -f $(NAME)
			@echo "[$(NAME)]: Deleted"

re			:	fclean all