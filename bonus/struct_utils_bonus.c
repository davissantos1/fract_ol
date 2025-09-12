/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:45:31 by dasimoes          #+#    #+#             */
/*   Updated: 2025/09/11 20:04:33 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

t_mlx	*set_mlx(t_gc *gc, t_fractol *f)
{
	t_mlx	*mlx;
	void	*ptr;

	ptr = mlx_init();
	gc_addptr(ptr, gc, GC_DEFAULT);
	mlx = gc_malloc(sizeof(t_mlx), gc, GC_DEFAULT);
	if (!mlx)
		return (NULL);
	mlx->init = ptr;
	if (!mlx->init)
		return (NULL);
	mlx->win = mlx_new_window(mlx->init, WIDTH, HEIGHT, f->name);
	if (!mlx->win)
		return (NULL);
	mlx->img = mlx_new_image(mlx->init, WIDTH, HEIGHT);
	if (!mlx->img)
		return (NULL);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line, &mlx->end);
	mlx->garbage = gc;
	mlx->fractol = f;
	return (mlx);
}

t_fractol	*set_fractol(t_gc *gc, char **av)
{
	t_fractol	*fractol;

	fractol = gc_malloc(sizeof(t_fractol), gc, GC_DEFAULT);
	if (!fractol)
		return (NULL);
	build_palette(fractol->colors, 256);
	fractol->name = av[0];
	fractol->min_x = -2.0;
	fractol->max_x = 1.0;
	fractol->min_y = -1.5;
	fractol->max_y = 1.5;
	fractol->center_x = (fractol->min_x + fractol->max_x) / 2;
	fractol->center_y = (fractol->min_y + fractol->max_y) / 2;
	fractol->iteration = 150;
	fractol->offset = 0;
	if (!ft_strncmp(fractol->name, "julia", 5))
	{
		fractol->julia_x = ft_atof(av[1]);
		fractol->julia_y = ft_atof(av[2]);
	}
	return (fractol);
}

void	build_palette(int *palette, int size)
{
	t_argb	color;
	int		i;

	i = 0;
	while (i < size)
	{
		color.part.a = 255;
		color.part.r = (unsigned char)(127 + 127 * sinf(i * 0.1));
		color.part.g = (unsigned char)(127 + 127 * sinf(i * 0.1 + 2));
		color.part.b = (unsigned char)(127 + 127 * sinf(i * 0.1 + 4));
		palette[i] = color.value;
		i++;
	}
}
