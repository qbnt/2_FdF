/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:26:22 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/13 16:40:41 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	nb_min(float a, float b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

float	nb_max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	nb_absol(float a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}
