/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 16:53:04 by thpham-v          #+#    #+#             */
/*   Updated: 2021/07/12 18:49:55 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"

void	draw_tab(t_data *mlx, t_var var)
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
	while (j < var.nb_l - 1)
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
}