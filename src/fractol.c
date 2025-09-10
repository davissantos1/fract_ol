/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:11:52 by dasimoes          #+#    #+#             */
/*   Updated: 2025/09/07 15:16:10 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	int res;

	if (ac == 2 || ac == 4)
	{
		if (!ft_strncmp(av[1], "mandelbrot", 10) && ac == 2)
			res = start_fractol(av + 1);
		else if (!ft_strncmp(av[1], "ship", 4) && ac == 2)
			res = start_fractol(av + 1);
		else if (!ft_strncmp(av[1], "julia", 5) && ac == 4)
		{
			if (is_valid(av[2]) && is_valid(av[3]))
				res= start_fractol(av + 1);
			else
				return (arg_error(2));
		}
		else
			return (arg_error(3));
	}
	else
		return (arg_error(1));
	return (res);
}	
