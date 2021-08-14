#ifndef FDF_H
# define FDF_H
# define ESC 53

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"

typedef struct    s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int            width;
	int            height;
}                t_data;

typedef struct	s_var
{
	int			nb_l;
	int			nb_c;
	int			fd;
	int			size;
	int			**tab;
}				t_var;

typedef struct	s_pos
{
	int	x;
	int y;
	float dx;
	float dy;
	float e;
}				t_pos;

int		key_event(int key, void *params);
int		ft_exit(void);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_read_line(char *file, t_var *var);
int		ft_count_words(char *s, char c);
void	ft_create_tab(char *s, char c, char **tab);
int		ft_getnbr(char *str);
void	ft_free_tab(char **tab, int size);
char	*ft_strndup(char *src, int n);
void	ft_fill_tab(char **tab, const char *s, char c, int nb_words);
char	**ft_split(char *s, char c);
void	ft_final_map(char *file, t_var *var);
int		ft_malloc_map(t_var *var);
void	draw_line(t_pos pos, t_data *mlx);
void	haut_gauche(t_pos pos, t_data *mlx);
void	haut_gauche_bis(t_pos pos, t_data *mlx);
void	bas_droite(t_pos pos, t_data *mlx);
void	bas_droite_bis(t_pos pos, t_data *mlx);
void	bas_gauche(t_pos pos, t_data *mlx);
void	bas_gauche_bis(t_pos pos, t_data *mlx);
void	haut_droite(t_pos pos, t_data *mlx);
void	haut_droite_bis(t_pos pos, t_data *mlx);
void	draw_tab(t_data *mlx, t_var *var, t_pos pos);
void	draw_tab_bis(t_data *mlx, t_var var);
void	get_iso(t_pos *pos);
void	draw_x(t_data *mlx, t_var *var, t_pos pos);
void	draw_y(t_data *mlx, t_var *var, t_pos pos);


#endif
