/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_walls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-23 09:07:46 by jesopan-          #+#    #+#             */
/*   Updated: 2024-09-23 09:07:46 by jesopan-         ###   ########ç         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strlen_split(char **map_2d)
{
	int	i;

	i = 0;
	while (map_2d[i])
		i++;
	return (i);
}

void	ft_recursive_filter(char **map_2d, int i, int j)
{
	if (i < 0 || i >= (int)ft_strlen_split(map_2d))
		return ;
	if (j < 0 || j > (int)ft_strlen(map_2d[i]))
		return ;
	if (map_2d[i][j] == '1' || map_2d[i][j] == '0' || \
		ft_strchr("NSEW", map_2d[i][j]))
	{
		map_2d[i][j] = '*';
		ft_recursive_filter(map_2d, i, j + 1);
		ft_recursive_filter(map_2d, i, j - 1);
		ft_recursive_filter(map_2d, i + 1, j);
		ft_recursive_filter(map_2d, i - 1, j);
	}
}

int	ft_check_map_free_spaces(char **map_2d)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map_2d[i][j] == ' ')
		j++;
	ft_recursive_filter(map_2d, i, j);
	while (map_2d[i])
	{
		j = 0;
		while (map_2d[i][j])
		{
			if (map_2d[i][j] == '1' || map_2d[i][j] == '0' ||
				ft_strchr("NSEW", map_2d[i][j]))
			{
				ft_write_map_err("the map is divided");
				return (free_split(map_2d), 1);
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

	row = -1;
	col = 0;
	map_2d = ft_especial_split(map_line);
	if (!map_2d)
		return (1);
	while (map_2d[++row])
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
	}
	if (ft_check_map_free_spaces(map_2d))
		return (1);
	return (free_split(map_2d), 0);
}
