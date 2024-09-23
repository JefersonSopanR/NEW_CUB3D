/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycaster.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-23 09:01:37 by jesopan-          #+#    #+#             */
/*   Updated: 2024-09-23 09:01:37 by jesopan-         ###   ########ç         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	ft_adjust_overflow_angle(double angle)
{
	if (angle > 2 * PI)
		angle -= 2 * PI;
	if (angle < 0)
		angle += 2 * PI;
	return (angle);
}

void	ft_raycaster(t_data *data)
{
	t_ray	*ray;
	double	rays_to_cast;

	ray = ft_calloc(1, sizeof(t_ray));
	if (!ray)
	{
		ft_putstr_fd("Error\nmalloc", 2);
		ft_free_data(data);
		exit(1);
	}
	ray->num_ray_casted = 0;
	rays_to_cast = (PI / 3) / SCREEN_WIDTH;
	ray->angle = ft_adjust_overflow_angle(data->player.angle + PI / 6);
	while (ray->num_ray_casted < SCREEN_WIDTH)
	{
		ray->distance_to_hit_wall = ft_cast_ray(ray, data);
		ft_draw_ray(ray, data);
		ray->angle = ft_adjust_overflow_angle(ray->angle - rays_to_cast);
		ray->num_ray_casted++;
	}
	free(ray);
}
