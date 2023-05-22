/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 09:56:01 by qbanet            #+#    #+#             */
/*   Updated: 2023/04/25 12:22:28 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int key_hook(int keycode, t_env *e)
{
    ft_printf("Touche appuyée: %d\n", keycode);
    if (keycode == ESC)
    {
        ft_close_window(e);
        exit(0);
    }
    return (0);
}