/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_2elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-23 09:04:18 by jesopan-          #+#    #+#             */
/*   Updated: 2024-09-23 09:04:18 by jesopan-         ###   ########ç         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_map_begining(char *map, int i)
{
	while (map[i] && map[i] != '\n')
	{
		if (map[i] == '0' || map[i] == '1')
			return (1);
		i++;
	}
	return (0);
}

t_err_type	ft_check_elements(char *map)
{
	t_identifier	id;
	int				i;

	ft_memset(&id, 0, sizeof(t_identifier));
	i = 0;
	while (map[i] && !id.checker && !id.dup)
	{
		if (!ft_strncmp(&map[i], "NO ", 3) \
		|| !ft_strncmp(&map[i], "SO ", 3) \
		|| !ft_strncmp(&map[i], "WE ", 3) \
		|| !ft_strncmp(&map[i], "EA ", 3) \
		|| !ft_strncmp(&map[i], "F ", 2) \
		|| !ft_strncmp(&map[i], "C ", 2))
			id.checker = ft_check_identifier(map, &i, &id);
		else if (ft_check_map_begining(map, i))
			break ;
		else if (map[i] == '\n' || ft_isspace(map[i]))
			i++;
		else
			id.checker = E_WRONG_ELEM;
	}
	if (id.checker || id.dup || ft_count_elements(&id, map, &i))
		return (id.checker);
	return (0);
}

t_err_type	ft_check_identifier(char *map, int *i, t_identifier *id)
{
	if (!ft_strncmp(&map[*i], "NO ", 3))
		ft_check_dup_elem(i, id, &id->no, E_NO);
	else if (!ft_strncmp(&map[*i], "SO ", 3))
		ft_check_dup_elem(i, id, &id->so, E_SO);
	else if (!ft_strncmp(&map[*i], "WE ", 3))
		ft_check_dup_elem(i, id, &id->we, E_WE);
	else if (!ft_strncmp(&map[*i], "EA ", 3))
		ft_check_dup_elem(i, id, &id->ea, E_EA);
	else if (!ft_strncmp(&map[*i], "F ", 2))
		ft_check_dup_elem(i, id, &id->f, E_F);
	else if (!ft_strncmp(&map[*i], "C ", 2))
		ft_check_dup_elem(i, id, &id->c, E_C);
	if (id->dup)
		return (E_DUP);
	while (ft_isspace(map[*i]))
		(*i)++;
	if (id->is_fc && map[*i])
		return (ft_check_fc_numbers(map, i, id));
	else if (map[*i])
		return (ft_check_texture_file(map, i, id));
	return (1);
}

void	ft_check_dup_elem(int *i, t_identifier *id, int	*element, \
t_err_type err_type)
{
	id->checker = err_type;
	(*element)++;
	if (err_type == E_F || err_type == E_C)
	{
		(*i)++;
		id->is_fc = true;
	}
	else
	{
		(*i) += 2;
		id->is_fc = false;
	}
	if (*element > 1)
		id->dup = true;
}

int	ft_count_elements(t_identifier *id, char *map, int *i)
{
	if (id->no != 1 || id->so != 1 || id->we != 1 || id->ea != 1 \
	|| id->f != 1 || id->c != 1)
	{
		id->checker = E_WRONG_ELEM;
		return (1);
	}
	if (ft_check_empty_lines(map, i))
	{
		id->checker = E_MAP;
		return (1);
	}
	if (ft_check_map_walls(map, i))
	{
		id->checker = E_MAP;
		return (1);
	}
	if (ft_check_map_player(map, i))
	{
		id->checker = E_MAP;
		return (1);
	}
	return (0);
}
