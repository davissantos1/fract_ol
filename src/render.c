/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:15:46 by dasimoes          #+#    #+#             */
/*   Updated: 2025/09/10 19:05:18 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	compute_fractol(int x, int y, t_fractol *f)
{
	int		iterations;
	float	cx;
	float	cy;

	cx = f->min_x + x * (f->max_x - f->min_x) / WIDTH;
	cy = f->min_y + y * (f->max_y - f->min_y) / HEIGHT;
	if (!ft_strncmp(f->name, "julia", 5))
		iterations = iterate_julia(cx, cy, f);
	else if (!ft_strncmp(f->name, "mandelbrot", 10))
		iterations = iterate_mandelbrot(cx, cy, f);
	else if (!ft_strncmp(f->name, "ship", 4))
		iterations = iterate_ship(cx, cy, f);
	else
		return (-1);
	if (iterations == f->iteration)
		return (-1);
	return ((iterations + f->offset) % f->iteration);
}

void	render_fractol(t_mlx *mlx, t_fractol *f)
{
	int	color;
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			color = compute_fractol(x, y, f);
			if (color == -1)
				pixel_put(mlx, x, y, 0x000000);
			else
				pixel_put(mlx, x, y, f->colors[color]);
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
	mlx_key_hook(mlx->win, hook_keys, mlx);
	mlx_mouse_hook(mlx->win, hook_mouse, mlx);
	mlx_hook(mlx->win, 17, 1L << 17, close_cross, mlx);
	mlx_loop(mlx->init);
	gc_free_all(gc);
	return (0);
}
