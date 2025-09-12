/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 20:59:35 by dasimoes          #+#    #+#             */
/*   Updated: 2025/09/10 18:21:50 by dasimoes         ###   ########.fr       */
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
		ft_putstr_fd("3- ./fractol ship\n", 1);
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
		ft_putstr_fd("3- ./fractol ship\n", 1);
	}
	return (1);
}

int	func_error(t_gc *gc)
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
		if (i == 0 && (str[i] == '+' || str[i] == '-'))
			i++;
		if ((i == 1 || i == 2) && str[i] == '.')
			i++;
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

float	ft_abs(float num)
{
	if (num < 0)
		return (-num);
	return (num);
}

float	ft_atof(char *s)
{
	int		i;
	float	point;
	float	whole;
	float	decimal;

	i = 0;
	point = 10;
	decimal = 0;
	whole = (float)ft_atoi(s);
	while (s[i] != '.' && s[i])
		i++;
	if (s[i] == '.')
	{
		i++;
		while (s[i] >= '0' && s[i] <= '9')
		{
			decimal += (s[i] - '0') / point;
			point *= 10;
			i++;
		}
	}
	if (whole < 0)
		return (whole - decimal);
	return (whole + decimal);
}
