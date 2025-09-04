/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:00:22 by dasimoes          #+#    #+#             */
/*   Updated: 2025/09/03 18:26:19 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int close_esc(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(mlx->init, mlx->win);
		exit(0);
		return (0);
	}
	return (0);
}

int	close_cross(t_mlx *mlx)
{
	mlx_destroy_window(mlx->init, mlx->win);
	exit(0);
	return (0);
}

void	hook_fractol(t_mlx *mlx)
{
	mlx_hook(mlx->win, 2, 1L<<0, close_esc, mlx);
	mlx_hook(mlx->win, 17, 1L<<17, close_cross, mlx);
}
