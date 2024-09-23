/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-23 08:59:57 by jesopan-          #+#    #+#             */
/*   Updated: 2024-09-23 08:59:57 by jesopan-         ###   ########ç         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_ray(t_ray *ray, t_data *data)
{
	int	x_pixel;
	int	y_pixel;
	int	wall_height;
	int	firts_wall_pixel;

	y_pixel = 0;
	x_pixel = ray->num_ray_casted;
	wall_height = ft_wall_pixels(ray);
	firts_wall_pixel = ceil((SCREEN_HEIGHT - wall_height) / 2);
	while (y_pixel < SCREEN_HEIGHT)
	{
		if (y_pixel < firts_wall_pixel)
			ft_paint_pixel(data->screen_view, x_pixel, \
			y_pixel, data->ceiling_color.rgb);
		else if (y_pixel > firts_wall_pixel + wall_height)
			ft_paint_pixel(data->screen_view, x_pixel, \
			y_pixel, data->floor_color.rgb);
		else
			ft_paint_wall(data, y_pixel, ray);
		y_pixel++;
	}
}

void	ft_paint_wall(t_data *data, int y_pixel, t_ray *ray)
{
	if (ray->orientation == VERTICAL && cos(ray->angle) < 0)
		ft_get_texture_pixel_color(data, data->ea_texture.img, ray, y_pixel);
	else if (ray->orientation == HORIZONTAL && sin(ray->angle) > 0)
		ft_get_texture_pixel_color(data, data->no_texture.img, ray, y_pixel);
	else if (ray->orientation == VERTICAL && cos(ray->angle) > 0)
		ft_get_texture_pixel_color(data, data->we_texture.img, ray, y_pixel);
	else if (ray->orientation == HORIZONTAL && sin(ray->angle) < 0)
		ft_get_texture_pixel_color(data, data->so_texture.img, ray, y_pixel);
}

void	ft_get_texture_pixel_color(t_data *data, t_img *img, \
t_ray *ray, int y_pixel)
{
	int	x_pixel;
	int	y_texture;
	int	x_texture;
	int	wall_height;
	int	color;

	x_pixel = ray->num_ray_casted;
	if (ray->orientation == VERTICAL)
		x_texture = (int)floor(data->player.y - ray->distance_to_hit_wall \
	* sin(ray->angle)) % SIZE_TILE;
	else
		x_texture = (int)floor(data->player.x + ray->distance_to_hit_wall \
	* cos(ray->angle)) % SIZE_TILE;
	wall_height = ft_wall_pixels(ray);
	if (wall_height == 0)
		y_texture = 0;
	else
		y_texture = (y_pixel - ceil((SCREEN_HEIGHT - wall_height) / 2)) \
		* SIZE_TILE / wall_height;
	color = *(int *)(img->addr + (y_texture * img->line_length + x_texture \
	* (img->bits_per_pixel / 8)));
	ft_paint_pixel(data->screen_view, x_pixel, y_pixel, color);
}

void	ft_paint_pixel(t_img *img, int x_pixel, int y_pixel, int color)
{
	char	*pixel_addr;
	int		num_pixels;

	num_pixels = img->bits_per_pixel - 8;
	pixel_addr = img->addr + (y_pixel * img->line_length + x_pixel \
	* (img->bits_per_pixel / 8));
	while (num_pixels >= 0)
	{
		if (img->endian != 0)
			*pixel_addr++ = (color >> num_pixels) & 0xFF;
		else
			*pixel_addr++ = (color >> (img->bits_per_pixel - 8 - num_pixels)) \
			& 0xFF;
		num_pixels -= 8;
	}
}
