/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 07:53:08 by qbanet            #+#    #+#             */
/*   Updated: 2023/06/23 17:24:07 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_free_tab(void ***tab, int nb_line, int nb_colon)
{
	int	i;
	int	j;

	i = 0;
	while(i < nb_line)
	{
		j = 0;
		if (nb_colon)
			while (j < nb_colon)
			{
				free(tab[i][j]);
				tab[i][j] = NULL;
				j++;
			}
			
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	return (0);
}