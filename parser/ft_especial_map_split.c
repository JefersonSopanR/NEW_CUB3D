/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_especial_map_split.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-23 09:07:54 by jesopan-          #+#    #+#             */
/*   Updated: 2024-09-23 09:07:54 by jesopan-         ###   ########ç         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**ft_especial_split(char *str)
{
	char	**split;
	char	**map_2d;
	int		i;
	int		max_len;

	map_2d = NULL;
	i = -1;
	split = ft_split(str, '\n');
	if (!split)
		return (NULL);
	if (ft_check_map_ends(split))
	{
		ft_write_map_err("Map should be surrounded by walls");
		return (free_split(split), NULL);
	}
	max_len = ft_strlen(split[i + 1]);
	while (split[++i])
	{
		if (ft_strlen(split[i]) > (size_t)max_len)
			max_len = ft_strlen(split[i]);
	}
	map_2d = ft_fill_map_with_doces(split, i, max_len + 1);
	free_split(split);
	return (map_2d);
}

int	ft_check_map_ends(char **map_2d)
{
	int	col;
	int	row;

	row = 0;
	col = 0;
	while (map_2d[0][col])
	{
		if (map_2d[0][col] != ' ' && map_2d[0][col] != '1')
			return (1);
		col++;
	}
	col = 0;
	while (map_2d[row])
		row++;
	while (map_2d[row - 1][col])
	{
		if (map_2d[row - 1][col] != ' ' && map_2d[row - 1][col] != '1')
			return (1);
		col++;
	}
	return (0);
}

char	**ft_fill_map_with_doces(char **split, int i, int max_len)
{
	char	**filler;
	int		len;

	len = 0;
	filler = ft_calloc(i + 1, sizeof(char *));
	if (!filler)
		return (NULL);
	i = -1;
	while (split[++i])
	{
		filler[i] = ft_calloc(max_len + 1, sizeof(char));
		if (!filler[i])
			return (NULL);
		len = ft_strlen(split[i]);
		ft_strlcpy(filler[i], split[i], len + 1);
		while (len < max_len)
			filler[i][len++] = '2';
	}
	return (filler);
}
