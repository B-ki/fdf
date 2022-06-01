/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:56:11 by rmorel            #+#    #+#             */
/*   Updated: 2022/05/09 15:59:23 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*get_next_line(int fd)
{
	static char	*prev;
	char		*buff;
	int			ret;

	if (!prev)
		prev = NULL;
	buff = malloc(sizeof(char) * (50 + 1));
	if (!buff)
		return (NULL);
	ret = 1;
	while (ret > 0 && !search_nl(prev))
	{
		ret = read(fd, buff, 50);
		if (ret > 0)
		{
			buff[ret] = '\0';
			prev = join_gnl(prev, buff);
		}
	}
	if (buff)
		free(buff);
	if (ret < 0)
		return (NULL);
	return (newline_gnl(&prev));
}

char	*join_gnl(char *prev, char *buff)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	dest = malloc(sizeof(char) * (ft_strlen(prev) + ft_strlen(buff) + 1));
	if (!dest)
		return (NULL);
	while (prev && prev[i])
	{
		dest[i] = prev[i];
		i++;
	}
	while (buff && buff[j])
	{
		dest[i] = buff[j];
		i++;
		j++;
	}
	free(prev);
	dest[i] = '\0';
	return (dest);
}

int	size_gnl(char *s, int start, int len)
{
	int	i;

	i = 0;
	while (s && s[start + i])
		i++;
	if (i < len)
		return (i + 1);
	return (len + 1);
}

char	*substr_gnl(char *s, int start, int len)
{
	int		i;
	char	*dest;

	i = 0;
	if (!s || s[0] == '\0')
		return (NULL);
	if (start > (int)ft_strlen(s))
	{
		dest = malloc(sizeof(char));
		dest[0] = '\0';
		return (dest);
	}
	dest = malloc(sizeof(char) * size_gnl(s, start, len));
	if (!dest)
		return (NULL);
	while (s[start] && i < len)
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*newline_gnl(char **prev)
{
	char	*tmp;
	int		sz;
	char	*newline;

	tmp = *prev;
	sz = 0;
	newline = NULL;
	if (*prev)
	{
		sz = search_nl(*prev) - *prev + 1;
		newline = substr_gnl(*prev, 0, sz);
		*prev = substr_gnl(*prev, sz, ft_strlen(*prev) - sz);
		free(tmp);
	}
	return (newline);
}
