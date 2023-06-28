/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parallels <parallels@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 18:16:53 by parallels         #+#    #+#             */
/*   Updated: 2023/06/28 20:56:33 by parallels        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"test.h"

void	ft_bresenham(t_env *fdf)
{
	fdf->point.dx = (abs(fdf->point.x2 - fdf->point.x1));
	fdf->point.sx = (fdf->point.x1 < fdf->point.x2 ? 1 : -1);
	fdf->point.dy = (abs(fdf->point.y2 - fdf->point.y1));
	fdf->point.sy = (fdf->point.y1 < fdf->point.y2 ? 1 : -1);
	fdf->point.err = (fdf->point.dx > fdf->point.dy ?
			fdf->point.dx : -fdf->point.dy) / 2;
	while (1)
	{
		ft_pixel_put(fdf, fdf->mov.l_r + fdf->point.x1,
					fdf->mov.d_u + fdf->point.y1);
		if (fdf->point.x1 == fdf->point.x2 && fdf->point.y1 == fdf->point.y2)
			break ;
		fdf->point.e2 = fdf->point.err;
		if (fdf->point.e2 > -fdf->point.dx)
		{
			fdf->point.err -= fdf->point.dy;
			fdf->point.x1 += fdf->point.sx;
		}
		if (fdf->point.e2 < fdf->point.dy)
		{
			fdf->point.err += fdf->point.dx;
			fdf->point.y1 += fdf->point.sy;
		}
	}
}

void my_mlx_put_pixel(t_mlx *test, int x, int y, int color)
{
	char	*dest;

	dest = (test->image.ptr + (y * test->image.size + x * (test->image.bpp / 8)));
	*(unsigned int *)dest = color;
}

void	ft_pixel_put(t_mlx *test, int x, int y)
{
	if (x > 0 && y > 0 && x < test->e.height && y < test->e.width)
	{
		test->image.pixels[(x * (test->image.bpp / 8)) +
			(y * test->image.size)] = test->color.red;
		test->image.pixels[(x * (test->image.bpp / 8)) +
			(y * test->image.size) + 1] = test->color.green;
		test->image.pixels[(x * (test->image.bpp / 8)) +
			(y * test->image.size) + 2] = test->color.blue;
	}
}

int	key_hook(int keycode, t_mlx *test)
{
	printf("Keycode : %d\n", keycode);
	if (keycode == 65307)
	{
		printf("0\n");
		mlx_destroy_image(&test->e.mlx, &test->image.ptr);
		printf("1\n");
		mlx_destroy_window(test->e.mlx, test->e.win);
		printf("2\n");
		mlx_destroy_display(test->e.mlx);
		printf("3\n");
		free(test->e.mlx);
	}
	return (0);
}

int	main(void)
{
	t_mlx	*test;

	test = calloc(1, sizeof(t_mlx));
	test->e.mlx = mlx_init();
	test->e.win = mlx_new_window(test->e.mlx, WIDTH, HEIGHT, "TEST");

	test->image.ptr = mlx_new_image(test->e.mlx, WIDTH, HEIGHT);
	test->image.pixels = mlx_get_data_addr(test->image.ptr, &test->image.bpp,
			&test->image.size, &test->image.endian);

	ft_pixel_put(test, 10, 10);
	mlx_put_image_to_window(test->e.mlx, test->e.win, test->image.ptr, 0, 0);

	mlx_key_hook(test->e.win, key_hook, &test);
	mlx_loop(test->e.mlx);
	return (0);
}
