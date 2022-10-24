/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 02:52:51 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/10/24 04:43:09 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remainder[OPEN_MAX];
	char		*buff;
	char		*tmp;

	while (!ft_strchr(remainder[fd], '\n'))
	{
		buff = get_buff(fd);
		if (buff == NULL)
		{
			return (NULL);
		}
		tmp = remainder[fd];
		remainder[fd] = ft_strjoin(tmp, buff);
		free(tmp);
		free(buff);
	}
	line = ft_substr(remainder[fd],
			0, ft_strchr(remainder[fd], '\n') - remainder[fd] + 1);
	tmp = remainder[fd];
	remainder[fd] = ft_substr(ft_strchr(remainder[fd], '\n') + 1,
			0, ft_strchr(remainder[fd], 0) - remainder[fd]);
	free(tmp);
	return (line);
}
