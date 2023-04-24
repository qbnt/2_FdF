/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:47:14 by qbanet            #+#    #+#             */
/*   Updated: 2023/04/24 11:28:54 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"

typedef struct s_ins
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_wi;
	int		win_he;
	char	*name;
}	t_ins;

void	ft_init_window(t_ins *soft);

#endif