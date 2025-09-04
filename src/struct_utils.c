/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:45:31 by dasimoes          #+#    #+#             */
/*   Updated: 2025/09/03 22:45:06 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx	*set_mlx(t_gc *gc)
{
	t_mlx	*mlx;
	mlx = gc_malloc(sizeof(t_mlx), gc, GC_DEFAULT);
	if (!mlx)
		return (NULL);
	mlx->init = NULL;
	mlx->win = NULL;
	mlx->img= NULL;
	mlx->addr = NULL;
	mlx->bpp = 0;
	mlx->line = 0;
	mlx->end = 0;
	return (mlx);
}

