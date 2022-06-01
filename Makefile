# BINARY

NAME = fdf

# DIRECTORIES

MLX_DIR = mlx/
LIBFT_DIR = libft/
INCLUDES_DIR = includes/ 
SRC_DIR = srcs/
OBJ_DIR = objs/

# LIBRARIES

MLX = $(MLX_DIR)libmlx.a
LIBFT = $(LIBFT_DIR)libft.a

# NAME

SRC_NAME = main.c				\
		   colors.c				\
		   colors2.c			\
		   colors3.c			\
		   draw.c				\
		   helpers.c			\
		   hook.c				\
		   image.c				\
		   line.c				\
		   parsing.c			\
		   parsing2.c			\
		   rotation.c			\
		   zoom.c				\
		   gnl.c				\
		   gnl2.c
OBJ_NAME = $(SRC_NAME:.c=.o)

# FILES

SRCS = $(addprefix $(SRC_DIR)/,$(SRC_NAME))
OBJS = $(addprefix $(OBJ_DIR),$(OBJ_NAME))

# FLAGS

CC = gcc -g
INC_PATH = -I$(MLX_DIR) -I$(LIBFT_DIR) -I$(INCLUDES_DIR)
LIB_PATH = -L$(MLX_DIR) -L$(LIBFT_DIR)
LINK = -lft -lmlx -lm -lX11 -lXext -lz
CFLAGS = $(INC_PATH) -Wall -Werror -Wextra
LFLAGS = $(LIB_PATH) $(LINK)
RM = rm -f

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			mkdir $(OBJ_DIR) 2> /dev/null || true
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(LIBFT) $(MLX)
			$(CC) $(OBJS) $(LFLAGS) -o $(NAME)

$(LIBFT):
			make -C $(LIBFT_DIR)

$(MLX):
			$(MAKE) -C $(MLX_DIR)

all:		$(NAME)

clean:
			$(RM) $(OBJS)
			rmdir $(OBJ_DIR) 2> /dev/null || true

fclean:		clean
			$(RM) $(NAME)

fcleanlft:
			$(MAKE) fclean -C ./libft

libft:
			make -C $(LIBFT_DIR)

re:			fclean	all

.PHONY:		all clean fclean re
