#----------------------------		Target		----------------------------------
NAME = so_long
#---------------------------------------------------------------------------------
#
CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
#---------------------------	Libft library	----------------------------------
LIB = libft.a
LDIR = Libft

#----------------------------	MLX library		----------------------------------
MLX_NAME = libmlx.dylib
MLX_DIR = minilibx_mms
MLXD_MAC_FLAGS = -lmlx -framework OpenGL -framework AppKit
#---------------------------------------------------------------------------------
INC			=	./includes
SRCS		=	main.c	img.c	map.c	window.c	move_img.c	not_bonus.c
SRCS_DIR	=	src/
OBJ_DIR		= objs/
OBJS		= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o) $(GNL_SRS:.c=.o))
#---------------------------------------------------------------------------------
SRCS_B		=	main.c	img.c	map.c	window.c	move_img.c	bonus.c
OBJS_B		= $(addprefix $(OBJ_DIR), $(SRCS_B:.c=.o) $(GNL_SRS:.c=.o))

#---------------------------------------------------------------------------------
all: makedir $(LIB) $(MLX_NAME) $(NAME)

makedir:
	@mkdir -p $(OBJ_DIR)

$(LIB):
	@$(MAKE) -C $(LDIR) --silent
	@cp $(LDIR)/libft.h $(INC)

$(MLX_NAME):
	@$(MAKE) -C $(MLX_DIR) --silent
	@cp $(MLX_DIR)/mlx.h $(INC)
	@cp $(MLX_DIR)/$(MLX_NAME) ./

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -L $(MLX_DIR) $(MLXD_MAC_FLAGS) -I$(INC) $(OBJS) $(LDIR)/$(LIB) -o $(NAME)


$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

clean:
	@$(MAKE) -C $(LDIR) clean --silent
	@$(MAKE) -C $(MLX_DIR) clean --silent
	@rm -rf $(OBJ_DIR)
	@rm -f $(INC)/libft.h $(INC)/mlx.h
	@rm -f $(MLX_NAME)
	clear
	@echo "All $(R)OBJS$(DF) deleted."

fclean: clean
	@$(MAKE) -C $(LDIR) fclean --silent
	@rm -f $(MLX_DIR)/*.o
	@rm -f $(MLX_DIR)/$(MLX_NAME)
	@rm -f $(MLX_NAME)
	@rm -f $(INC)/libft.h $(INC)/mlx.h
	clear
	@echo "$(R)All created files deleted.$(DF)"

re: fclean all

bonus:	makedir $(LIB) $(MLX_NAME) $(NAME) $(OBJS_B)
	$(CC) $(CFLAGS) -L $(MLX_DIR) $(MLXD_MAC_FLAGS) -I$(INC) $(OBJS_B) $(LDIR)/$(LIB) -o $(NAME)
	@echo "$(NAME) is ready"


.PHONY: clean fclean re bonus
