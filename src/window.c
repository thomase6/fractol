/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:17:59 by texenber          #+#    #+#             */
/*   Updated: 2025/08/27 14:54:22 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    data_init(t_data *data)
{
    data->escape_value = 4;
    data->iter_def = 200;
    data->shift_x = 0.0;
    data->shift_y = 0.0;
}

int ft_exit(t_data *data)
{
    mlx_destroy_image(data->mlx, data->img.img);
    mlx_destroy_window(data->mlx, data->win);
    mlx_destroy_display(data->mlx);
    free(data->mlx);
    exit(0);
}
void event_handler(t_data *data)
{ 
    mlx_hook(data->win, 2, 1L<<0, key_press, data);
    mlx_hook(data->win, 4, 1L<<2, mouse_press, data);
    mlx_hook(data->win, 17, 1L<<17, ft_exit, data);
    
}
void window_init(t_data *data)
{
    
    data->mlx = mlx_init();
    if (!data->mlx)
    {
        printf ("malloc error");
        exit(EXIT_FAILURE);
    }
    data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, data->name);
    if (!data->win)
    {
        mlx_destroy_display(data->mlx);
        free(data->mlx);
        printf ("malloc error");
        exit(EXIT_FAILURE);
    }
    data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    if (!data->img.img)
    {
        // mlx_destroy_window(data->mlx, data->win);
        // mlx_destroy_display(data->mlx);
        // free(data->mlx);
        printf ("malloc error");
        exit(EXIT_FAILURE);
    }
    data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp, &data->img.line_len, &data->img.endian);
    event_handler(data);
    data_init(data);
}
