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

void	draw_line(t_data *mlx, t_pos pos1, t_pos pos2)
{	
	
	pos.x = 
	pos.y = 
	
	pos.dx = abs(pos.x2 - pos.x1);
	pos.dy = abs(pos.y2 - pos.y1);
	pos.e = 0;
	
	if (pos.x <= pos.x2 && pos.y < pos.y2)
		haut_gauche(pos, mlx);
	if (pos.x >= pos.x2 && pos.y >= pos.y2)
		bas_droite(pos, mlx);
	if (pos.x <= pos.x2 && pos.y >= pos.y2)
		bas_gauche(pos, mlx);
	if (pos.x > pos.x2 && pos.y <= pos.y2)
		haut_droite(pos, mlx);
	my_mlx_pixel_put(mlx, , , 0XFF0000);
	my_mlx_pixel_put(mlx, , , 0XFF0000);
}
	
void	haut_gauche(t_pos pos, t_data *mlx)
{
	if (pos.dx > pos.dy)
	{
		while (pos.x <= pos.x2)
		{
			my_mlx_pixel_put(mlx, pos.x, pos.y, 255);
			pos.e -= 2 * pos.dy;
			if (pos.e < 0)
			{
				pos.y++;
				pos.e += 2 * pos.dx;
			}
			pos.x++;
		}
	}
	else
		haut_gauche_bis(pos, mlx);
}

void	bas_droite(t_pos pos, t_data *mlx)
{
	if (pos.dx < pos.dy)
	{
		while (pos.y >= pos.y2)
		{
			my_mlx_pixel_put(mlx, pos.x, pos.y, 255);
			pos.e -= 2 * pos.dx;
			if (pos.e < 0)
			{
				pos.x--;
				pos.e += 2 * pos.dy;
			}
			pos.y--;
		}
	}
	else
		bas_droite_bis(pos, mlx);	
}

void	bas_gauche(t_pos pos, t_data *mlx)
{
	if (pos.dx > pos.dy)
	{
		while (pos.x <= pos.x2)
		{
			my_mlx_pixel_put(mlx, pos.x, pos.y, 255);
			pos.e -= 2 * pos.dy;
			if (pos.e < 0)
			{
				pos.y--;
				pos.e += 2 * pos.dx;
			}
			pos.x++;
		}
	}
	else
		bas_gauche_bis(pos, mlx);
}

void	haut_droite(t_pos pos, t_data *mlx)
{
	if (pos.dx > pos.dy)
	{
		while (pos.x >= pos.x2)
		{
			my_mlx_pixel_put(mlx, pos.x, pos.y, 255);
			pos.e -= 2 * pos.dy;
			if (pos.e < 0)
			{
				pos.y++;
				pos.e += 2 * pos.dx;
			}
			pos.x--;
		}
	}
	else
		haut_droite_bis(pos, mlx);
}
