/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 14:13:47 by texenber          #+#    #+#             */
/*   Updated: 2025/08/28 10:38:15 by texenber         ###   ########.fr       */
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
        if (ac == 4)
        {
            data.j_x = ft_atof(av[2]);
            data.j_y = ft_atof(av[3]); 
        }
        window_init(&data);
        fractal_render(&data);
        mlx_loop(data.mlx);
    }
    else 
    {
        printf ("wrong input, please input: 'mandelbrot' 'julia <a> <b>'\n"); // change to a proper error message
        exit (EXIT_FAILURE);
    }
    return (0);
}

