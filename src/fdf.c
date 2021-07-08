/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 23:52:07 by thpham-v          #+#    #+#             */
/*   Updated: 2021/07/08 15:17:43 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"

	
int		main(/*int argc, char **argv*/)
{
	t_data	mlx;
	t_pos	pos;
	//t_var	var;
	
	//argc = 0;
	//ft_read_line(argv[1], &var);
	//ft_malloc_map(&var);
	//ft_final_map(argv[1], &var);
	mlx.width = 800;
	mlx.height = 600;
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 800, 600, "Hello world!");
	mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, 800, 600);
	mlx.addr = (int *)mlx_get_data_addr(mlx.img_ptr, &mlx.bits_per_pixel, &mlx.line_length,
			&mlx.endian);
	draw_line(pos, &mlx);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
	mlx_hook(mlx.win_ptr, 17, 0, ft_exit, (void *)0);
	mlx_key_hook(mlx.win_ptr, key_event, (void *)0);
	mlx_loop(mlx.mlx_ptr);
}
