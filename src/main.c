/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 14:13:47 by texenber          #+#    #+#             */
/*   Updated: 2025/08/25 14:13:50 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int ac, char **av)
{
    t_data  data;

    if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot\0", 11)) 
        || (ac == 4 && !ft_strncmp(av[1], "julia\0", 6)))
    {
        // printf ("valid input\n"); //gotta remove this later
        data.name = av[1];
        // printf ("fractal name: %s", data.name);
        window_init(&data);
        fractal_render(&data);
        mlx_loop(data.mlx);
    }
    else 
    {
        printf ("wrong input"); // change to a proper error message
        exit (EXIT_FAILURE);
    }
    return (0);
}

