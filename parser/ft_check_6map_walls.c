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

void	ft_write_space_error(void)
{
	ft_putstr_fd("Error\nThe map is divided with space", 2);
	ft_putchar_fd('\n', 2);
	return ;
}

int	ft_spaces_detector(char **map_2d, int j)
{
	int	y;

	y = 0;
	while (map_2d[y])
	{
		if (!ft_strchr("012NWES", map_2d[y][j]))
			return (1);
		y++;
	}
	return (0);
}

int	ft_check_map_free_spaces(char **map_2d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map_2d[i])
	{
		j = 0;
		while (map_2d[i][j])
		{
			if (map_2d[i][j] == '2')
			{
				if (ft_spaces_detector(map_2d, j))
				{
					ft_write_space_error();
					return (free_split(map_2d), 1);
				}
			}
			j++;
		}
		i++;
	}
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
	if (!map_2d || ft_check_map_free_spaces(map_2d))
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
