/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 07:53:08 by qbanet            #+#    #+#             */
/*   Updated: 2023/06/23 07:57:41 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_free_tab(void *tab, int nb_line)
{
	int	i;

	while(i < nb_line)
	{
		free(tab[i]);
		i++;
	}
	nb_line--;
	if (nb_line > 0)
		free(tab);
	return (0)
}