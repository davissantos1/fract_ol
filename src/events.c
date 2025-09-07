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
	exit(0);
	return (0);
}

int	hook_keys(int keycode, t_mlx *mlx)
{
	if (keycode == 0xff1b)
	{
		mlx_destroy_window(mlx->init, mlx->win);
		exit(0);
	}
	if (keycode == 0xff52)
		mlx->y *= 1.05;
	if (keycode == 0xff54)
		mlx->y *= 0.95;
	if (keycode == 0xff51)
		mlx->x *= 1.05;
	if (keycode == 0xff53)
		mlx->x *= 0.95;
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, mlx->x, mlx->y); 
	return (0);
}

void	hook_fractol(t_mlx *mlx)
{
	mlx_hook(mlx->win, 2, 1L<<0, hook_keys, mlx);
	mlx_hook(mlx->win, 17, 1L<<17, close_cross, mlx);
}
