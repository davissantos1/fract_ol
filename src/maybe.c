int	pixel_put(t_ctx *ctx, int x, int y, int color)
{
	char	*dst;

	dst = ctx->addr + (y * ctx->ll + x * (ctx->bpp / 8));
	*(unsigned int*)dst = color;
}

void	square(t_ctx *ctx, int x, int y, int size, int color, int hollow)
{
	int hor;
	int tmp;
	int line;
	int offset;

	tmp = x;
	hor = x + size;
	line = size;
	offset = size;
	while (size >= 0)
	{
		x = tmp;
		if (!hollow)
		{
			while (x < hor)
				pixel_put(ctx, x++, y, color);
		}
		else
		{
			if (line == 0 || line == offset)
			{
				while (x < hor)
					pixel_put(ctx, x++, y, color);
				line--;
			}
			else
			{
				pixel_put(ctx, x, y, color);
				pixel_put(ctx, x + offset, y, color);
				line--;
			}
		}
		y++;
		size--;
	}
}
