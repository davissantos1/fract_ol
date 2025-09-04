#ifndef FRACTOL_H
#define FRACTOL_H

// External includes
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

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

struct s_argb
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
	unsigned char a;
};
	
typedef struct	s_mlx
{
	void	*init;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line;
	int		end;
} t_mlx;

typedef struct	s_fractol
{
	char *name;
	int	x;
	int	y;
} t_fractol;

// Unions
typedef union u_argb
{
	int	value;
	struct s_argb part;
}	t_argb;

// Prototypes
t_mlx		*set_mlx(t_gc *gc);
int			arg_error(int type);
int			func_error(t_gc *gc);
void		pixel_put(t_mlx *mlx, int x, int y, int color);
void		hook_fractol(t_mlx *mlx);
int			render_fractol(void);
int			is_valid(char *str);
int 		close_esc(int keycode, t_mlx *mlx);
int			close_cross(t_mlx *mlx);

#endif
