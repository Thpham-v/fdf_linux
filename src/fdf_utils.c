/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 23:51:37 by thpham-v          #+#    #+#             */
/*   Updated: 2021/06/25 04:17:39 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/get_next_line.h"

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
	mlx->addr[y * (mlx->line_length / 4) + x] = color;
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
