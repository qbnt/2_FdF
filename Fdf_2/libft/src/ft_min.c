/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:21:04 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/09 12:21:41 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_min(long long *tab, unsigned int len)
{
	unsigned int	i;
	long long		min;

	if (len == 0)
		return (0);
	i = 1;
	min = *tab;
	while (i != len)
	{
		if (min > *(tab + i))
			min = *(tab + i);
		i++;
	}
	return (min);
}
