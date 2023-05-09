/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:47:14 by qbanet            #+#    #+#             */
/*   Updated: 2023/05/09 15:13:47 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"

# define ERROR_ARG 1

# define WIDTH 1920
# define HEIGHT 1080
# define SQUAR_SIZE 500

# define RED 0xFF0000
# define GREEN 0x00FF00

# define ESC 65307

/*******STRUCT*******/

typedef struct s_3d
{
	t_env	e;
}	t_3d;

typedef struct s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	int		width;
	int		height;
}	t_env;

typedef struct s_squar
{
	int	x;
	int	y;
}	t_squar;

/*init.c*/
void	ft_init_t_env(t_env *e);
void	ft_init_t_squar(t_squar *squar);

/*window.c*/
void	ft_init_window(t_env *e);
void	ft_close_window(t_env *e);

/*key.c*/
int		key_hook(int keycode, t_env *e);

/*error.c*/
int	ft_error(int error);

/*file.c*/


#endif
