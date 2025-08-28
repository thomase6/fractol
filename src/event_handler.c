/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:19:29 by texenber          #+#    #+#             */
/*   Updated: 2025/08/28 09:15:03 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int key_press(int keycode, t_data *data)
{   
     double move_speed;
     double scaled_move_speed;

     move_speed = 0.5;
     scaled_move_speed = move_speed * data->zoom;
    
//    printf("%d\n", data->iter_def);
    if (keycode == ESC)
    {
        printf("ESC was pressed");
        ft_exit(data);
    }
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
//    printf("%d\n", button);
    if (button == 4)
        data->zoom *= 0.9;
    else if (button == 5)
        data->zoom /= 0.9;
    fractal_render(data);
    return 0;
}
