/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 23:52:07 by thpham-v          #+#    #+#             */
/*   Updated: 2021/07/02 06:52:20 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"

void	draw_line(t_data *mlx)
{
	int x1=0,	y1=0;
	int x2=100,	y2=400;
	
	int	x = x1;
	int y = y1;
	
	float dx = abs(x2 - x1);
	float dy = abs(y2 - y1);
	float m = dy / dx;
	float e = 0;
	
	if(x < x2 && y < y2)
	{
		if (x2 > y2)
		{
			while (x < x2)
			{
				printf("a\n");
				my_mlx_pixel_put(mlx, x, y, 255);
				e = e - m;
				if (e < -0.5)
				{
					y++;
					e = e + 1.0;
				}
				x++;
			}
		}
		else
		{
			while (y < y2)
			{
				printf("b\n");
				my_mlx_pixel_put(mlx, x, y, 255);
				e = e - m;
				if (e < -0.5)
				{
					x++;
					e = e + 1.0;
				}
				y++;
			}
		}
	}
	/*while (y < y2)
	{
		printf("b\n");
		my_mlx_pixel_put(mlx, x, y, 255);
		e = e - m;
		if (e < -0.5)
		{
			y++;
			e = e + 1.0;
		}
		x++;
	}
	while (x > x2)
	{
		printf("c\n");
		my_mlx_pixel_put(mlx, x, y, 255);
		e = e - m;
		if (e < -0.5)
		{
			y--;
			e = e + 1.0;
		}
		x--;
	}
	while (y > y2)
	{
		printf("d\n");
		my_mlx_pixel_put(mlx, x, y, 255);
		e = e - m;
		if (e < -0.5)
		{
			y--;
			e = e + 1.0;
		}
		x--;
	}*/
	my_mlx_pixel_put(mlx, x1, y1, 0XFF0000);
	my_mlx_pixel_put(mlx, x2, y2, 0XFF0000);
}

int		main(/*int argc, char **argv*/)
{
	t_data	mlx;
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
	draw_line(&mlx);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
	mlx_hook(mlx.win_ptr, 17, 0, ft_exit, (void *)0);
	mlx_key_hook(mlx.win_ptr, key_event, (void *)0);
	mlx_loop(mlx.mlx_ptr);
}
