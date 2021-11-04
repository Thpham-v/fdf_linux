/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_final_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 00:49:29 by thpham-v          #+#    #+#             */
/*   Updated: 2021/11/04 17:12:20 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"

int	open_file(char *file, t_var *var)
{
	var->fd = open(file, O_DIRECTORY);
	if (var->fd != -1)
	{
		printf("Error it is a directory\n");
		return (-1);
	}
	var->fd = open(file, O_RDONLY);
	if (var->fd == -1)
		return (-1);
	return (0);
}

int	ft_read_line(char *file, t_var *var, int ret)
{
	int		nb_c_temp;
	char	*line;

	if (open_file(file, var) == -1)
		return (-1);
	while (ret)
	{
		ret = get_next_line(var->fd, &line, 1);
		if (line[0] != '\0')
		{
			var->nb_c = ft_count_words(line, ' ');
			if (var->nb_l != 0 && var->nb_c != nb_c_temp)
				var->verif = 1;
			nb_c_temp = var->nb_c;
			var->nb_l++;
		}
		free(line);
	}
	if (var->verif == 1)
	{
		printf("Error\nwrong map\n");
		exit_all(var);
	}
	return (ret);
}

int	ft_malloc_map(t_var *var)
{
	int	i;

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

void	ft_final_map(char *file, t_var *var, int ret)
{
	int		i;
	int		j;
	char	*line;
	char	**tab_char;

	i = 0;
	ret = 1;
	var->fd = open(file, O_RDONLY);
	while (ret)
	{
		ret = get_next_line(var->fd, &line, 1);
		if (line[0] != '\0')
		{
			tab_char = ft_split(line, ' ');
			j = 0;
			while (tab_char[j])
			{
				var->tab[i][j] = ft_getnbr(tab_char[j]);
				j++;
			}
			ft_free_tab(tab_char);
			i++;
		}
		free(line);
	}
}
