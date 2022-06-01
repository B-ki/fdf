/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:50:35 by rmorel            #+#    #+#             */
/*   Updated: 2022/05/09 16:56:44 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	try_all_lines(t_fdf *fdf)
{
	int	i;

	i = -1;
	while (++i <= W_W)
		bres(point(W_W / 2, W_H / 2, 0), point(i, 0, 0), fdf);
	i = -1;
	while (++i <= W_H)
		bres(point(W_W / 2, W_H / 2, 0), point(0, i, 0), fdf);
	i = -1;
	while (++i <= W_W)
		bres(point(W_W / 2, W_H / 2, 0), point(i, W_H, 0), fdf);
	i = -1;
	while (++i <= W_H)
		bres(point(W_W / 2, W_H / 2, 0), point(W_W, i, 0), fdf);
}

void	check_variables(t_fdf *fdf)
{
	ft_printf("fdf %p\n", fdf);
	ft_printf("data %p\n", fdf->data);
	ft_printf("mlx %p\n", fdf->mlx);
	ft_printf("win %p\n", fdf->win);
	ft_printf("data->img %p\n", fdf->data->img);
	ft_printf("data->addr %p\n", fdf->data->addr);
	ft_printf("data->bits %d\n", fdf->data->bpp);
	ft_printf("data->line %d\n", fdf->data->line_lgth);
	ft_printf("data->endian %d\n", fdf->data->endian);
	ft_printf("data->x %d\n", fdf->data->x);
	ft_printf("data->y %d\n", fdf->data->y);
}

void	check_points(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i <= 20)
	{
		printf("point %d : x = %f, y = %f, z = %f, trgb = %d\n", i,
			fdf->map[i].x, fdf->map[i].y, fdf->map[i].z, fdf->map[i].trgb);
		if (fdf->m_cpy)
			printf("point_copy %d : x = %f, y = %f, z = %f\n", i,
				fdf->m_cpy[i].x, fdf->m_cpy[i].y, fdf->m_cpy[i].z);
		i++;
	}
}

t_point	*point(int x, int y, int z)
{
	t_point	*t_p;

	t_p = malloc(sizeof(t_point));
	if (!t_p)
		return (NULL);
	t_p->x = x;
	t_p->y = y;
	t_p->z = z;
	return (t_p);
}
