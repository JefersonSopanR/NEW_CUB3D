/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-23 08:55:41 by jesopan-          #+#    #+#             */
/*   Updated: 2024-09-23 08:55:41 by jesopan-         ###   ########ç         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_map(t_data *data)
{
	free(data->no_texture.xpm_file);
	free(data->so_texture.xpm_file);
	free(data->we_texture.xpm_file);
	free(data->ea_texture.xpm_file);
	free_split(data->map_2d);
	free(data);
}

void	ft_free_data(t_data *data)
{
	mlx_destroy_image(data->mlx, data->no_texture.img->img);
	free(data->no_texture.xpm_file);
	free(data->no_texture.img);
	mlx_destroy_image(data->mlx, data->so_texture.img->img);
	free(data->so_texture.xpm_file);
	free(data->so_texture.img);
	mlx_destroy_image(data->mlx, data->we_texture.img->img);
	free(data->we_texture.xpm_file);
	free(data->we_texture.img);
	mlx_destroy_image(data->mlx, data->ea_texture.img->img);
	free(data->ea_texture.xpm_file);
	free(data->ea_texture.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	if (data->mlx)
		free(data->mlx);
	free_split(data->map_2d);
	free(data);
}
