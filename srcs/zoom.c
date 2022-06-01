/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 10:48:09 by rmorel            #+#    #+#             */
/*   Updated: 2022/05/05 14:44:42 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_in(t_fdf *fdf)
{
	int	i;

	i = 1;
	if (fdf->map[i].x > 2000)
		return ;
	while (i <= fdf->map[0].x * fdf->map[0].y)
	{
		fdf->map[i].x = fdf->map[i].x * 1.1;
		fdf->map[i].y = fdf->map[i].y * 1.1;
		i++;
	}
}

void	zoom_out(t_fdf *fdf)
{
	int	i;

	i = 1;
	while (i <= fdf->map[0].x * fdf->map[0].y)
	{
		fdf->map[i].x = fdf->map[i].x * 0.9;
		fdf->map[i].y = fdf->map[i].y * 0.9;
		i++;
	}
}
