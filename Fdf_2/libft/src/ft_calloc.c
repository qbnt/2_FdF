/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 10:46:19 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/08 21:52:48 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	tmp;

	tmp = nmemb * size;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (tmp / size != nmemb || tmp / nmemb != size)
		return (NULL);
	ptr = malloc(tmp);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (tmp));
	return (ptr);
}
