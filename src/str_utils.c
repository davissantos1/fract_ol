/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 20:59:35 by dasimoes          #+#    #+#             */
/*   Updated: 2025/09/03 20:14:26 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	arg_error(int type)
{
	if (type == 1)
	{
		ft_putstr_fd("You must use it like this:\n", 1);
		ft_putstr_fd("1- ./fractol mandelbrot\n", 1);
		ft_putstr_fd("2- ./fractol julia <x value> <y value>\n", 1);
	}
	if (type == 2)
	{
		ft_putstr_fd("You must use valid decimal numbers:\n", 1);
		ft_putstr_fd("Example: ./fractol julia 10 5\n", 1);
	}
	if (type == 3)
	{
		ft_putstr_fd("You had a typo, use one of these:\n", 1);
		ft_putstr_fd("1- ./fractol mandelbrot\n", 1);
		ft_putstr_fd("2- ./fractol julia <x value> <y value>\n", 1);
	}
	return (1);
}

int func_error(t_gc *gc)
{
	gc_free_all(gc);
	perror("Error: ");
	return (1);
}

int	is_valid(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}
		
