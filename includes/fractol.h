#ifndef FRACTOL_H
#define FRACTOL_H

// External includes
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <math.h>

// Local includes
#include "mlx.h"
#include "libft.h"

// Macros
#define WIDTH 1080
#define HEIGHT 800

// Structs
typedef struct	s_complex
{
	float	real;
	float	i;
}	t_complex;	

typedef struct	s_mlx
{
	void		*init;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line;
	int			end;
} t_mlx;

typedef struct	s_fractol
{
	char 	*name;
	int		colors[256];
	float	min_x;
	float	max_x;
	float	min_y;
	float	max_y;
	float	center_x;
	float	center_y;
	int		iteration;
} t_fractol;

struct s_argb
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char a;
};

// Unions
typedef union u_argb
{
	int	value;
	struct s_argb part;
}	t_argb;

// Prototypes
t_mlx		*set_mlx(t_gc *gc, t_fractol *fractol);
int			arg_error(int type);
int			func_error(t_gc *gc);
void		pixel_put(t_mlx *mlx, int x, int y, int color);
void		hook_fractol(t_mlx *mlx);
int			hook_keys(int keycode, t_mlx *mlx);
int			render_fractol(char **av);
int			is_valid(char *str);
int			close_cross(t_mlx *mlx);
int			pan_window(int keycode, t_mlx *mlx);
void		build_palette(int *palette, int size);
t_fractol 	*set_fractol(t_gc *gc, char **av);

#endif
