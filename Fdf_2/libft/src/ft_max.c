/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:32:23 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/09 12:18:21 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max(long long *tab, unsigned int len)
{
	unsigned int	i;
	long long		max;

	if (len == 0)
		return (0);
	i = 1;
	max = *tab;
	while (i != len)
	{
		if (max < *(tab + i))
			max = *(tab + i);
		i++;
	}
	return (max);
}
