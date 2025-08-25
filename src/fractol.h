/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:01:46 by texenber          #+#    #+#             */
/*   Updated: 2025/08/15 11:01:51 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// window size
# define WIDTH 500
# define HEIGHT 500

// libraries
#include <mlx.h>
#include <stdlib.h>

typedef struct s_data
{
    void    *img;
    char    *addr;
    int     bpp;
    int     line_length;
    int     endian; 
}           t_data;

int main(void);

#endif