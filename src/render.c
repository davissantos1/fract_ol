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

int	compute_fractol(int x, int y, t_fractol *f)
{
	float	cx;
	float	cy;

	cx =  f->min_x + x * (f->max_x - f->min_x) / WIDTH;
	cy =  f->min_y + y * (f->max_y - f->min_y) / HEIGHT;
			
	if (!ft_strncmp(f->name, "julia", 5))
		return (iterate_julia(cx, cy, f));
	else if (!ft_strncmp(f->name, "mandelbrot", 10))
		return (iterate_mandelbrot(cx, cy, f));
	else if (!ft_strncmp(f->name, "ship", 4))
		return (iterate_ship(cx, cy, f));
	else
		return (-1);
}

void	render_fractol(t_mlx *mlx, t_fractol *f)
{
	int iteration;
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			iteration = compute_fractol(x, y, f);
			if (iteration == f->iteration)
				pixel_put(mlx, x, y, 0x000000);
			else
				pixel_put(mlx, x, y, f->colors[iteration]);
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
	mlx_hook(mlx->win, 2, 1L<<0, hook_keys, mlx);
	mlx_hook(mlx->win, 4, 1L<<2, hook_wheel, mlx);
	mlx_hook(mlx->win, 6, 1L<<6, hook_mouse, mlx);
	mlx_hook(mlx->win, 17, 1L<<17, close_cross, mlx);
	mlx_loop(mlx->init);
	gc_free_all(gc);
	return (0);
}
