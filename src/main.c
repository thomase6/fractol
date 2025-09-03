/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 09:34:02 by texenber          #+#    #+#             */
/*   Updated: 2025/09/03 11:05:22 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_data	data;

	input_validation(ac, av, &data);
	data_init(&data);
	window_init(&data);
	fractal_render(&data);
	event_handler(&data);
	return (0);
}
