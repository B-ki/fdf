/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 21:34:30 by rmorel            #+#    #+#             */
/*   Updated: 2022/05/09 16:59:11 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	count_line(char *str)
{
	int		i;
	float	count;

	i = 0;
	count = 0;
	while (str && str[i])
	{
		if (str[i] < 32)
			count++;
		i++;
	}
	return (count);
}

float	count_col(char *str)
{
	int		i;
	float	count;

	i = 0;
	count = 0;
	while (str && str[i] && str[i] != '\n')
	{
		while (str[i] == 32)
			i++;
		if (str[i] > 32)
		{
			count++;
			while (str[i] > 32)
				i++;
		}
	}
	return (count);
}

t_point	*str_to_map(char *line, char **total_line)
{
	t_point	*map;
	t_var	v;
	char	**line_split;

	map = malloc(sizeof(t_point) * (count_line(line) * count_col(line) + 1));
	if (!map)
		return (NULL);
	v.i = 0;
	v.j = 0;
	v.m = 1;
	while (total_line[(int)v.i])
	{
		line_split = ft_split(total_line[(int)v.i], ' ');
		while (line_split[(int)v.j])
		{
			fill_map(map, v, line_split);
			v.j++;
			v.m++;
		}
		v.i++;
		v.j = 0;
		free_split(line_split);
	}
	fill_zero_map(map, line);
	return (map);
}

void	fill_map(t_point *map, t_var v, char **line_split)
{
	char	*hex;

	map[v.m].x = v.j;
	map[v.m].y = v.i;
	if (ft_strchr(line_split[(int)v.j], ','))
	{
		hex = ft_strchr(line_split[(int)v.j] + 1, ',');
		hex += 2;
		map[v.m].trgb = hex_to_int(hex);
	}
	else
		map[v.m].trgb = 0;
	map[v.m].z = (float)ft_atoi(line_split[(int)v.j]);
}

void	create_copy(t_fdf *fdf)
{
	fdf->m_cpy = malloc(sizeof(t_point) * (fdf->map[0].x * fdf->map[0].y + 1));
	if (!fdf->m_cpy)
		return ;
	copy_map(fdf->map, fdf->m_cpy);
}
