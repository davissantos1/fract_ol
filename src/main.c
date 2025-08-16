#include "fract_ol.h"

int	main(void)
{
	void	*mlx;
	void	*window;
	int		x;
	int		y;
	char	*title;

	x = 100;
	y = 100;
	title = "oi";
	mlx = mlx_init();
	if (!mlx)
		return (1);
	window = mlx_new_window(mlx, x, y, title);
	if (!window)
		return (1);
	return (0);
}	
