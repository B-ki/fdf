/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 23:35:40 by rmorel            #+#    #+#             */
/*   Updated: 2022/05/06 14:28:09 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotation_x(t_fdf *fdf, float angle)
{
	int	i;

	i = 1;
	while (i <= fdf->map[0].x * fdf->map[0].y)
	{
		fdf->map[i].y = fdf->map[i].y * cos(angle) - fdf->map[i].z * sin(angle);
		fdf->map[i].z = fdf->map[i].y * sin(angle) + fdf->map[i].z * cos(angle);
		i++;
	}
}

void	rotation_y(t_fdf *fdf, float angle)
{
	int	i;

	i = 1;
	while (i <= fdf->map[0].x * fdf->map[0].y)
	{
		fdf->map[i].x = fdf->map[i].x * cos(angle) + fdf->map[i].z * sin(angle);
		fdf->map[i].z = -fdf->map[i].x * sin(angle)
			+ fdf->map[i].z * cos(angle);
		i++;
	}
}

void	rotation_z(t_fdf *fdf, float angle)
{
	int	i;

	i = 1;
	while (i <= fdf->map[0].x * fdf->map[0].y)
	{
		fdf->map[i].x = fdf->map[i].x * cos(angle) - fdf->map[i].y * sin(angle);
		fdf->map[i].y = fdf->map[i].x * sin(angle) + fdf->map[i].y * cos(angle);
		i++;
	}
}
