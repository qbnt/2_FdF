/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:47:14 by qbanet            #+#    #+#             */
/*   Updated: 2023/04/24 17:44:20 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_ins
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		win_wi;
	int		win_he;
}	t_ins;

void	ft_init_window(t_ins *soft);
void	ft_close_window(t_ins *soft);
int		ft_close_hook(int keycode, void *context);

#endif
