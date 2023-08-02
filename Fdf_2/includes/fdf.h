/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:24:10 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/02 13:48:16 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "libft.h"
# include "mlx.h"
# include "fdf_define.h"
# include "fdf_struct.h"

/*map_crea.c*/
void	create_map(t_map *map, char *s);

/*utile.c*/
void	ft_print_tab_2d(int **tab);
int		color(int cas, char *c_color);

#endif