/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:22:30 by rmorel            #+#    #+#             */
/*   Updated: 2022/05/09 16:56:59 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_image(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx, fdf->data->img);
	ft_bzero(fdf->data, sizeof(t_data));
	fdf->data->img = mlx_new_image(fdf->mlx, W_W, W_H);
	fdf->data->addr = mlx_get_data_addr(fdf->data->img, &fdf->data->bpp,
			&fdf->data->line_lgth, &fdf->data->endian);
	draw_map(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->data->img,
		fdf->data->x, fdf->data->y);
}

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;
	int		x2;
	int		y2;

	x2 = x + W_W / 2;
	y2 = y + W_H / 2;
	if (x2 > W_W || y2 > W_H || x2 <= 0 || y2 <= 0)
		return ;
	dst = fdf->data->addr + (y2 * fdf->data->line_lgth
			+ x2 * (fdf->data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	render_next_frame(t_fdf *fdf)
{
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->data->img, fdf->data->x,
		fdf->data->y);
	return (0);
}
