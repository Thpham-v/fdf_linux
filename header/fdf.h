#ifndef FDF_H
# define FDF_H
# define ESC 53

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx_macos/mlx.h"

typedef struct    s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	//int            width;
	//int            height;
}                t_data;

typedef struct	s_var
{
	int			nb_l;
	int			nb_c;
	int			fd;
	int			**tab;
}				t_var;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
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
void	affiche_tab(t_var *var);
int		ft_malloc_map(t_var *var);

#endif
