/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:52:26 by qbanet            #+#    #+#             */
/*   Updated: 2023/06/19 14:42:28 by qbanet           ###   ########.fr       */
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

int	*ft_inted_line(char *line, int nm_colon)
{
	char	**splited_line;
	int		*inted_line;
	int		i;
	int		j;

	splited_line = ft_split(line, ' ');
	inted_line = ft_calloc(nm_colon, sizeof(int));
	i = 0;
	while (splited_line[i])
	{
		inted_line[i] = ft_atoi(splited_line[i]);
		i ++;
	}
	j = 0;
	while (splited_line[j])
		free(splited_line[j ++]);
	free(splited_line);
	return (inted_line);
}

void	ft_print_tab(int **tab, int nb_line, int nb_colon)
{
	int		i;
	int		y;

	i = 0;
	while (i < nb_line)
	{
		y = 0;
		while (y < nb_colon)
		{
			ft_printf("%d|", tab[i][y]);
			y ++;
		}
		ft_printf("\n");
		i ++;
	}
}
