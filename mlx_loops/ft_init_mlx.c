/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-23 09:40:39 by jesopan-          #+#    #+#             */
/*   Updated: 2024-09-23 09:40:39 by jesopan-         ###   ########ç         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_free_map(data);
		ft_putstr_fd("Error\nmlx_init", 2);
		exit(1);
	}
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
	if (!data->win)
	{
		free(data->mlx);
		ft_free_map(data);
		ft_putstr_fd("Error\nmlx_new_window", 2);
		exit(1);
	}
}

void	ft_get_xpm_textures(t_data *data)
{
	data->so_texture.img = ft_xpm_file_to_image(data->mlx, \
	data->so_texture.xpm_file, data);
	data->no_texture.img = ft_xpm_file_to_image(data->mlx, \
	data->no_texture.xpm_file, data);
	data->we_texture.img = ft_xpm_file_to_image(data->mlx, \
	data->we_texture.xpm_file, data);
	data->ea_texture.img = ft_xpm_file_to_image(data->mlx, \
	data->ea_texture.xpm_file, data);
}

t_img	*ft_xpm_file_to_image(void *mlx, char *xpm_file, t_data *data)
{
	t_img	*img;

	img = ft_calloc(1, sizeof(t_img));
	if (!img)
	{
		ft_putstr_fd("Error\nmalloc", 2);
		ft_free_data(data);
		exit(1);
	}
	img->img = mlx_xpm_file_to_image(mlx, xpm_file, &img->width, &img->height);
	printf("Width: %d\n", img->width);
	printf("Height: %d\n", img->height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
	&img->line_length, &img->endian);
	printf("Bits per pixel: %d\n", img->bits_per_pixel);
	printf("Line length: %d\n", img->line_length);
	printf("Endian: %d\n", img->endian);
	return (img);
}
