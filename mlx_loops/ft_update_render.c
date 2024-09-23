/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_render.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-23 09:44:19 by jesopan-          #+#    #+#             */
/*   Updated: 2024-09-23 09:44:19 by jesopan-         ###   ########ç         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_update_render(t_data *data)
{
	ft_update_player_position(data, data->player.direction);
	if (data->player.rotation)
		ft_update_player_angle(data, data->player.rotation);
	ft_render_game(data);
	return (0);
}

void	ft_update_player_position(t_data *data, int direction)
{
	if (direction == UP && ft_is_inside_map(data, &data->player, direction))
	{
		data->player.x += SPEED * cos(data->player.angle);
		data->player.y -= SPEED * sin(data->player.angle);
	}
	else if (direction == DOWN && ft_is_inside_map(data, &data->player, \
	direction))
	{
		data->player.x -= SPEED * cos(data->player.angle);
		data->player.y += SPEED * sin(data->player.angle);
	}
	else if (direction == LEFT && ft_is_inside_map(data, &data->player, \
	direction))
	{
		data->player.x -= SPEED * sin(data->player.angle);
		data->player.y -= SPEED * cos(data->player.angle);
	}
	else if (direction == RIGHT && ft_is_inside_map(data, &data->player, \
	direction))
	{
		data->player.x += SPEED * sin(data->player.angle);
		data->player.y += SPEED * cos(data->player.angle);
	}
	return ;
}

bool	ft_is_inside_map(t_data *data, t_player *player, int direction)
{
	int	x;
	int	y;

	ft_get_axis_values(&x, &y, player, direction);
	if (x < 0 || y < 0)
		return (false);
	if (ft_check_map_leaks(data, x, y))
		return (false);
	if (data->map_2d[y][x] == '1')
		return (false);
	return (true);
}

void	ft_update_player_angle(t_data *data, int rotation)
{
	if (rotation == LEFT)
	{
		data->player.angle = ft_adjust_overflow_angle(data->player.angle + \
		0.06);
	}
	else if (rotation == RIGHT)
		data->player.angle = ft_adjust_overflow_angle(data->player.angle - \
		0.06);
}

void	ft_get_axis_values(int *x, int *y, t_player *player, int direction)
{
	if (direction == UP)
	{
		*x = floor((player->x + SPEED * cos(player->angle)) / SIZE_TILE);
		*y = floor((player->y - SPEED * sin(player->angle)) / SIZE_TILE);
	}
	else if (direction == DOWN)
	{
		*x = floor((player->x - SPEED * cos(player->angle)) / SIZE_TILE);
		*y = floor((player->y + SPEED * sin(player->angle)) / SIZE_TILE);
	}
	else if (direction == LEFT)
	{
		*x = floor((player->x - SPEED * sin(player->angle)) / SIZE_TILE);
		*y = floor((player->y - SPEED * cos(player->angle)) / SIZE_TILE);
	}
	else if (direction == RIGHT)
	{
		*x = floor((player->x + SPEED * sin(player->angle)) / SIZE_TILE);
		*y = floor((player->y + SPEED * cos(player->angle)) / SIZE_TILE);
	}
}
