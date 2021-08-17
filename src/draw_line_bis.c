/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 14:27:54 by thpham-v          #+#    #+#             */
/*   Updated: 2021/07/13 19:23:52 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"

void	haut_gauche_bis(t_pos pos1, t_pos pos2, t_data *mlx)
{
	while (pos1.y <= pos2.y)
	{
		my_mlx_pixel_put(mlx, pos1.x, pos1.y, 255);
		pos1.e = pos1.e - 2 * pos1.dx;
		if (pos1.e < 0)
		{
			pos1.x++;
			pos1.e = pos1.e + 2 * pos1.dy;
		}
		pos1.y++;
	}
}

void	bas_droite_bis(t_pos pos1, t_pos pos2, t_data *mlx)
{
	while (pos1.x >= pos2.x)
	{
		my_mlx_pixel_put(mlx, pos1.x, pos1.y, 255);
		pos1.e -= 2 * pos1.dy;
			if (pos1.e < 0)
			{
				pos1.y--;
				pos1.e += 2 * pos1.dx;
			}
			pos1.x--;
	}
}

void	bas_gauche_bis(t_pos pos1, t_pos pos2, t_data *mlx)
{
	while (pos1.y >= pos2.y)
	{
		my_mlx_pixel_put(mlx, pos1.x, pos1.y, 255);
		pos1.e -= 2 * pos1.dx;
		if (pos1.e < 0)
		{
			pos1.x++;
			pos1.e += 2 * pos1.dy;
		}
		pos1.y--;
	}
}

void	haut_droite_bis(t_pos pos1, t_pos pos2, t_data *mlx)
{
	while (pos1.y <= pos2.y)
	{
		my_mlx_pixel_put(mlx, pos1.x, pos1.y, 255);
		pos1.e -= 2 * pos1.dx;
		if (pos1.e < 0)
		{
			pos1.x--;
			pos1.e += 2 * pos1.dy;
		}
		pos1.y++;
	}
}