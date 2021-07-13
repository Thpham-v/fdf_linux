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

void	haut_gauche_bis(t_pos pos, t_data *mlx)
{
	while (pos.y <= pos.y2)
	{
		my_mlx_pixel_put(mlx, pos.x, pos.y, 255);
		pos.e = pos.e - 2 * pos.dx;
		if (pos.e < 0)
		{
			pos.x++;
			pos.e = pos.e + 2 * pos.dy;
		}
		pos.y++;
	}
}

void	bas_droite_bis(t_pos pos, t_data *mlx)
{
	while (pos.x >= pos.x2)
	{
		my_mlx_pixel_put(mlx, pos.x, pos.y, 255);
		pos.e -= 2 * pos.dy;
			if (pos.e < 0)
			{
				pos.y--;
				pos.e += 2 * pos.dx;
			}
			pos.x--;
	}
}

void	bas_gauche_bis(t_pos pos, t_data *mlx)
{
	while (pos.y >= pos.y2)
	{
		my_mlx_pixel_put(mlx, pos.x, pos.y, 255);
		pos.e -= 2 * pos.dx;
		if (pos.e < 0)
		{
			pos.x++;
			pos.e += 2 * pos.dy;
		}
		pos.y--;
	}
}

void	haut_droite_bis(t_pos pos, t_data *mlx)
{
	while (pos.y <= pos.y2)
	{
		my_mlx_pixel_put(mlx, pos.x, pos.y, 255);
		pos.e -= 2 * pos.dx;
		if (pos.e < 0)
		{
			pos.x--;
			pos.e += 2 * pos.dy;
		}
		pos.y++;
	}
}