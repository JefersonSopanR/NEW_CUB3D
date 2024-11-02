/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_parser_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesopan- <jesopan-@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-23 09:08:03 by jesopan-          #+#    #+#             */
/*   Updated: 2024-09-23 09:08:03 by jesopan-         ###   ########ç         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit(char *msg, char *map, t_err_type type_error, t_data *data)
{
	if (map)
		free(map);
	if (type_error != E_MAP)
		ft_putstr_fd("Error\n", 2);
	if (type_error == E_NO)
		ft_putstr_fd("Wrong NO texture\n", 2);
	else if (type_error == E_SO)
		ft_putstr_fd("Wrong SO texture\n", 2);
	else if (type_error == E_WE)
		ft_putstr_fd("Wrong WE texture\n", 2);
	else if (type_error == E_EA)
		ft_putstr_fd("Wrong EA texture\n", 2);
	else if (type_error == E_F)
		ft_putstr_fd("Wrong F texture\n", 2);
	else if (type_error == E_C)
		ft_putstr_fd("Wrong C texture\n", 2);
	else if (type_error == E_WRONG_ELEM)
		ft_putstr_fd("Wrong element\n", 2);
	else if (type_error == E_DUP)
		ft_putstr_fd("Duplicate element\n", 2);
	else if (msg && type_error != E_MAP)
		ft_putstr_fd(msg, 2);
	free(data);
	exit(1);
}

void	ft_write_map_err(char *err_msg)
{
	ft_putstr_fd("\e[31mError\n\e[0m", 2);
	ft_putstr_fd(err_msg, 2);
	ft_putstr_fd("\n", 2);
}
