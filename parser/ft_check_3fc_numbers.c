/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_3fc_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-23 09:05:57 by jesopan-          #+#    #+#             */
/*   Updated: 2024-09-23 09:05:57 by jesopan-         ###   ########ç         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_fc_numbers(char *map, int *i, t_identifier *id)
{
	int		comma;

	comma = 0;
	if (!ft_isdigit(map[*i]))
		return (id->checker);
	while (map[*i] && map[*i] != '\n')
	{
		if (ft_check_digit_fc(map, i))
			return (id->checker);
		if (ft_isspace(map[*i]) || map[*i] == ',')
		{
			if (ft_skip_spaces(map, i, &comma))
				return (id->checker);
		}
		else
			break ;
	}
	if (comma != 2)
		return (id->checker);
	return (0);
}

int	ft_check_digit_fc(char *map, int *i)
{
	char	*char_digit;
	int		digit;
	int		start;

	start = (*i);
	while (ft_isdigit(map[*i]))
		(*i)++;
	char_digit = ft_substr(map, start, (*i) - start);
	if (!char_digit)
		return (1);
	digit = ft_atoi(char_digit);
	free(char_digit);
	if (digit < 0 || digit > 255)
		return (1);
	return (0);
}

int	ft_skip_spaces(char *map, int *i, int *comma)
{
	if (!map[*i])
		return (1);
	while (ft_isspace(map[*i]))
		(*i)++;
	if (map[*i] == ',')
	{
		(*i)++;
		(*comma)++;
	}
	else
		return (1);
	while (ft_isspace(map[*i]))
		(*i)++;
	if (!ft_isdigit(map[*i]))
		return (1);
	return (0);
}
