/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-23 09:41:39 by jesopan-          #+#    #+#             */
/*   Updated: 2024-09-23 09:41:39 by jesopan-         ###   ########ç         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_map(t_data *data)
{
	int	i;

	i = 0;
	printf("NO -> (%s)\n", data->no_texture.xpm_file);
	printf("SO -> (%s)\n", data->so_texture.xpm_file);
	printf("WE -> (%s)\n", data->we_texture.xpm_file);
	printf("EA -> (%s)\n", data->ea_texture.xpm_file);
	printf("F -> (%d, %d, %d)\n", data->floor_color.r, data->floor_color.g, data->floor_color.b);
	printf("C -> (%d, %d, %d)\n", data->ceiling_color.r, data->ceiling_color.g, data->ceiling_color.b);
	printf("ceil -> %d\n", data->ceiling_color.rgb);
	printf("floor -> %d\n", data->floor_color.rgb);
	printf("MAP\n");
	while (data->map_2d[i])
	{
		printf("(%s)\n", data->map_2d[i]);
		i++;
	}
	printf("Player position: x = %f, y = %f\n", data->player.x, data->player.y);
	printf("Player angle: %f\n", data->player.angle);
}

int	ft_close(t_data *data)
{
	printf("Closing\n");
	ft_free_data(data);
	exit(0);
}

int	ft_key_press(int keycode, t_data *data)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
		ft_close(data);
	if (keycode == KEY_W)
		data->player.direction = UP;
	if (keycode == KEY_S)
		data->player.direction = DOWN;
	if (keycode == KEY_A)
		data->player.direction = LEFT;
	if (keycode == KEY_D)
		data->player.direction = RIGHT;
	if (keycode == KEY_LEFT)
		data->player.rotation = LEFT;
	if (keycode == KEY_RIGHT)
		data->player.rotation = RIGHT;
	return (0);
}

int	ft_key_unpress(int keycode, t_data *data)
{
	if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A \
	|| keycode == KEY_D)
		data->player.direction = 0;
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		data->player.rotation = 0;
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
	{
		ft_putstr_fd("Error\nmalloc", 2);
		exit(1);
	}
	if (ac != 2)
	{
		ft_putstr_fd("Error\nWrong number of arguments\n", 2);
		free(data);
		exit(1);
	}
	ft_check_map_file(av, data);
	ft_retrieve_map(av, data);
	ft_print_map(data);
	ft_init_mlx(data);
	ft_get_xpm_textures(data);
	mlx_loop_hook(data->mlx, ft_update_render, data);
	mlx_hook(data->win, 2, 1, ft_key_press, data);
	mlx_hook(data->win, 3, 10, ft_key_unpress, data);
	mlx_hook(data->win, 17, 0, ft_close, data);
	mlx_loop(data->mlx);
	ft_free_data(data);
	return (0);
}
