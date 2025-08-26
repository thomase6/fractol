/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:19:29 by texenber          #+#    #+#             */
/*   Updated: 2025/08/26 15:58:51 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int key_press(int keycode, t_data *data)
{
    if (keycode == ESC)
    {
        printf("ESC was pressed");
        ft_exit(data);
        return (1);
    }
    return (0);
}
// int mouse_press(int keycode, t_data *data)
// {   
//     return 0;
// }
// int close_x(t_data *data)
// {
//     return 0;
// }