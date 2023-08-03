/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:24:10 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/03 13:31:21 by qbanet           ###   ########.fr       */
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
int		color(int cas, char *c_color);
void	ft_print_tab(int **tab, int nb_line, int nb_colon);

/*init.c*/
void	ft_window(t_fdf *fdf);

/*key.c*/
int		key_hook(int keycode, t_fdf *fdf);
int		ft_expose_hook(t_fdf *fdf);

/*key_move.c*/
void	ft_key_move(t_fdf *fdf, int keycode);

/*draw.c*/
void	ft_draw(t_fdf *fdf);

#endif