/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:52:38 by dasimoes          #+#    #+#             */
/*   Updated: 2025/09/11 18:56:51 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iterate_julia(float cx, float cy, t_fractol *f)
{
	float	tmp_x;
	float	tmp_y;
	float	zx;
	float	zy;
	int		i;

	i = 0;
	tmp_x = cx;
	tmp_y = cy;
	while (i < f->iteration && ((tmp_x * tmp_x + tmp_y * tmp_y) <= 4))
	{
		zx = tmp_x * tmp_x - tmp_y * tmp_y + f->julia_x;
		zy = 2 * tmp_x * tmp_y + f->julia_y;
		tmp_x = zx;
		tmp_y = zy;
		i++;
	}
	return (i);
}

int	iterate_mandelbrot(float cx, float cy, t_fractol *f)
{
	float	tmp_x;
	float	tmp_y;
	float	zx;
	float	zy;
	int		i;

	i = 0;
	tmp_x = 0;
	tmp_y = 0;
	zx = 0;
	zy = 0;
	while (i < f->iteration && ((zx * zx + zy * zy) <= 4))
	{
		zx = tmp_x * tmp_x - tmp_y * tmp_y + cx;
		zy = 2 * tmp_x * tmp_y + cy;
		tmp_x = zx;
		tmp_y = zy;
		i++;
	}
	return (i);
}

int	iterate_ship(float cx, float cy, t_fractol *f)
{
	float	tmp_x;
	float	tmp_y;
	float	zx;
	float	zy;
	int		i;

	i = 0;
	tmp_x = 0;
	tmp_y = 0;
	zx = 0;
	zy = 0;
	while (i < f->iteration && ((zx * zx + zy * zy) <= 4))
	{
		zx = tmp_x * tmp_x - tmp_y * tmp_y + cx;
		zy = 2 * ft_abs(tmp_x) * ft_abs(tmp_y) + cy;
		tmp_x = zx;
		tmp_y = zy;
		i++;
	}
	return (i);
}
