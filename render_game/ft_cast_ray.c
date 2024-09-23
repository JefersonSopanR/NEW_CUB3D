/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-23 08:56:55 by jesopan-          #+#    #+#             */
/*   Updated: 2024-09-23 08:56:55 by jesopan-         ###   ########ç         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	ft_cast_ray(t_ray *ray, t_data *data)
{
	double	hit_horizantall_wall;
	double	hit_vertical_wall;

	hit_horizantall_wall = ft_cast_ray_horizontally(ray, data, &data->player);
	hit_vertical_wall = ft_cast_ray_vertically(ray, data, &data->player);
	if (hit_horizantall_wall < hit_vertical_wall)
	{
		ray->orientation = HORIZONTAL;
		return (hit_horizantall_wall);
	}
	ray->orientation = VERTICAL;
	return (hit_vertical_wall);
}

double	ft_cast_ray_horizontally(t_ray *ray, t_data *data, t_player *player)
{
	t_travel_ray_points	ray_point;

	if (sin(ray->angle) == 0)
		return (INT_MAX);
	if (sin(ray->angle) > 0)
	{
		ray_point.y_step = -1 * SIZE_TILE;
		ray_point.x_step = SIZE_TILE / tan(ray->angle);
		ray_point.y_intercept = floor(player->y / SIZE_TILE) \
		* SIZE_TILE - 0.0001;
		ray_point.x_intercept = player->x + (player->y - ray_point.y_intercept) \
		/ tan(ray->angle);
	}
	else
	{
		ray_point.y_step = SIZE_TILE;
		ray_point.x_step = -1 * SIZE_TILE / tan(ray->angle);
		ray_point.y_intercept = floor(player->y / SIZE_TILE) \
		* SIZE_TILE + SIZE_TILE;
		ray_point.x_intercept = player->x + (player->y - ray_point.y_intercept) \
		/ tan(ray->angle);
	}
	return (ft_calculate_distance_to_wall(data, &ray_point, player));
}

double	ft_cast_ray_vertically(t_ray *ray, t_data *data, t_player *player)
{
	t_travel_ray_points	ray_point;

	if (cos(ray->angle) == 0)
		return (INT_MAX);
	if (cos(ray->angle) > 0)
	{
		ray_point.x_step = SIZE_TILE;
		ray_point.y_step = -1 * SIZE_TILE * tan(ray->angle);
		ray_point.x_intercept = floor(player->x / SIZE_TILE) \
		* SIZE_TILE + SIZE_TILE;
		ray_point.y_intercept = player->y + (player->x - ray_point.x_intercept) \
		* tan(ray->angle);
	}
	else
	{
		ray_point.x_step = -1 * SIZE_TILE;
		ray_point.y_step = SIZE_TILE * tan(ray->angle);
		ray_point.x_intercept = floor(player->x / SIZE_TILE) \
		* SIZE_TILE - 0.0001;
		ray_point.y_intercept = player->y + (player->x - ray_point.x_intercept) \
		* tan(ray->angle);
	}
	return (ft_calculate_distance_to_wall(data, &ray_point, player));
}

double	ft_calculate_distance_to_wall(t_data *data, t_travel_ray_points *ray, \
t_player *player)
{
	double	distance_to_wall;

	while (ft_check_wall_collision(data, ray) != -1)
	{
		if (ft_check_wall_collision(data, ray))
		{
			distance_to_wall = sqrt(pow(player->x - ray->x_intercept, 2) \
			+ pow(player->y - ray->y_intercept, 2));
			return (distance_to_wall);
		}
		ray->x_intercept += ray->x_step;
		ray->y_intercept += ray->y_step;
	}
	return (INT_MAX);
}
