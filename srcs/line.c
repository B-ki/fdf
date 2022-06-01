/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:09:52 by rmorel            #+#    #+#             */
/*   Updated: 2022/05/09 16:55:43 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bres(t_point *t_p1, t_point *t_p2, t_fdf *fdf)
{
	int	dx;
	int	dy;

	dx = t_p2->x - t_p1->x;
	dy = t_p2->y - t_p1->y;
	if ((t_p1->x > W_W / 2 && t_p2->x > W_W / 2) || (t_p1->x < -W_W
			/ 2 && t_p2->x < -W_W / 2) || (t_p1->y > W_H / 2 && t_p2->y
			> W_H / 2) || (t_p1->y < -W_H / 2 && t_p2->y < -W_H / 2))
		return ;
	else if (dx > 0 && dy >= 0 && dx >= dy)
		bres_0_1(t_p1, t_p2, fdf, average_color(t_p1->trgb, t_p2->trgb));
	else if (dx >= 0 && dy > 0 && dy >= dx)
		bres_1_8(t_p1, t_p2, fdf, average_color(t_p1->trgb, t_p2->trgb));
	else if (dx < 0 && dy >= 0 && dy >= -dx)
		bres_m1_m8(t_p1, t_p2, fdf, average_color(t_p1->trgb, t_p2->trgb));
	else if (dx <= 0 && dy > 0 && - dx >= dy)
		bres_0_m1(t_p1, t_p2, fdf, average_color(t_p1->trgb, t_p2->trgb));
	else if (dx < 0 && dy <= 0 && - dx >= -dy)
		bres_0_1(t_p2, t_p1, fdf, average_color(t_p1->trgb, t_p2->trgb));
	else if (dx <= 0 && dy < 0 && - dy >= -dx)
		bres_1_8(t_p2, t_p1, fdf, average_color(t_p1->trgb, t_p2->trgb));
	else if (dx > 0 && dy <= 0 && - dy >= dx)
		bres_m1_m8(t_p2, t_p1, fdf, average_color(t_p1->trgb, t_p2->trgb));
	else
		bres_0_m1(t_p2, t_p1, fdf, average_color(t_p1->trgb, t_p2->trgb));
}

void	bres_0_1(t_point *t_p1, t_point *t_p2, t_fdf *fdf, int trgb)
{
	int	x1;
	int	x2;
	int	y1;
	int	y2;
	int	e;

	x1 = t_p1->x;
	x2 = t_p2->x;
	y1 = t_p1->y;
	y2 = t_p2->y;
	e = x2 - x1;
	while (x1 <= x2)
	{
		my_mlx_pixel_put(fdf, x1, y1, trgb);
		x1++;
		e = e - (y2 - y1) * 2;
		if (e <= 0)
		{
			y1++;
			e = e + (x2 - x1) * 2;
		}
	}
}

void	bres_1_8(t_point *t_p1, t_point *t_p2, t_fdf *fdf, int trgb)
{
	int	x1;
	int	x2;
	int	y1;
	int	y2;
	int	e;

	x1 = t_p1->x;
	x2 = t_p2->x;
	y1 = t_p1->y;
	y2 = t_p2->y;
	e = y2 - y1;
	while (y1 <= y2)
	{
		my_mlx_pixel_put(fdf, x1, y1, trgb);
		y1++;
		e = e - (x2 - x1) * 2;
		if (e <= 0)
		{
			x1++;
			e = e + (y2 - y1) * 2;
		}
	}
}

void	bres_0_m1(t_point *t_p1, t_point *t_p2, t_fdf *fdf, int trgb)
{
	int	x1;
	int	x2;
	int	y1;
	int	y2;
	int	e;

	x1 = t_p1->x;
	x2 = t_p2->x;
	y1 = t_p1->y;
	y2 = t_p2->y;
	e = x2 - x1;
	while (x1 >= x2)
	{
		my_mlx_pixel_put(fdf, x1, y1, trgb);
		x1--;
		e = e + (y2 - y1) * 2;
		if (e >= 0)
		{
			y1++;
			e = e + (x2 - x1) * 2;
		}
	}
}

void	bres_m1_m8(t_point *t_p1, t_point *t_p2, t_fdf *fdf, int trgb)
{
	int	x1;
	int	x2;
	int	y1;
	int	y2;
	int	e;

	x1 = t_p1->x;
	x2 = t_p2->x;
	y1 = t_p1->y;
	y2 = t_p2->y;
	e = y2 - y1;
	while (y1 <= y2)
	{
		my_mlx_pixel_put(fdf, x1, y1, trgb);
		y1++;
		e = e + (x2 - x1) * 2;
		if (e <= 0)
		{
			x1--;
			e = e + (y2 - y1) * 2;
		}
	}
}
