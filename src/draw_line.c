/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 14:16:55 by thpham-v          #+#    #+#             */
/*   Updated: 2021/08/14 18:54:10 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"
	
void	haut_gauche(t_pos pos1, t_pos pos2, t_data *mlx)
{
	if (pos1.dx > pos1.dy)
	{
		while (pos1.x <= pos2.x)
		{
			my_mlx_pixel_put(mlx, pos1.x, pos1.y, 0X00ffb1);
			pos1.e -= 2 * pos1.dy;
			if (pos1.e < 0)
			{
				pos1.y++;
				pos1.e += 2 * pos1.dx;
			}
			pos1.x++;
		}
	}
	else
		haut_gauche_bis(pos1, pos2, mlx);
}

void	bas_droite(t_pos pos1, t_pos pos2, t_data *mlx)
{
	if (pos1.dx < pos1.dy)
	{
		while (pos1.y >= pos2.y)
		{
			my_mlx_pixel_put(mlx, pos1.x, pos1.y, 0X00ffb1);
			pos1.e -= 2 * pos1.dx;
			if (pos1.e < 0)
			{
				pos1.x--;
				pos1.e += 2 * pos1.dy;
			}
			pos1.y--;
		}
	}
	else
		bas_droite_bis(pos1, pos2, mlx);	
}

void	bas_gauche(t_pos pos1, t_pos pos2, t_data *mlx)
{
	if (pos1.dx > pos1.dy)
	{
		while (pos1.x <= pos2.x)
		{
			my_mlx_pixel_put(mlx, pos1.x, pos1.y, 0X00ffb1);
			pos1.e -= 2 * pos1.dy;
			if (pos1.e < 0)
			{
				pos1.y--;
				pos1.e += 2 * pos1.dx;
			}
			pos1.x++;
		}
	}
	else
		bas_gauche_bis(pos1, pos2, mlx);
}

void	haut_droite(t_pos pos1, t_pos pos2, t_data *mlx)
{
	if (pos1.dx > pos1.dy)
	{
		while (pos1.x >= pos2.x)
		{
			my_mlx_pixel_put(mlx, pos1.x, pos1.y, 0X00ffb1);
			pos1.e -= 2 * pos1.dy;
			if (pos1.e < 0)
			{
				pos1.y++;
				pos1.e += 2 * pos1.dx;
			}
			pos1.x--;
		}
	}
	else
		haut_droite_bis(pos1, pos2, mlx);
}

void	draw_line(t_data *mlx, t_pos pos1, t_pos pos2)
{	
	pos1.dx = abs(pos2.x - pos1.x);
	pos1.dy = abs(pos2.y - pos1.y);
	pos1.e = 0;
	if (pos1.x <= pos2.x && pos1.y < pos2.y)
		haut_gauche(pos1, pos2, mlx);
	if (pos1.x >= pos2.x && pos1.y >= pos2.y)
		bas_droite(pos1, pos2, mlx);
	if (pos1.x <= pos2.x && pos1.y >= pos2.y)
		bas_gauche(pos1, pos2, mlx);
	if (pos1.x > pos2.x && pos1.y <= pos2.y)
		haut_droite(pos1, pos2, mlx);
}
