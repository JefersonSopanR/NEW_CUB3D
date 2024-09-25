/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retrieve_player_information.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-23 08:53:14 by jesopan-          #+#    #+#             */
/*   Updated: 2024-09-23 08:53:14 by jesopan-         ###   ########ç         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	double	get_player_position(int axis)
{
	double	pixel_position;

	pixel_position = (axis * SIZE_TILE) + SIZE_TILE / 2;
	return (pixel_position);
}

static	double	get_player_angle(char direction)
{
	double	angle;

	if (direction == 'E')
	{
		angle = 0;
		return (angle);
	}
	else if (direction == 'N')
	{
		angle = PI * 0.5;
		return (angle);
	}
	else if (direction == 'W')
	{
		angle = PI;
		return (angle);
	}
	angle = PI * 1.5;
	return (angle);
}

void	ft_retrieve_player_information(t_data *data)
{
	int		x;
	int		y;
	char	**map;

	y = 0;
	x = 0;
	map = data->map_2d;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_strchr("EWNS", map[y][x]))
			{
				data->player.x = get_player_position(x);
				data->player.y = get_player_position(y);
				data->player.angle = get_player_angle(map[y][x]);
				map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}

void	ft_set_map_dimensions(t_data *data)
{
	int	i;

	i = 0;
	while (data->map_2d[i])
		i++;
	data->map_height = i;
	data->map_width = ft_strlen(data->map_2d[0]);
}
