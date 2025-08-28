#ifndef FRACT_OL_H
#define FRACT_OL_H

// External includes
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

// Local includes
#include "mlx.h"
#include "libft.h"

// Structs
typedef struct	s_complex
{
	double r;
	double i;
}	t_complex;	

typedef struct	s_ctx
{
	void	*mlx;
	void	*window;
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
} t_ctx;

// Prototypes
t_ctx	*ctx_init(t_gc *gc);
int		print_error(t_gc *gc);
void	pixel_put(t_ctx *ctx, int x, int y, int color);

#endif
