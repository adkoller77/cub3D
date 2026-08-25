NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = src/main.c \
      src/parsing/parse_element.c \
      src/parsing/parse_map.c \
      src/parsing/parse_color.c \
      src/parsing/parse_texture.c \
      src/parsing/validate_map.c \
      src/parsing/check_elements.c \
      src/player/init_player.c \
      src/player/move_player.c \
      src/raycasting/raycasting.c \
      src/raycasting/draw.c \
      src/raycasting/texture.c \
      src/mlx/init_mlx.c \
      src/mlx/events.c \
      src/mlx/key_events.c \
      src/mlx/load_textures.c \
      src/utils/error.c

OBJS = $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = libs/minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

INCLUDES = -I includes -I $(MLX_DIR) -I $(LIBFT_DIR)

all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
