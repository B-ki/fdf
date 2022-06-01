/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:22:16 by rmorel            #+#    #+#             */
/*   Updated: 2022/05/09 14:15:07 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	get_max_z(t_fdf *fdf)
{
	int	i;
	int	max;

	i = 1;
	max = fdf->map[1].z;
	while (i <= fdf->map[0].x * fdf->map[0].y)
	{
		if (fdf->map[i].z > max)
			max = fdf->map[i].z;
		i++;
	}
	if (max == 0)
		return (-1);
	return (max);
}

float	get_min_z(t_fdf *fdf)
{
	int	i;
	int	min;

	i = 1;
	min = fdf->map[1].z;
	while (i <= fdf->map[0].x * fdf->map[0].y)
	{
		if (fdf->map[i].z < min)
			min = fdf->map[i].z;
		i++;
	}
	if (min == 0)
		return (-1);
	return (min);
}
