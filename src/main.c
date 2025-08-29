/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 09:34:02 by texenber          #+#    #+#             */
/*   Updated: 2025/08/29 15:54:28 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void julia_input_check(t_data *data)
{
    if (data->j_x > 2.0 || data->j_x < -2.0 || 
        data->j_y > 2.0 || data->j_y < -2.0)
    {
        ft_printf("the parameters must be between -2.0 and 2.0");
        exit(EXIT_FAILURE);
    }
    
}
static void input_validation(int ac, char **av, t_data *data)
{
    if (ac != 2 && ac != 4)
    {
        ft_printf("Use: ./fractol mandelbrot | julia <a> <b>\n");
        exit(EXIT_FAILURE);
    }
    if (ac == 2 && (ft_strncmp(av[1], "mandelbrot", 10) == 0) && ft_strlen(av[1]) == 10)
        data->name = "mandelbrot";
    else if (ac == 4 && (ft_strncmp(av[1], "julia", 5) == 0) && ft_strlen(av[1]) == 5)
    {    
        data->name = "julia";
        data->j_x = ft_atof(av[2]);
        data->j_y = ft_atof(av[3]);
        julia_input_check(data);
    }    
    else
    {
        ft_printf("Invalid Fractal name\n");
        exit(EXIT_FAILURE);
    }   
        
}
int main(int ac, char **av)
{
    t_data data;
    
    input_validation(ac, av, &data);
    data_init(&data);
    window_init(&data);
    fractal_render(&data);
    event_handler(&data);
    return (0);   
}