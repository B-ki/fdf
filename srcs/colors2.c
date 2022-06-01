/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:20:31 by rmorel            #+#    #+#             */
/*   Updated: 2022/05/09 15:58:05 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	add_shade(double distance, int trgb)
{
	return (create_trgb(get_t(trgb), get_r(trgb) * (1 - distance),
			get_g(trgb) * (1 - distance), get_b(trgb) * (1 - distance)));
}

int	get_opposite_color(int trgb)
{
	return ((~trgb) & 0xFF);
}

int	average_color(int trgb_1, int trgb_2)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = (get_t(trgb_1) + get_t(trgb_2)) / 2;
	r = (get_r(trgb_1) + get_r(trgb_2)) / 2;
	g = (get_g(trgb_1) + get_g(trgb_2)) / 2;
	b = (get_b(trgb_1) + get_b(trgb_2)) / 2;
	return (create_trgb(t, r, g, b));
}

int	color_grad(float x, int z)
{
	int	trgb_min;
	int	trgb_max;

	if (z > 0)
	{
		trgb_max = RGB_POS_MAX;
		trgb_min = RGB_POS_MIN;
	}
	else
	{
		trgb_max = RGB_NEG_MIN;
		trgb_min = RGB_NEG_MAX;
	}
	return (create_trgb(get_t(trgb_min) * x + get_t(trgb_max) * (1 - x),
			get_r(trgb_min) * x + get_r(trgb_max) * (1 - x),
			get_g(trgb_min) * x + get_g(trgb_max) * (1 - x),
			get_b(trgb_min) * x + get_b(trgb_max) * (1 - x)));
}

void	fill_color(t_fdf *fdf)
{
	int		i;
	float	z_min;
	float	z_max;

	i = 1;
	z_min = get_min_z(fdf);
	z_max = get_max_z(fdf);
	if (fdf && fdf->map && fdf->map[0].trgb)
		return ;
	while (i <= fdf->map[0].x * fdf->map[0].y)
	{
		if (fdf->map[i].z < 0)
			fdf->map[i].trgb = color_grad(-fdf->map[i].z / z_min, -1);
		else if (fdf->map[i].z >= 0)
			fdf->map[i].trgb = color_grad(fdf->map[i].z / z_max, 1);
		else
			fdf->map[i].trgb = RGB_NULL;
		i++;
	}
}
