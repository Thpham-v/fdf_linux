/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 16:53:04 by thpham-v          #+#    #+#             */
/*   Updated: 2021/08/14 19:17:28 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"

void	get_iso(t_pos *pos)
{

}

/*void	draw_tab(t_data *mlx, t_var var)
{
	t_pos pos;
	int i;
	int j;

	i = 0;
	j = 0;
	pos.x1 = 0;
	pos.x2 = 0;
	pos.y1 = 0;
	pos.y2 = 0;
	while (j < var.nb_l)
	{
		i = 0;
		pos.x2 = 0;
		pos.x1 = 0;
		while (i < var.nb_c - 1)
		{
			pos.x2 += 35;
			draw_line(pos, mlx);
			pos.x1 += 35;
			i++;	
		}
		pos.y1 += 20;
		pos.y2 += 20;
		j++;
	}
	i = 0;
	j = 0;
	pos.x1 = 0;
	pos.x2 = 0;
	pos.y1 = 0;
	pos.y2 = 0;
	while (j < var.nb_c)
	{
		i = 0;
		pos.y1 = 0;
		pos.y2 = 0;
		while (i < var.nb_l - 1)
		{
			pos.y2 += 20;
			draw_line(pos, mlx);
			pos.y1 += 20;
			i++;	
		}
		pos.x1 += 35;
		pos.x2 += 35;
		j++;
	}
}*/

void	draw_x(t_var *var)
{
	
}	

void	draw_y(t_var *var)
{
	
}

void	draw_tab(t_var *var)
{
	int i;
	int j;
	
	i = 0;
	while (i < var->nb_c)
	{
		j = 0;
		while (j < var->nb_l)
		{
			draw_x(var);
			j++;
		}
		i++;
	}
	j = 0;
	while (j < var->nb_l)
	{
		i = 0;
		while (i < var->nb_c)
		{
			draw_y(var);
			i++;
		}
		j++;
	}
}
