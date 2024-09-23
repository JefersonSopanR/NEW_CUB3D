/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retrieve_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-23 08:55:52 by jesopan-          #+#    #+#             */
/*   Updated: 2024-09-23 08:55:52 by jesopan-         ###   ########ç         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_retrieve_ceiling_color(char *map_line, int *i, t_data *data)
{
	(*i)++;
	while (ft_isspace(map_line[*i]))
		(*i)++;
	data->ceiling_color.r = ft_get_color(map_line, i);
	ft_skip_comma(map_line, i);
	data->ceiling_color.g = ft_get_color(map_line, i);
	ft_skip_comma(map_line, i);
	data->ceiling_color.b = ft_get_color(map_line, i);
	data->ceiling_color.rgb = hex_color(data->ceiling_color);
}

void	ft_retrieve_floor_color(char *map_line, int *i, t_data *data)
{
	(*i)++;
	while (ft_isspace(map_line[*i]))
		(*i)++;
	data->floor_color.r = ft_get_color(map_line, i);
	ft_skip_comma(map_line, i);
	data->floor_color.g = ft_get_color(map_line, i);
	ft_skip_comma(map_line, i);
	data->floor_color.b = ft_get_color(map_line, i);
	data->floor_color.rgb = hex_color(data->floor_color);
}

int	ft_get_color(char *map_line, int *i)
{
	char	*str_color;
	int		color_number;
	int		start;

	start = (*i);
	while (map_line[*i] && ft_isdigit(map_line[*i]))
		(*i)++;
	str_color = ft_substr(map_line, start, (*i) - start);
	if (!str_color)
		return (0);
	color_number = ft_atoi(str_color);
	free(str_color);
	return (color_number);
}

void	ft_skip_comma(char *map_line, int *i)
{
	while (!ft_isdigit(map_line[*i]))
		(*i)++;
}
