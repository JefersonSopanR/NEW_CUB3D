/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_ray_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-23 08:56:13 by jesopan-          #+#    #+#             */
/*   Updated: 2024-09-23 08:56:13 by jesopan-         ###   ########ç         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_wall_collision(t_data *data, t_travel_ray_points *ray)
{
	int	map_x;
	int	map_y;

	map_x = floor(ray->x_intercept / SIZE_TILE);
	map_y = floor(ray->y_intercept / SIZE_TILE);
	if (map_x < 0 || map_y < 0)
		return (-1);
	if (ft_check_map_leaks(data, map_x, map_y))
		return (-1);
	if (data->map_2d[map_y][map_x] == '1')
		return (1);
	return (0);
}

int	ft_check_map_leaks(t_data *data, int x, int y)
{
	int	col;
	int	row;

	col = 0;
	row = 0;
	while (data->map_2d[col])
	{
		row = 0;
		while (data->map_2d[col][row])
		{
			if (col == y && row == x)
				return (0);
			row++;
		}
		col++;
	}
	return (1);
}

int	ft_wall_pixels(t_ray *ray)
{
	int	wall_height;

	if (ray->distance_to_hit_wall == 0)
		return (0);
	wall_height = ceil(SIZE_TILE / ray->distance_to_hit_wall * \
	(SCREEN_WIDTH / (2 * tan(PI / 6))));
	return (wall_height);
}

int	hex_color(t_color color)
{
	int	hex;

	hex = 0;
	hex += color.r << 16;
	hex += color.g << 8;
	hex += color.b;
	return (hex);
}
