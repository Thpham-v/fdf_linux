/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 21:08:06 by thpham-v          #+#    #+#             */
/*   Updated: 2021/09/01 23:23:49 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define ESC 65307

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_data;

typedef struct s_var
{
	t_data		mlx;
	int			nb_l;
	int			nb_c;
	int			fd;
	int			size;
	int			**tab;
	int			startx;
	int			starty;
	int			i;
	int			j;
	int			verif;
}				t_var;

typedef struct s_pos
{
	int		x;
	int		y;
	float	dx;
	float	dy;
	float	e;
}				t_pos;

int		key_event(int key, t_var *var);
int		exit_all(t_var *var);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		ft_read_line(char *file, t_var *var, int ret);
int		ft_count_words(char *s, char c);
void	ft_create_tab(char *s, char c, char **tab);
int		ft_getnbr(char *str);
void	ft_free_tab(char **tab);
char	*ft_strndup(char *src, int n);
void	ft_fill_tab(char **tab, const char *s, char c, int nb_words);
char	**ft_split(char *s, char c);
void	ft_final_map(char *file, t_var *var, int ret);
int		ft_malloc_map(t_var *var);
void	draw_line(t_data *mlx, t_pos pos1, t_pos pos2);
void	haut_gauche_bis(t_pos pos1, t_pos pos2, t_data *mlx);
void	bas_droite_bis(t_pos pos1, t_pos pos2, t_data *mlx);
void	bas_gauche_bis(t_pos pos1, t_pos pos2, t_data *mlx);
void	haut_droite_bis(t_pos pos1, t_pos pos2, t_data *mlx);
void	draw_tab(t_var *var);
void	draw_tab_bis(t_data *mlx, t_var var);
t_pos	get_iso(t_pos pos);
void	draw_x(t_data *mlx, t_var *var);
void	draw_y(t_data *mlx, t_var *var);
void	init_display(t_var *var);
t_pos	get_cart(t_pos iso);
void	ft_init(void *s, size_t n);

#endif
