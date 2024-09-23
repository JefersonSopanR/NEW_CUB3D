/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_5map_empty_lines.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-23 09:06:26 by jesopan-          #+#    #+#             */
/*   Updated: 2024-09-23 09:06:26 by jesopan-         ###   ########ç         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_check_last_char(char *map, int *i, int star_position)
{
	int		j;
	char	**map_2d_array;

	j = (*i);
	if (star_position != 1)
	{
		ft_write_map_err("There should be one start positon");
		return (1);
	}
	map_2d_array = ft_split(&map[j], '\n');
	if (!map_2d_array)
		return (1);
	j = -1;
	while (map_2d_array[++j])
	{
		if (map_2d_array[j][ft_strlen(map_2d_array[j]) - 1] != '1')
		{
			if (map_2d_array[j][ft_strlen(map_2d_array[j]) - 1] == ' ')
				ft_write_map_err("There's a space at the end the map");
			else
				ft_write_map_err("Map should be surrounded by walls");
			return (free_split(map_2d_array), 1);
		}
	}
	return (free_split(map_2d_array), 0);
}

int	ft_check_empty_lines(char *map, int *i)
{
	int	j;
	int	star_position;

	j = (*i) - 1;
	star_position = 0;
	while (map[++j])
	{
		if (map[j] == '\n' && (map[j + 1] == '\n' || map[j + 1] == '\0'))
		{
			ft_write_map_err("Shouldn't be empty lines in the map");
			return (1);
		}
		if (!ft_strchr("\n01NSEW ", map[j]))
		{
			ft_write_map_err("Wrong character in the map");
			return (1);
		}
		if (ft_strchr("NSEW", map[j]))
			star_position++;
	}
	if (ft_check_last_char(map, i, star_position))
		return (1);
	return (0);
}
