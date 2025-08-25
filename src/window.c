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

int ft_mlx_exit(t_data *data)
{
    mlx_destroy_window(data->mlx, data->win);
    mlx_destroy_display(data->mlx);
    free(data->mlx);
    exit(0);
}
void my_mlx_put_pixel(t_img *img, int x, int y, int color)
{
    char *dst;

    dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
    *(unsigned int*)dst = color;
}
void color_screen(t_data *data, int color)
{
    int y = 0;
    int x = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            my_mlx_put_pixel( &data->img, x, y, color);
            x++;
        }
        y++;
    }
}
int key_press(int keycode, t_data *data)
{
    if (keycode == G)
    {
        color_screen(data, 0x00FF00);
    }
    if (keycode == B)
    {
        color_screen(data, 0x0000FF);
    }
    else if (keycode == ESC)
    {
        printf("keycode: %d was pressed",keycode);
        ft_mlx_exit(data);
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
    return (0);
}
int window(void)
{
    t_data data;

    data.mlx = mlx_init();
    if (!data.mlx)
        return (1);
    data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "The Void");
    if (!data.win)
    {
        mlx_destroy_display(data.mlx);
        free(data.mlx);
        return (1);
    }
    data.img.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
    data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bpp, &data.img.line_len, &data.img.endian);
    mlx_key_hook(data.win, key_press, &data);
    mlx_loop(data.mlx);
    return (0);
}
