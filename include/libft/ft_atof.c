/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 09:33:34 by texenber          #+#    #+#             */
/*   Updated: 2025/08/28 10:48:02 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(char *str)
{
    int     i;
    int     sign;
    double  integer_part;
    double  fractional_part;
    double  pow;

    i = 0;
    sign = 1;
    pow = 1;
    integer_part = 0;
    fractional_part = 0;
    while (ft_is_space(str[i]))
        i++;
    while (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    // if (str[i] == '.')
    //     integer_part = 0;
    while (str[i] && str[i] != '.')
    {    
        integer_part = (integer_part * 10) + (str[i] - 48);
        i++;
    }
    if (str[i] == '.')
        i++;
    while(str[i])
    {
        pow /= 10;
        fractional_part = fractional_part + (str[i] - 48) * pow;
    }
    return ((integer_part + fractional_part) * sign);
}