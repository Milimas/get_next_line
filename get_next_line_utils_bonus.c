/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeihaqi <abeihaqi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:57:33 by abeihaqi          #+#    #+#             */
/*   Updated: 2022/10/26 01:38:01 by abeihaqi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	s = (const char *)src;
	d = (char *)dst;
	if (!s && !d)
		return (NULL);
	while (n--)
		*d++ = *s++;
	return (dst);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*str;

	s1len = ft_strchr((char *)s1, 0) - s1;
	s2len = ft_strchr((char *)s2, 0) - s2;
	str = (char *)malloc((s1len + s2len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, s1len);
	ft_memcpy(str + s1len, s2, s2len);
	str[s1len + s2len] = 0;
	free(s1);
	return (str);
}

char	*ft_strchr(char *buff, char c)
{
	if (buff != NULL)
	{
		while (*buff && *buff != c)
			buff++;
		if (*buff == c)
			return (buff);
	}
	return (NULL);
}

char	*get_buff(int fd)
{
	char	*buff;
	ssize_t	rbytes;

	buff = malloc(BUFFER_SIZE + 1);
	rbytes = read(fd, buff, BUFFER_SIZE);
	if (rbytes > 0 && rbytes <= BUFFER_SIZE)
	{
		buff[rbytes] = 0;
		return (buff);
	}
	free(buff);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (len > (size_t)(ft_strchr((char *)s + start, 0) - s + start))
		len = ft_strchr((char *)s + start, 0) - s + start;
	if (len <= 0 || !s)
		return (NULL);
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	ft_memcpy(sub, s + start, len);
	sub[len] = 0;
	return (sub);
}
