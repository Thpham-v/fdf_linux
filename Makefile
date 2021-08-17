NAME			=	fdf
MLX_DIR			=	./minilibx_macos/
SRC_DIR			=	./src/
INC_DIR			=	./header/
SRCS			=	fdf.c			\
					fdf_final_map.c	\
					fdf_utils.c		\
					get_next_line_utils.c	\
					get_next_line.c			\
					ft_split.c				\
					draw_line.c				\
					draw_line_bis.c			\
					draw_tab.c
					
SRC_BASENAME	=	$(addprefix $(SRC_DIR), $(SRCS))		
OBJS			=	$(SRC_BASENAME:.c=.o)
CC				=	gcc 
FLAGS			=	-Wall -Wextra -I $(MLX_DIR) -I $(INC_DIR)

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