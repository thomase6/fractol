/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 10:28:22 by texenber          #+#    #+#             */
/*   Updated: 2025/09/03 10:37:37 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	number_check(char *str)
{
	if (ft_atof(str) > 2.0 || ft_atof(str) < -2.0)
	{
		ft_printf ("Please make sure the parameters "
			"are between 2.0 and -2.0");
		exit (EXIT_FAILURE);
	}
}

static void	dot_check(int i, char *str)
{
	int	dot;

	dot = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		else if (str[i] == '.' && ft_isdigit(str[i + 1]) && dot == 0)
		{
			dot = 1;
			i++;
		}
		else
		{
			ft_printf("wrong variable input");
			exit(EXIT_FAILURE);
		}
	}
}

static void	julia_input_check(char *str)
{
	int	i;

	i = 0;
	if (ft_strncmp(str, "", 1) == 0)
	{
		ft_printf ("wrong variable input for julia");
		exit (EXIT_FAILURE);
	}
	while (str[i] && ft_is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
	{
		ft_printf("wrong variable input for julia");
		exit(EXIT_FAILURE);
	}
	dot_check(i, str);
	number_check(str);
}

void	input_validation(int ac, char **av, t_data *data)
{
	if (ac != 2 && ac != 4)
	{
		ft_printf("Use: ./fractol mandelbrot | julia <a> <b>\n");
		exit(EXIT_FAILURE);
	}
	if (ac == 2 && (ft_strncmp(av[1], "mandelbrot", 10) == 0)
		&& ft_strlen(av[1]) == 10)
		data->name = "mandelbrot";
	else if (ac == 4 && (ft_strncmp(av[1], "julia", 5) == 0)
		&& ft_strlen(av[1]) == 5)
	{
		data->name = "julia";
		julia_input_check(av[2]);
		julia_input_check(av[3]);
		data->j_x = ft_atof(av[2]);
		data->j_y = ft_atof(av[3]);
	}
	else
	{
		ft_printf("Invalid Fractal name\n");
		exit(EXIT_FAILURE);
	}
}
