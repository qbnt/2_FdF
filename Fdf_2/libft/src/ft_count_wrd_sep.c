/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_wrd_sep.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:53:01 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/17 15:41:28 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_wrd_sep(char const *s, char c)
{
	int	count;
	int	sep;

	sep = 0;
	count = 0;
	while (*s)
	{
		if (sep == 1 && *s == c)
		{
			sep = 0;
			count ++;
		}
		if (sep == 0 && *s != c)
		{
			sep = 1;
		}
		s++;
	}
	return (count);
}
