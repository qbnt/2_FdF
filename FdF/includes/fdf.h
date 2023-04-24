/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:47:14 by qbanet            #+#    #+#             */
/*   Updated: 2023/04/24 18:15:32 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	int		width;
	int		height;
}	t_env;

void	ft_init_t_env(t_env *e);
void	ft_init_window(t_env *e);
void	ft_close_window(t_env *e);
int		ft_close_hook(int keycode, void *context);
int		key_hook(int keycode, t_env *e);

#endif
