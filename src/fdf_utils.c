/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 23:51:37 by thpham-v          #+#    #+#             */
/*   Updated: 2021/07/08 12:18:11 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"

int		key_event(int key, void *params)
{
	params = NULL;
	if (key == ESC)
		exit(0);
	return (0);
}

int		ft_exit(void)
{
	exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_data *mlx, int x, int y, int color)
{
	if ((x >= 0 && x < mlx->width) && (y >= 0 && y < mlx->height))
		mlx->addr[y * mlx->line_length / 4 + x] = color;
}

int		ft_getnbr(char *str)
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
