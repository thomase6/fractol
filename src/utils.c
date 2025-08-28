/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 10:18:36 by texenber          #+#    #+#             */
/*   Updated: 2025/08/28 08:35:15 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double map(double unscaled_num, double new_max, double new_min, double old_max, double old_min)
{
    return ((new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min);
}
t_complex sum_complex(t_complex z1, t_complex z2)
{
    t_complex result;
    
    result.x = z1.x + z2.x;
    result.y = z1.y + z2.y;
    return (result);
}
t_complex square_complex(t_complex z)
{
    t_complex result;

    result.x = (z.x * z.x) - (z.y * z.y);
    result.y = 2 * z.x * z.y;
    return (result);
}
