/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 23:52:07 by thpham-v          #+#    #+#             */
/*   Updated: 2021/08/19 23:40:11 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"

void	init_display(t_var *var)
{
	int		sizex;
	int		sizey;
	t_pos	cart;
	t_pos	iso;

	iso.x = var->mlx.width / 2;
	iso.y = var->mlx.height / 2;
	cart = get_cart(iso);
	sizex = var->mlx.width / (var->nb_c * 2);
	sizey = var->mlx.height / (var->nb_l * 2);
	var->size = sizex + 2;
	if (sizex >= sizey)
		var->size = sizey + 2;
	var->startx = cart.x - var->nb_c / 2 * var->size;
	var->starty = cart.y - var->nb_l / 2 * var->size;
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = s;
	i = -1;
	while (++i < n)
	{
		str[i] = 0;
	}
	s = str;
}

int	exit_all(t_var *var)
{
	int	i;

	i = -1;
	if (var->tab)
	{
		while (++i < var->nb_l)
			free(var->tab[i]);
		free(var->tab);
	}
	if (var->mlx.img_ptr)
		mlx_destroy_image(var->mlx.mlx_ptr, var->mlx.img_ptr);
	if (var->mlx.win_ptr)
		mlx_destroy_window(var->mlx.mlx_ptr, var->mlx.win_ptr);
	if (var->mlx.mlx_ptr)
	{
		mlx_destroy_display(var->mlx.mlx_ptr);
		free(var->mlx.mlx_ptr);
	}
	exit(0);
	return (0);
}

void	init_var_windows(t_var *var)
{
	var->mlx.width *= 0.8;
	var->mlx.height *= 0.6;
	var->mlx.win_ptr = mlx_new_window
		(var->mlx.mlx_ptr, var->mlx.width, var->mlx.height, "FDF");
	var->mlx.img_ptr = mlx_new_image
		(var->mlx.mlx_ptr, var->mlx.width, var->mlx.height);
	var->mlx.addr = (int *)mlx_get_data_addr
		(var->mlx.img_ptr, &var->mlx.bits_per_pixel, &var->mlx.line_length,
			&var->mlx.endian);
}

int	main(int argc, char **argv)
{
	t_var	var;

	if (argc != 2)
	{
		printf("Error\nwrong number of arguments\n");
		return (0);
	}
	ft_bzero(&var, sizeof(t_var));
	if ((ft_read_line(argv[1], &var) != -1))
	{
		ft_malloc_map(&var);
		ft_final_map(argv[1], &var, 1);
		var.mlx.mlx_ptr = mlx_init();
		mlx_get_screen_size(var.mlx.mlx_ptr, &var.mlx.width, &var.mlx.height);
		init_var_windows(&var);
		draw_tab(&var);
		mlx_put_image_to_window
			(var.mlx.mlx_ptr, var.mlx.win_ptr, var.mlx.img_ptr, 0, 0);
		mlx_hook(var.mlx.win_ptr, 17, 0, exit_all, &var);
		mlx_key_hook(var.mlx.win_ptr, key_event, &var);
		mlx_loop(var.mlx.mlx_ptr);
	}
	exit_all(&var);
	return (0);
}
