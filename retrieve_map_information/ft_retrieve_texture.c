/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_retrieve_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-23 08:55:14 by jesopan-          #+#    #+#             */
/*   Updated: 2024-09-23 08:55:14 by jesopan-         ###   ########ç         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_retrieve_ea_texture(char *map_line, int *i, t_data *data)
{
	char	*east_texture;
	int		start;

	(*i) += 2;
	while (ft_isspace(map_line[*i]))
		(*i)++;
	start = (*i);
	while (map_line[*i] && !ft_isspace(map_line[*i]) && map_line[*i] != '\n')
		(*i)++;
	east_texture = ft_substr(map_line, start, (*i) - start);
	if (!east_texture)
		return ;
	data->ea_texture.xpm_file = east_texture;
	return ;
}

void	ft_retrieve_we_texture(char *map_line, int *i, t_data *data)
{
	char	*west_texture;
	int		start;

	(*i) += 2;
	while (ft_isspace(map_line[*i]))
		(*i)++;
	start = (*i);
	while (map_line[*i] && !ft_isspace(map_line[*i]) && map_line[*i] != '\n')
		(*i)++;
	west_texture = ft_substr(map_line, start, (*i) - start);
	if (!west_texture)
		return ;
	data->we_texture.xpm_file = west_texture;
	return ;
}

void	ft_retrieve_so_texture(char *map_line, int *i, t_data *data)
{
	char	*south_texture;
	int		start;

	(*i) += 2;
	while (ft_isspace(map_line[*i]))
		(*i)++;
	start = (*i);
	while (map_line[*i] && !ft_isspace(map_line[*i]) && map_line[*i] != '\n')
		(*i)++;
	south_texture = ft_substr(map_line, start, (*i) - start);
	if (!south_texture)
		return ;
	data->so_texture.xpm_file = south_texture;
	return ;
}

void	ft_retrieve_no_texture(char *map_line, int *i, t_data *data)
{
	char	*north_texture;
	int		start;

	(*i) += 2;
	while (ft_isspace(map_line[*i]))
		(*i)++;
	start = (*i);
	while (map_line[*i] && !ft_isspace(map_line[*i]) && map_line[*i] != '\n')
		(*i)++;
	north_texture = ft_substr(map_line, start, (*i) - start);
	if (!north_texture)
		return ;
	data->no_texture.xpm_file = north_texture;
	return ;
}
