/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 20:02:16 by thpham-v          #+#    #+#             */
/*   Updated: 2021/09/01 18:58:40 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"

int	ft_free(char *str)
{
	if (!str)
		return (0);
	free(str);
	return (0);
}

int	get_next_line(int fd, char **line, int ret)
{
	static char	*temp;
	char		buff[BUFFER_SIZE + 1];

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while (!ft_is_break_line(temp) && ret != 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		temp = ft_strjoin(temp, buff);
	}
	*line = ft_get_line(temp);
	temp = ft_get_temp(temp);
	if (!*line || !temp)
		return (-1);
	if (ret == 0)
	{
		ret = ft_free(temp);
		temp = NULL;
		return (0);
	}
	return (1);
}
