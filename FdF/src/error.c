/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:43:58 by qbanet            #+#    #+#             */
/*   Updated: 2023/05/10 09:37:38 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_error(int error)
{
	if (error == ERROR_ARG)
		ft_printf("Invalid number of arguments.\nUsage : ./fdf <filename>\n");
	if (error == ERROR_ARG)
		ft_printf("Error during opening,\n");
	exit(EXIT_FAILURE);
}
