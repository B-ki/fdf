/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:02:52 by rmorel            #+#    #+#             */
/*   Updated: 2022/05/09 15:59:41 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_map(t_fdf *fdf)
{
	int	i;
	int	nb_col;
	int	nb_line;

	i = 1;
	nb_col = fdf->map[0].x;
	nb_line = fdf->map[0].y;
	while (i <= nb_col * nb_line)
	{
		if (i <= (nb_line - 1) * nb_col)
			bres(&fdf->map[i], &fdf->map[i + nb_col], fdf);
		if (i % nb_col != 0)
			bres(&fdf->map[i], &fdf->map[i + 1], fdf);
		i++;
	}
}

void	init_map(t_point *map)
{
	int	i;
	int	s;

	i = 1;
	if (map[0].x < 30)
		s = SCALE;
	else
		s = SCALE_BIG;
	while (i <= map[0].x * map[0].y)
	{
		map[i].x = map[i].x * s;
		map[i].y = map[i].y * s;
		map[i].z = map[i].z * s / 4;
		i++;
	}
	i = 1;
	while (i <= map[0].x * map[0].y)
	{
		map[i].x = map[i].x - map[0].x / 2 * s;
		map[i].y = map[i].y - map[0].y / 2 * s;
		i++;
	}
}

void	translate_map_x(t_point *map, float t)
{
	int	i;

	i = 1;
	while (i <= map[0].x * map[0].y)
	{
		map[i].x = map[i].x + t;
		i++;
	}
}

void	translate_map_y(t_point *map, float t)
{
	int	i;

	i = 1;
	while (i <= map[0].x * map[0].y)
	{
		map[i].y = map[i].y + t;
		i++;
	}
}
