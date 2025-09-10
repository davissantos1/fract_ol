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
#define HEIGHT 1080

// Structs
typedef struct	s_fractol
{
	char 		*name;
	int			colors[256];
	int			iteration;
	int			offset;
	float		julia_x;
	float		julia_y;
	float		min_x;
	float		max_x;
	float		min_y;
	float		max_y;
	float		center_x;
	float		center_y;
} t_fractol;

typedef struct	s_mlx
{
	void		*init;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line;
	int			end;
	t_gc		*garbage;
	t_fractol	*fractol;
} t_mlx;

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
int			is_valid(char *str);
int			close_cross(t_mlx *mlx);
int			pan_window(int keycode, t_mlx *mlx);
void		build_palette(int *palette, int size);
t_fractol 	*set_fractol(t_gc *gc, char **av);
int			start_fractol(char **av);
void		render_fractol(t_mlx *mlx, t_fractol *f);
int			compute_fractol(int x, int y, t_fractol *f);
int			iterate_julia(float cx, float cy, t_fractol *f);
int			iterate_mandelbrot(float cx, float cy, t_fractol *f);
int			iterate_ship(float cx, float cy, t_fractol *f);
void		horizontal_pan(int keycode, t_mlx *mlx);
void		vertical_pan(int keycode, t_mlx *mlx);
int			hook_mouse(int button, int x, int y, t_mlx *mlx);
int			point_zoom(t_fractol *f, int mx, int my, float factor);
float		ft_atof(char *s);
float		ft_abs(float num);

#endif
