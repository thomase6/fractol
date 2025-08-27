/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:19:29 by texenber          #+#    #+#             */
/*   Updated: 2025/08/27 15:01:37 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int key_press(int keycode, t_data *data)
{
    printf("%d\n", data->iter_def);
    if (keycode == ESC)
    {
        printf("ESC was pressed");
        ft_exit(data);
    }
    else if (keycode == LEFT)
        data->shift_x -= 0.5;
    else if (keycode == RIGHT)
        data->shift_x += 0.5;
    else if (keycode == UP)
        data->shift_y += 0.5;
    else if (keycode == DOWN)
        data->shift_y -= 0.5;
    else if (keycode == PLUS)
        data->iter_def += 10;
    else if (keycode == MINUS)
        data->iter_def -= 10;
    fractal_render(data);
    return (0);
}
int mouse_press(int keycode, t_data *data)
{   
    printf("%d\n", keycode);
    return 0;
}
// int close_x(t_data *data)
// {
//     mlx_destroy_window(data->mlx, data->win);
//     return(0);
// }
