/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:11:52 by dasimoes          #+#    #+#             */
/*   Updated: 2025/08/31 16:45:10 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	print_error(t_gc *gc)
{
	gc_free_all(gc);
	perror("Error: ");
	return (1);
}
	
t_ctx	*ctx_init(t_gc *gc)
{
	t_ctx	*ctx;
	ctx = gc_malloc(sizeof(t_ctx), gc, GC_DEFAULT);
	if (!ctx)
		return (NULL);
	ctx->mlx = NULL;
	ctx->window = NULL;
	ctx->img= NULL;
	ctx->addr = NULL;
	ctx->bpp = 0;
	ctx->ll = 0;
	ctx->endian = 0;
	return (ctx);
}

void	pixel_put(t_ctx *ctx, int x, int y, int color)
{
	char	*dst;

	dst = ctx->addr + (y * ctx->ll + x * (ctx->bpp / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	t_gc	*gc;
	t_ctx	*ctx;

	gc = gc_init();
	if (!gc)
		return (print_error(gc));
	ctx = ctx_init(gc);
	if (!ctx)
		return (print_error(gc));
	ctx->mlx = mlx_init();
	ctx->window = mlx_new_window(ctx->mlx, 1920, 1080, "I fucking work");
	ctx->img = mlx_new_image(ctx->mlx, 1920, 1080);
	ctx->addr = mlx_get_data_addr(ctx->img, &ctx->bpp, &ctx->ll, &ctx->endian);
	mlx_put_image_to_window(ctx->mlx, ctx->window, ctx->img, 0, 0);
	mlx_loop(ctx->mlx);
	return (0);
}	
