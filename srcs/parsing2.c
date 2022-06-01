/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:32:20 by rmorel            #+#    #+#             */
/*   Updated: 2022/05/09 16:59:22 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*create_map(char **av, t_fdf *fdf)
{
	int		fd;
	char	*buff;
	char	*line;
	char	**total_line;
	t_point	*map;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit_clean(fdf);
	buff = get_next_line(fd);
	if (!buff)
		exit_clean(fdf);
	line = NULL;
	while (buff)
	{
		line = join_gnl(line, buff);
		free(buff);
		buff = get_next_line(fd);
	}
	total_line = ft_split(line, '\n');
	map = str_to_map(line, total_line);
	free(buff);
	free(line);
	free_split(total_line);
	return (map);
}

void	fill_zero_map(t_point *map, char *line)
{
	map[0].x = count_col(line);
	map[0].y = count_line(line);
	map[0].z = 0;
	if (map && map[1].trgb)
		map[0].trgb = 1;
	else
		map[0].trgb = 0;
}

void	free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

u_int32_t	hex_to_int(char *hex)
{
	u_int32_t	val;
	u_int8_t	byte;

	val = 0;
	while (*hex)
	{
		byte = *hex++;
		if (byte >= '0' && byte <= '9')
			byte = byte - '0';
		else if (byte >= 'a' && byte <= 'z')
			byte = byte - 'a' + 10;
		else if (byte >= 'A' && byte <= 'Z')
			byte = byte - 'A' + 10;
		val = (val << 4) | (byte & 0xF);
	}
	return (val);
}

void	copy_map(t_point *m1, t_point *m2)
{
	int	i;

	i = 0;
	while (i <= m1[0].x * m1[0].y)
	{
		m2[i].x = m1[i].x;
		m2[i].y = m1[i].y;
		m2[i].z = m1[i].z;
		m2[i].trgb = m1[i].trgb;
		i++;
	}	
}
