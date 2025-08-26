/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:17:59 by texenber          #+#    #+#             */
/*   Updated: 2025/08/26 16:00:10 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    data_init(t_data *data)
{
    data->escape_value = 4;
    data->iter_def = 200;
}

int ft_exit(t_data *data)
{
    mlx_destroy_window(data->mlx, data->win);
    mlx_destroy_display(data->mlx);
    free(data->mlx);
    exit(0);
}
void event_handler(t_data *data)
{ 
    mlx_hook(data->win, 2, 1L<<0, key_press, data);
    // mlx_hook(data->win, 4, 1L<<2, mouse_press, data);
    // mlx_hook(data->win, 17, 1L<<17, close_x, data);
    
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
        ft_exit(data);
        printf ("malloc error");
        exit(EXIT_FAILURE);
    }
    data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp, &data->img.line_len, &data->img.endian);
    event_handler(data);
    data_init(data);
}
