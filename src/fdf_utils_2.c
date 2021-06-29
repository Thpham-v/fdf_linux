/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 00:49:29 by thpham-v          #+#    #+#             */
/*   Updated: 2021/06/29 06:39:18 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/get_next_line.h"

void	ft_read_line(char *file, t_var *var)
{
	int		ret;
	int		nb_c_temp;
	char	*line;

	var->nb_l = 0;
	var->nb_c = 0;
	var->fd = 0;
	ret = 1;
	var->fd = open(file, O_RDONLY);
	while (ret)
	{
		ret = get_next_line(var->fd, &line);
		if (line[0] != '\0')
		{
			nb_c_temp = ft_count_words(line, ' ');
			if (var->nb_c < nb_c_temp)
				var->nb_c = nb_c_temp;
			var->nb_l++;
		}
			free(line);
	}
}

int		ft_malloc_map(t_var *var)
{
	int i;
	
	i = 0;
	var->tab = malloc(sizeof(int *) * var->nb_l);
	if (!var->tab)
		return (0);
	while (i < var->nb_l)
	{
		var->tab[i] = malloc(sizeof(int) * var->nb_c);
		if (!var->tab[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_final_map(char *file, t_var *var)
{
	int		i;
	int		j;
	int		ret;
	char	*line;
	char	**tab_char;
	
	i = 0;
	ret = 1;
	var->fd = open(file, O_RDONLY);
	while (ret)
	{
		ret = get_next_line(var->fd, &line);
		if (line[0] != '\0')
		{
			tab_char = ft_split(line, ' ');
			j = 0;
			while (tab_char[j])
			{
				var->tab[i][j] = ft_getnbr(tab_char[j]);
				j++;
			}
		}
		free(line);
		i++;
		}
}

void	affiche_tab(t_var *var)
{
	int i;
	int j;

	i = 0;
	while (i < var->nb_l)
	{
		j = 0;
		while (j < var->nb_c)
		{
			printf("%d  ", var->tab[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
