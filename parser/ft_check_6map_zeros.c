/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_6map_zeros.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-25 12:24:54 by jesopan-          #+#    #+#             */
/*   Updated: 2024-09-25 12:24:54 by jesopan-         ###   ########ç         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
