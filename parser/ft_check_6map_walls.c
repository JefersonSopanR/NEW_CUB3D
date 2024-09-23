/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_6map_walls.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-23 09:07:46 by jesopan-          #+#    #+#             */
/*   Updated: 2024-09-23 09:07:46 by jesopan-         ###   ########ç         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_map_walls(char *map, int *i)
{
	char	*map_line;
	int		start;
	int		end;

	start = (*i);
	end = (*i);
	while (map[end])
		end++;
	map_line = ft_substr(map, start, end - start);
	if (!map_line)
		return (1);
	if (ft_check_map_surroenders(map_line))
		return (free(map_line), 1);
	free(map_line);
	return (0);
}

int	ft_check_map_surroenders(char *map_line)
{
	char	**map_2d;
	int		row;
	int		col;

	row = 0;
	col = 0;
	map_2d = ft_especial_split(map_line);
	if (!map_2d)
		return (1);
	while (map_2d[row])
	{
		col = 0;
		while (map_2d[row][col])
		{
			if (map_2d[row][col] == '0')
			{
				if (ft_check_zeros(map_2d, row, col))
					return (1);
			}
			col++;
		}
		row++;
	}
	return (free_split(map_2d), 0);
}

int	ft_check_zeros(char **map_2d, int y, int x)
{
	int	exit_code;

	exit_code = 0;
	if (!ft_strchr("NSEW01", map_2d[y + 1][x]))
		exit_code = 1;
	if (!ft_strchr("NSEW01", map_2d[y - 1][x]))
		exit_code = 1;
	if (!ft_strchr("NSEW01", map_2d[y][x + 1]))
		exit_code = 1;
	if (!ft_strchr("NSEW10", map_2d[y][x - 1]))
		exit_code = 1;
	if (exit_code)
	{
		ft_write_map_err("Map should be surrounded by walls");
		free_split(map_2d);
	}
	return (exit_code);
}
