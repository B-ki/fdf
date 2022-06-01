/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:16:00 by rmorel            #+#    #+#             */
/*   Updated: 2022/05/09 10:08:39 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	enter_window(int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	(void)fdf;
	ft_printf("Hello !\n");
	return (1);
}

int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == 65307)
	{
		ft_printf("Au revoir !\n");
		mlx_loop_end(fdf->mlx);
	}
	if (keycode == 'w')
		translate_map_y(fdf->map, 10);
	else if (keycode == 's')
		translate_map_y(fdf->map, -10);
	else if (keycode == 'a')
		translate_map_x(fdf->map, -10);
	else if (keycode == 'd')
		translate_map_x(fdf->map, 10);
	else if (keycode >= 65361 && keycode <= 65453)
		key_down_moves(keycode, fdf);
	else if (keycode == 'p')
		copy_map(fdf->m_cpy, fdf->map);
	else if (keycode == 'i')
	{
		copy_map(fdf->m_cpy, fdf->map);
		rotation_y(fdf, -0.45);
		rotation_x(fdf, -0.35);
	}
	clear_image(fdf);
	return (1);
}

int	key_down_moves(int keycode, t_fdf *fdf)
{
	if (keycode == 65362)
		rotation_x(fdf, 0.05);
	else if (keycode == 65364)
		rotation_x(fdf, -0.05);
	else if (keycode == 65361)
		rotation_y(fdf, 0.05);
	else if (keycode == 65363)
		rotation_y(fdf, -0.05);
	else if (keycode == 65451)
		zoom_in(fdf);
	else if (keycode == 65453)
		zoom_out(fdf);
	return (1);
}

int	red_cross(t_fdf *fdf)
{
	ft_printf("Au revoir !\n");
	mlx_loop_end(fdf->mlx);
	return (1);
}
