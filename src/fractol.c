/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:11:52 by dasimoes          #+#    #+#             */
/*   Updated: 2025/09/03 20:21:08 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	int render;

	if (ac == 2 || ac == 4)
	{
		if (!ft_strncmp(av[1], "mandelbrot", 10) && ac == 2)
			render = render_fractol();
		else if (!ft_strncmp(av[1], "julia", 5) && ac == 4)
		{
			if (is_valid(av[2]) && is_valid(av[3]))
				render = render_fractol();
			else
				return (arg_error(2));
		}
		else
			return (arg_error(3));
	}
	else
		return (arg_error(1));
	return (render);
}	
