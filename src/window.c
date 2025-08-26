/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:17:59 by texenber          #+#    #+#             */
/*   Updated: 2025/08/15 11:18:02 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    data_init(t_data *data)
{
    data->escape_value = 4;
    data->iter_def = 100;
}

int ft_exit(t_data *data)
{
    mlx_destroy_window(data->mlx, data->win);
    mlx_destroy_display(data->mlx);
    free(data->mlx);
    exit(0);
}
// int key_press(int keycode, t_data *data)
// {
//     if (keycode == ESC)
//     {
//         printf("keycode: %d was pressed",keycode);
//         ft_exit(data);
//     }
//     mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
//     return (0);
// }
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
//    mlx_key_hook(data->win, key_press, &data);
    data_init(data);
}
