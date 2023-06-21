/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:52:26 by qbanet            #+#    #+#             */
/*   Updated: 2023/06/21 11:38:27 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_form(char *s)
{
	s = ft_strrchr(s, '.');
	if (ft_strlen(s) != 4)
		return (-1);
	if (ft_strncmp(s, ".fdf", 4) == 0)
		return (0);
	return (-1);
}

void	ft_print_tab(int **tab, int nb_line, int nb_colon)
{
	int		i;
	int		j;

	i = 0;
	while (i < nb_line)
	{
		j = 0;
		while (j < nb_colon)
		{
			ft_printf("%d|", tab[i][j]);
			j ++;
		}
		ft_printf("\n");
		i ++;
	}
}

void	ft_print_color(char ***tab, int nb_line, int nb_colon)
{
	int		i;
	int		j;

	i = 0;
	while (i < nb_line)
	{
		j = 0;
		while (j < nb_colon)
		{
			ft_printf("%s|", tab[i][j]);
			j ++;
		}
		ft_printf("\n");
		i ++;
	}
}

char	*ft_color(char *node)
{
	char	*str;

	str = ft_strchr(node, ',') + 1;
	return (ft_strdup(str));
}
