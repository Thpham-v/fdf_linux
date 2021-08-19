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

t_pos	get_iso(t_pos pos)
{
	t_pos	iso;

	iso.x = (pos.x - pos.y);
	iso.y = (pos.x + pos.y) / 2;
	return (iso);
}

t_pos	get_cart(t_pos iso)
{
	t_pos	cart;

	cart.x = (2 * iso.y + iso.x) / 2;
	cart.y = (2 * iso.y - iso.x) / 2;
	return (cart);
}

void	draw_x(t_data *mlx, t_var *var)
{
	t_pos	pos1;
	t_pos	pos2;
	t_pos	iso1;
	t_pos	iso2;

	pos1.x = var->startx + var->i * var->size;
	pos1.y = var->starty + var->j * var->size;
	pos2.x = pos1.x;
	pos2.y = var->starty + (var->j + 1) * var->size;
	iso1 = get_iso(pos1);
	iso2 = get_iso(pos2);
	iso1.y -= (var->tab[var->j][var->i]) * 3;
	iso2.y -= (var->tab[var->j + 1][var->i]) * 3;
	draw_line(mlx, iso1, iso2);
}	

void	draw_y(t_data *mlx, t_var *var)
{
	t_pos	pos1;
	t_pos	pos2;
	t_pos	iso1;
	t_pos	iso2;

	pos1.x = var->startx + var->i * var->size;
	pos1.y = var->starty + var->j * var->size;
	pos2.x = var->startx + (var->i + 1) * var->size;
	pos2.y = pos1.y;
	iso1 = get_iso(pos1);
	iso2 = get_iso(pos2);
	iso1.y -= (var->tab[var->j][var->i]) * 3;
	iso2.y -= (var->tab[var->j][var->i + 1]) * 3;
	draw_line(mlx, iso1, iso2);
}

void	draw_tab(t_var *var)
{
	init_display(var);
	var->i = 0;
	while (var->i < var->nb_c)
	{
		var->j = 0;
		while (var->j < var->nb_l - 1)
		{
			draw_x(&var->mlx, var);
			var->j++;
		}
		var->i++;
	}
	var->j = 0;
	while (var->j < var->nb_l)
	{
		var->i = 0;
		while (var->i < var->nb_c - 1)
		{
			draw_y(&var->mlx, var);
			var->i++;
		}
		var->j++;
	}
}
