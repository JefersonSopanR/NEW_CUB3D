NAME = cub3d
CLANG = clang
CFLAGS = -Wall -Wextra -Werror -I. -I./minilibx-linux
RM = rm -f

PARSER_DIR = ./parser/
RETRIEVE_MAP_INFORMATION_DIR = ./retrieve_map_information/
RENDER_GAME_DIR = ./render_game/
MLX_LOOPS_DIR = ./mlx_loops/

PARSER = $(addprefix $(PARSER_DIR), \
        ft_check_map_file.c ft_check_elements.c \
        ft_check_fc_numbers.c ft_check_texture_file.c \
        ft_check_map_empty_lines.c ft_check_map_walls.c \
		ft_check_map_zeros.c ft_especial_map_split.c \
		ft_exit_parser_error.c ft_free_split.c ft_check_map_recursive.c)

RETRIEVE_MAP_INFORMATION = $(addprefix $(RETRIEVE_MAP_INFORMATION_DIR), \
        ft_retrieve_map.c ft_retrieve_texture.c \
        ft_retrieve_color.c ft_free_map.c ft_retrieve_player_information.c)

RENDER_GAME = $(addprefix $(RENDER_GAME_DIR), \
		ft_raycaster.c ft_cast_ray.c ft_draw_ray.c ft_cast_ray_utils.c \
		ft_render_game.c)

MLX_LOOPS = $(addprefix $(MLX_LOOPS_DIR), \
			ft_init_mlx.c ft_update_render.c)

SRCS = main.c $(PARSER) $(RETRIEVE_MAP_INFORMATION) $(MLX_LOOPS) $(RENDER_GAME)

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MINILIBX_DIR = minilibx-linux
MINILIBX = $(MINILIBX_DIR)/libmlx.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	$(CLANG) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MINILIBX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MINILIBX_DIR) clean

re: fclean all

.PHONY: all clean fclean re