/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:15:46 by dasimoes          #+#    #+#             */
/*   Updated: 2025/09/03 23:26:49 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Endianness:
* the least significant byte is stored first in memory for little endian;
* the most significant byte is stored first in memory for big endian;
* 
* This means that once I save an int as ARGB and if I try to change a specific byte of such an int, I need to understand that it could be litt* little endian, meaning the computer will store B then G then R and finally A
* ARGB -> BGRA (in memory)
*/

#include "fractol.h"
#include <unistd.h>

int	render_fractol(void)
{
	t_mlx	*mlx;
	t_gc	*gc;
	t_argb	color;
	int		x;

	x = -1;
	gc = gc_init();
	if (!gc)
		return (func_error(gc));
	mlx = set_mlx(gc);
	if (!mlx)
		return (func_error(gc));
	mlx->init = mlx_init(); //void check
	mlx->win = mlx_new_window(mlx->init, WIDTH, HEIGHT, "mandelbrot");
	mlx->img = mlx_new_image(mlx->init, WIDTH, HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line, &mlx->end);
	printf("endian: %d\n", mlx->end);
	color.value = 0x00FF0000; // red
	while (++x < 1081)
	{
		printf("color value: %X\n", color.value);
		printf("color a: %X\n", color.part.a);
		printf("color r: %X\n", color.part.r);
		printf("color g: %X\n", color.part.g);
		printf("color b: %X\n", color.part.b);
		pixel_put(mlx, x, 10, color.value);
		color.part.g++;
	}
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, 0, 0);
	hook_fractol(mlx);
	mlx_loop(mlx->init);
	return (0);
}
