/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 09:59:33 by texenber          #+#    #+#             */
/*   Updated: 2025/08/27 14:28:28 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void my_mlx_put_pixel(t_img *img, int x, int y, int color)
{
    char *dst;

    dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
    *(unsigned int*)dst = color;
}

void    handle_pixel(int x, int y, t_data *data)
{
    t_complex   z;
    t_complex   c;
    int         i;
    int         color;

    i = 0;
    z.x = 0.0;
    z.y = 0.0;

    c.x = map(x, +2, -2, WIDTH, 0) + data->shift_x;
    c.y = map(y, -2, +2, HEIGHT, 0) + data->shift_y;
    // iterations until escape
    while (i < data->iter_def)
    {
        z = sum_complex(square_complex(z), c);
        if (z.x * z.x + z.y * z.y > 4)
        {
            color = map(i+1, WHITE, BLACK, data->iter_def, 0);
            my_mlx_put_pixel(&data->img, x, y, color);
            return;
        }
        i++;
    }
    my_mlx_put_pixel(&data->img, x, y, BLACK);
}
void fractal_render(t_data *data)
{
    int x;
    int y;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            handle_pixel(x, y, data);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
