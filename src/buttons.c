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

void	zoom(t_fractol *f, float factor)
{
	float	width;
	float	height;

	width = (f->max_x - f->min_x) * factor;
	height = (f->max_y - f->min_y) * factor;
	if (factor < 1)
	{
		f->min_x = f->center_x - width / 2;
		f->max_x = f->center_x + width / 2;
		f->min_y = f->center_y - height / 2;
		f->max_y = f->center_y + height / 2;
	}
	else
	{
		f->min_x = f->center_x - width / 2;
		f->max_x = f->center_x + width / 2;
		f->min_y = f->center_y - height / 2;
		f->max_y = f->center_y + height / 2;
	}
}

int	hook_mouse(int mx, int my, t_mlx *mlx)
{
	float		factor;
	float		width;
	float		height;
	t_fractol	*f;

	factor = 0.95;
	f = mlx->fractol;
	width = (f->max_x - f->min_x) * factor;
	height = (f->max_y - f->min_y) * factor;
	f->min_x = mx - width / 2;
	f->max_x = mx + width / 2;
	f->min_y = my - height / 2;
	f->max_y = my + height / 2;
	f->center_x = mx;
	f->center_y = my;
	return (0);
}

int	hook_wheel(int button, t_mlx *mlx)
{
	if (button == 4)
	{
		zoom(mlx->fractol, 0.95);
		render_fractol(mlx, mlx->fractol);
	}
	if (button == 5)
	{
		zoom(mlx->fractol, 1.05);
		render_fractol(mlx, mlx->fractol);
	}
	return (0);
}
