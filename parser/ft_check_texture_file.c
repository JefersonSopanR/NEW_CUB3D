/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_texture_file.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-23 09:06:17 by jesopan-          #+#    #+#             */
/*   Updated: 2024-09-23 09:06:17 by jesopan-         ###   ########ç         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_check_xpm_file(char *file_xpm, t_identifier *id)
{
	int	fd;

	fd = open(file_xpm, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\ncannot open the", 2);
		if (id->checker == E_NO)
			ft_putstr_fd(" NORTH ", 2);
		else if (id->checker == E_SO)
			ft_putstr_fd(" SOUTH ", 2);
		else if (id->checker == E_WE)
			ft_putstr_fd(" WEST ", 2);
		else if (id->checker == E_EA)
			ft_putstr_fd(" EAST ", 2);
		ft_putstr_fd("texture file\n", 2);
		ft_putstr_fd("Make sure the path and the file name is correct: ", 2);
		ft_putstr_fd(file_xpm, 2);
		ft_putstr_fd("\n", 2);
		return (1);
	}
	close(fd);
	return (0);
}

int	ft_check_texture_file(char	*map, int *i, t_identifier *id)
{
	char	*file_xpm;
	int		start;
	int		check_xpm_file;

	check_xpm_file = 0;
	start = (*i);
	if (map[*i] == '\n')
		return (id->checker);
	while (map[*i] && map[*i] != '\n' && !ft_isspace(map[*i]))
		(*i)++;
	file_xpm = ft_substr(map, start, (*i) - start);
	check_xpm_file = ft_check_xpm_file(file_xpm, id);
	if (check_xpm_file)
	{
		free(file_xpm);
		return (E_MAP);
	}
	if (!file_xpm)
		return (1);
	free(file_xpm);
	return (0);
}
