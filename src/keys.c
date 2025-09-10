/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 18:20:19 by dasimoes          #+#    #+#             */
/*   Updated: 2025/09/10 18:21:18 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	vertical_pan(int keycode, t_mlx *mlx)
{
	float		step_y;
	t_fractol	*f;

	f = mlx->fractol;
	step_y = (f->max_y - f->min_y) * 0.05;
	if (keycode == 0xff52)
	{
		f->min_y -= step_y;
		f->max_y -= step_y;
		f->center_y = (f->max_y - f->min_y) / 2;
	}
	if (keycode == 0xff54)
	{
		f->min_y += step_y;
		f->max_y += step_y;
		f->center_y = (f->max_y - f->min_y) / 2;
	}
	render_fractol(mlx, mlx->fractol);
}

void	horizontal_pan(int keycode, t_mlx *mlx)
{
	float		step_x;
	t_fractol	*f;

	f = mlx->fractol;
	step_x = (f->max_x - f->min_x) * 0.05;
	if (keycode == 0xff51)
	{
		f->min_x -= step_x;
		f->max_x -= step_x;
		f->center_x = (f->max_x - f->min_x) / 2;
	}
	if (keycode == 0xff53)
	{
		f->min_x += step_x;
		f->max_x += step_x;
		f->center_x = (f->max_x - f->min_x) / 2;
	}
	render_fractol(mlx, mlx->fractol);
}

int	hook_keys(int keycode, t_mlx *mlx)
{
	if (keycode == 0xff1b)
	{
		mlx_destroy_window(mlx->init, mlx->win);
		gc_free_all(mlx->garbage);
		exit(1);
	}
	else if (keycode == 0x20)
	{
		mlx->fractol->offset++;
		mlx->fractol->offset = mlx->fractol->offset % mlx->fractol->iteration;
		render_fractol(mlx, mlx->fractol);
	}
	else if ((keycode == 0xff52) || (keycode == 0xff54))
		vertical_pan(keycode, mlx);
	else if ((keycode == 0xff51) || (keycode == 0xff53))
		horizontal_pan(keycode, mlx);
	return (0);
}
