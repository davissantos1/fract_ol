/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:00:22 by dasimoes          #+#    #+#             */
/*   Updated: 2025/09/10 20:24:39 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_cross(t_mlx *mlx)
{
	mlx_destroy_image(mlx->init, mlx->img);
	mlx_destroy_window(mlx->init, mlx->win);
	mlx_destroy_display(mlx->init);
	gc_free_all(mlx->garbage);
	exit(1);
	return (1);
}

int	point_zoom(t_fractol *f, int mx, int my, float factor)
{
	float		fractal_x;
	float		fractal_y;

	fractal_x = f->min_x + (mx / (float)WIDTH) * (f->max_x - f->min_x);
	fractal_y = f->min_y + (my / (float)HEIGHT) * (f->max_y - f->min_y);

	f->min_x = fractal_x - (fractal_x - f->min_x) * factor;
	f->max_x = fractal_x + (f->max_x - fractal_x) * factor;
	f->min_y = fractal_y - (fractal_y - f->min_y) * factor;
	f->max_y = fractal_y + (f->max_y - fractal_y) * factor;
	f->center_x = (f->max_x - f->min_x) / 2;
	f->center_y = (f->max_y - f->min_y) / 2;
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
