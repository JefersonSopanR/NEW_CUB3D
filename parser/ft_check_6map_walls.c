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
	printf("MapLine\n%s\nFinish\n", map_line);
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
