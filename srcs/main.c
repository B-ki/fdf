/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:39:06 by rmorel            #+#    #+#             */
/*   Updated: 2022/05/09 16:56:32 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf	*fdf;

	if (ac != 2)
		return (0);
	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		return (0);
	ft_bzero(fdf, sizeof(t_fdf));
	init_window(fdf);
	fdf->map = create_map(av, fdf);
	init_map(fdf->map);
	fill_color(fdf);
	create_copy(fdf);
	rotation_y(fdf, -0.45);
	rotation_x(fdf, -0.35);
	clear_image(fdf);
	mlx_hook(fdf->win, 2, 1L << 0, key_hook, fdf);
	mlx_hook(fdf->win, 17, 1L << 17, red_cross, fdf);
	mlx_loop(fdf->mlx);
	exit_clean(fdf);
	return (0);
}

void	init_window(t_fdf *fdf)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
	{
		exit_clean(fdf);
	}
	fdf->data = data;
	ft_bzero(fdf->data, sizeof(t_data));
	fdf->trgb = create_trgb(0, 255, 255, 255);
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, W_W, W_H, "Hello world!");
	fdf->data->img = mlx_new_image(fdf->mlx, W_W, W_H);
	fdf->data->addr = mlx_get_data_addr(fdf->data->img, &fdf->data->bpp,
			&fdf->data->line_lgth, &fdf->data->endian);
}

void	exit_clean(t_fdf *fdf)
{
	if (fdf && fdf->mlx)
	{
		mlx_destroy_image(fdf->mlx, fdf->data->img);
		mlx_destroy_window(fdf->mlx, fdf->win);
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
	}
	if (fdf && fdf->data)
		free(fdf->data);
	if (fdf && fdf->map)
		free(fdf->map);
	if (fdf && fdf->m_cpy)
		free(fdf->m_cpy);
	if (fdf)
		free(fdf);
	exit(EXIT_SUCCESS);
	return ;
}
