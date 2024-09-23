/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-23 09:12:17 by jesopan-          #+#    #+#             */
/*   Updated: 2024-09-23 09:12:17 by jesopan-         ###   ########ç         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>
# include <math.h>
# include <limits.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "libft/libft.h"

# define SIZE_TILE		64
# define PI				3.14159265358979323846

# define SPEED			12

# define WINDOW_WIDTH	960
# define WINDOW_HEIGHT	720

# define SCREEN_WIDTH	960
# define SCREEN_HEIGHT	720

# define HORIZONTAL		1
# define VERTICAL		2

# define KEY_ESC			65307
# define KEY_Q			113

# define KEY_LEFT		65361
# define KEY_RIGHT		65363

# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100

# define UP				1
# define DOWN			2
# define LEFT			3
# define RIGHT			4

typedef enum e_err_type
{
	NONE,
	OTHER,
	E_NO,
	E_SO,
	E_WE,
	E_EA,
	E_F,
	E_C,
	E_WRONG_ELEM,
	E_DUP,
	E_MAP,
}	t_err_type;

typedef struct s_identifier
{
	int				no;
	int				so;
	int				we;
	int				ea;
	int				f;
	int				c;
	t_err_type		checker;
	bool			dup;
	bool			is_fc;
}	t_identifier;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	rgb;
}	t_color;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_texture
{
	char	*xpm_file;
	t_img	*img;
}	t_texture;

typedef struct s_player
{
	double	angle;
	double	speed;
	double	y;
	double	x;
	int		direction;
	int		rotation;
}	t_player;

typedef struct s_ray
{
	double	angle;
	double	distance_to_hit_wall;
	int		num_ray_casted;
	int		orientation;
}	t_ray;

typedef struct s_travel_ray_points
{
	double	x_step;
	double	y_step;
	double	x_intercept;
	double	y_intercept;
}	t_travel_ray_points;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			win_width;
	int			win_height;
	int			map_width;
	int			map_height;
	t_texture	no_texture;
	t_texture	so_texture;
	t_texture	we_texture;
	t_texture	ea_texture;
	t_color		floor_color;
	t_color		ceiling_color;	
	t_player	player;
	t_img		*screen_view;
	char		**map_2d;
}	t_data;

			//PASER_FUNCTIONS_PROTOTYPES
//ft_check_1map_file.c
void		ft_check_map_file(char **av, t_data *data);
char		*ft_read_file(char *file, t_data *data);
//
//ft_check_2elements.c
//
t_err_type	ft_check_elements(char *map);
t_err_type	ft_check_identifier(char *map, int *i, t_identifier *id);
void		ft_check_dup_elem(int *i, t_identifier *id, int	*element, \
			t_err_type err_type);
int			ft_count_elements(t_identifier *id, char *map, int *i);
//
//ft_check_3fc_numbers.c
//
int			ft_check_fc_numbers(char *map, int *i, t_identifier *id);
int			ft_check_digit_fc(char *map, int *i);
int			ft_skip_spaces(char *map, int *i, int *comma);
//
//ft_check_4texture_file.c
//
int			ft_check_texture_file(char	*map, int *i, t_identifier *id);
//
//ft_check_5map_emty_lines.c
//
int			ft_check_empty_lines(char *map, int *i);
//
//ft_check_6map_walls.c
//
int			ft_check_map_walls(char *map, int *i);
int			ft_check_map_surroenders(char *map_line);
int			ft_check_zeros(char **map_2d, int y, int x);
//
//ft_especial_map_split.c
//
char		**ft_especial_split(char *str);
int			ft_check_map_ends(char **map_2d);
char		**ft_fill_map_with_doces(char **split, int i, int max_len);
//
//ft_exit_parser_error.c
//
void		ft_exit(char *msg, char *map, t_err_type type_error, t_data *data);
void		ft_write_map_err(char *err_msg);
//
//ft_free_split.c
//
void		free_split(char **split_str);
//
//
			//RETIEVES_MAP_FUNCTIONS_PROTOTYPES
//
//
//ft_retrieve_map.c
//
void		ft_retrieve_map(char **av, t_data *data);
void		ft_retrieve_textures(char *map_line, int *i, t_data *data);
void		ft_retrieve_colors(char *map_line, int *i, t_data *data);
//
//ft_retrieve_texture.c
//
void		ft_retrieve_ea_texture(char *map_line, int *i, t_data *data);
void		ft_retrieve_we_texture(char *map_line, int *i, t_data *data);
void		ft_retrieve_so_texture(char *map_line, int *i, t_data *data);
void		ft_retrieve_no_texture(char *map_line, int *i, t_data *data);
//
//ft_retrieve_color.c
//
void		ft_retrieve_ceiling_color(char *map_line, int *i, t_data *data);
void		ft_retrieve_floor_color(char *map_line, int *i, t_data *data);
int			ft_get_color(char *map_line, int *i);
void		ft_skip_comma(char *map_line, int *i);
//
//ft_retrive_player_information.c
//
void		ft_retrieve_player_information(t_data *data);
void		ft_set_map_dimensions(t_data *data);
//
//ft_free_map.c
//
void		ft_free_map(t_data *data);
void		ft_free_data(t_data *data);
//
//
			//RAYCASTER_FUNCTIONS_PROTOTYPES
//ft_render_game.c
//
void		ft_render_game(t_data *data);
t_img		*ft_get_screen_view(t_data *data);
//
//ft_raycaster.c
//
void		ft_raycaster(t_data *data);
double		ft_adjust_overflow_angle(double angle);
//
//ft_cast_ray.c
//
double		ft_cast_ray(t_ray *ray, t_data *data);
double		ft_cast_ray_horizontally(t_ray *ray, t_data *data, \
			t_player *player);
double		ft_cast_ray_vertically(t_ray *ray, t_data *data, t_player *player);
double		ft_calculate_distance_to_wall(t_data *data, \
			t_travel_ray_points *ray, t_player *player);
//
//ft_cast_ray_utils.c
//
int			ft_check_wall_collision(t_data *data, t_travel_ray_points *ray);
int			ft_wall_pixels(t_ray *ray);
int			hex_color(t_color color);
int			ft_check_map_leaks(t_data *data, int x, int y);
//
//ft_draw_ray.c
//
void		ft_draw_ray(t_ray *ray, t_data *data);
void		ft_paint_wall(t_data *data, int y_pixel, t_ray *ray);
void		ft_get_texture_pixel_color(t_data *data, t_img *img, \
			t_ray *ray, int y_pixel);
void		ft_paint_pixel(t_img *img, int x_pixel, int y_pixel, int color);
//
//
			//FT_INIT_MLX
//
//ft_init_mlx.c
//
void		ft_init_mlx(t_data *data);
void		ft_get_xpm_textures(t_data *data);
t_img		*ft_xpm_file_to_image(void *mlx, char *xpm_file, t_data *data);
//
//ft_update_render.c
//
int			ft_update_render(t_data *data);
void		ft_update_player_position(t_data *data, int direction);
bool		ft_is_inside_map(t_data *data, t_player *player, int direction);
void		ft_update_player_angle(t_data *data, int rotation);
void		ft_get_axis_values(int *x, int *y, t_player *player, int direction);
//
//
//			MAIN_FUNCTION
//
int			ft_key_unpress(int keycode, t_data *data);
int			ft_key_press(int keycode, t_data *data);
int			ft_close(t_data *data);
void		ft_print_map(t_data *data);

//

#endif