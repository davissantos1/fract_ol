/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:15:46 by dasimoes          #+#    #+#             */
/*   Updated: 2025/09/07 18:54:42 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	compute_fractol(int x, int y, t_fractol *f)
{
	float	cx;
	float	cy;

	cx =  f->min_x + (f->max_x - f->min_x) * (
	// (WIDTH - x) / (HEIGHT - y) = (f->max_x - f->min_x) / (f->max_y - f->min_x) = k ---- proportion
	// cx = x + k * WIDTH

}

void	render_fractol(t_mlx *mlx, t_fractol *f)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			compute_fractol(x, y, f);
			pixel_put(mlx, x, y, f->colors[x]);
		}
	}	
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, 0, 0);
}

int	start_fractol(char **av)
{
	t_mlx		*mlx;
	t_gc		*gc;
	t_fractol	*f;

	gc = gc_init();
	if (!gc)
		return (func_error(gc));
	f = set_fractol(gc, av);
	if (!f)
		return (func_error(gc));
	mlx = set_mlx(gc, f);
	if (!mlx)
		return (func_error(gc));
	render_fractol(mlx, f);
	hook_fractol(mlx);
	mlx_loop(mlx->init);
	return (0);
}
