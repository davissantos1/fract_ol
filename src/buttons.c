/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:00:22 by dasimoes          #+#    #+#             */
/*   Updated: 2025/09/07 14:24:01 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_cross(t_mlx *mlx)
{
	mlx_destroy_window(mlx->init, mlx->win);
	gc_free_all(mlx->garbage);
	exit(1);
	return (1);
}

int	point_zoom(t_fractol *f, int mx, int my, float factor)
{
	float		fractal_x;
	float		fractal_y;
	float		width;
	float		height;

	fractal_x = f->min_x + (mx / (float)WIDTH) * (f->max_x - f->min_x);
	fractal_y = f->min_y + (my / (float)HEIGHT) * (f->max_y - f->min_y);
	width = (f->max_x - f->min_x) * factor;
	height = (f->max_y - f->min_y) * factor;
	f->min_x = fractal_x - width / 2;
	f->max_x = fractal_x + width / 2;
	f->min_y = fractal_y - height / 2;
	f->max_y = fractal_y + height / 2;
	f->center_x = mx;
	f->center_y = my;
	return (0);
}

int	hook_mouse(int button, int x, int y, t_mlx *mlx)
{
	if (!mlx || !mlx->fractol)
		return (0);
	if (button == 4)
	{
		point_zoom(mlx->fractol, x, y, 0.95);
		render_fractol(mlx, mlx->fractol);
	}
	else if (button == 5)
	{
		point_zoom(mlx->fractol, x, y, 1.05);
		render_fractol(mlx, mlx->fractol);
	}
	return (0);
}
