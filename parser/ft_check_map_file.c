/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-23 09:02:33 by jesopan-          #+#    #+#             */
/*   Updated: 2024-09-23 09:02:33 by jesopan-         ###   ########ç         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_map_file(char **av, t_data *data)
{
	char			*map;
	t_err_type		type_error;

	type_error = 0;
	map = NULL;
	if (ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".cub", 4))
	{
		ft_exit("Incorrect map file extension\n"
			"[hint] The file name should end with .cub\n", NULL, 0, data);
	}
	map = ft_read_file(av[1], data);
	if (!map)
		ft_exit("couldn't open map file\n", NULL, 0, data);
	type_error = ft_check_elements(map);
	if (type_error)
		ft_exit("Wrong texture\n", map, type_error, data);
	free(map);
	return ;
}

char	*ft_read_file(char *file, t_data *data)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	*map_line;

	map_line = ft_strdup("");
	if (!map_line)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (free(map_line), NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = map_line;
		map_line = ft_strjoin(map_line, line);
		free(tmp);
		free(line);
	}
	close(fd);
	if (!map_line[0])
		ft_exit("Map is empty\n", map_line, 0, data);
	return (map_line);
}

int	ft_verify_player_surroundings(char **map_split)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map_split[y])
	{
		x = 0;
		while (map_split[y][x])
		{
			if (ft_strchr("NSEW", map_split[y][x]))
			{
				if (map_split[y][x + 1] == ' ' || map_split[y][x - 1] == ' ' || \
					map_split[y + 1][x] == ' ' || map_split[y - 1][x] == ' ')
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_check_map_player(char *map, int *i)
{
	int		j;
	char	**map_split;

	j = *i;
	map_split = ft_split(&map[j], '\n');
	if (!map_split)
		return (1);
	if (ft_verify_player_surroundings(map_split))
	{
		free_split(map_split);
		ft_write_map_err("The player shouldn't be surround by empty space");
		return (1);
	}
	return (free_split(map_split), 0);
}
