/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:43:58 by qbanet            #+#    #+#             */
/*   Updated: 2023/05/23 16:48:03 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_error(int error)
{
	if (error == ERROR_ARG)
		ft_printf("Invalid number of arguments.\nUsage : ./fdf <filename>\n");
	if (error == ERROR_OPEN)
		ft_printf("Error during opening.\n");
	if (error == ERROR_CLOSE)
		ft_printf("Error during closing.\n");
	if (error == ERROR_MAP)
		ft_printf("Error during computing map.\n");
	exit(EXIT_FAILURE);
}
