/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-23 09:01:51 by jesopan-          #+#    #+#             */
/*   Updated: 2024-09-23 09:01:51 by jesopan-         ###   ########ç         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_render_game(t_data *data)
{
	data->screen_view = ft_get_screen_view(data);
	ft_raycaster(data);
	mlx_put_image_to_window(data->mlx, data->win, data->screen_view->img, 0, 0);
	mlx_destroy_image(data->mlx, data->screen_view->img);
	free(data->screen_view);
}

t_img	*ft_get_screen_view(t_data *data)
{
	t_img	*img;

	img = ft_calloc(1, sizeof(t_img));
	if (!img)
	{
		ft_putstr_fd("Error\nmalloc", 2);
		ft_free_data(data);
		exit(1);
	}
	img->img = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
	&img->line_length, &img->endian);
	return (img);
}
