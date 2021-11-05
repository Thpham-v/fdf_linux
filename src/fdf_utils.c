/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 23:51:37 by thpham-v          #+#    #+#             */
/*   Updated: 2021/11/05 14:27:29 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"

int	arg_error(int argc)
{
	if (*__environ == NULL)
		return (-1);
	if (argc != 2)
	{
		printf("Error\nwrong number of arguments\n");
		return (-1);
	}
	return (0);
}

int	key_event(int key, t_var *var)
{
	if (key == ESC)
		exit_all(var);
	return (0);
}

void	my_mlx_pixel_put(t_data *mlx, int x, int y, int color)
{
	if ((x >= 0 && x < mlx->width) && (y >= 0 && y < mlx->height))
		mlx->addr[y * mlx->line_length / 4 + x] = color;
}

int	ft_getnbr(char *str)
{
	size_t	i;
	int		result;

	i = 0;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		result = (result * 10) + (str[i++] - '0');
	if (str[0] == '-')
		result *= -1;
	return (result);
}
