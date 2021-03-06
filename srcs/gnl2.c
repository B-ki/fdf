/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorel <rmorel@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:30:48 by rmorel            #+#    #+#             */
/*   Updated: 2022/05/03 13:00:15 by rmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*search_nl(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == 10)
			return (&s[i]);
		i++;
	}
	return (NULL);
}
