/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 10:38:19 by texenber          #+#    #+#             */
/*   Updated: 2025/08/29 16:34:23 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    data_init(t_data *data)
{
    data->escape_value = 4;
    data->iter_def = 100;
    data->shift_x = 0.0;
    data->shift_y = 0.0;
    data->zoom = 1.0;
}

int ft_exit(t_data *data)
{
    mlx_destroy_image(data->mlx, data->img.img);
    mlx_destroy_window(data->mlx, data->win);
    mlx_destroy_display(data->mlx);
    free(data->mlx);
    exit(0);
    return (0);
}
int key_press(int keycode, t_data *data)
{   
    double move_speed;
    double scaled_move_speed;

    move_speed = 0.5;
    scaled_move_speed = move_speed * data->zoom;
    if (keycode == ESC)
        ft_exit(data);
    else if (keycode == LEFT)
        data->shift_x -= scaled_move_speed;
    else if (keycode == RIGHT)
        data->shift_x += scaled_move_speed;
    else if (keycode == UP)
        data->shift_y += scaled_move_speed;
    else if (keycode == DOWN)
        data->shift_y -= scaled_move_speed;
    else if (keycode == PLUS)
        data->iter_def += 10;
    else if (keycode == MINUS)
        data->iter_def -= 10;
    fractal_render(data);
    return (0);
}
int mouse_press(int button,int x,int y, t_data *data)
{   
    (void)x;
    (void)y;
    
    if (button == SCROLLUP)
        data->zoom *= 0.9;
    else if (button == SCROLLDOWN)
        data->zoom /= 0.9;
    fractal_render(data);
    return 0;
}
void event_handler(t_data *data)
{ 
    mlx_hook(data->win, 2, 1L<<0, key_press, data);
    mlx_hook(data->win, 4, 1L<<2, mouse_press, data);
    mlx_hook(data->win, 17, 1L<<17, ft_exit, data);
    mlx_loop(data->mlx);
}