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

// x11 keycodes
# define ESC 65307
# define B 98
# define G 103

// libraries
#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "/home/texenber/CC/fractol_wip/include/libft/libft.h"

typedef struct s_img
{
    void    *img;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian; 
}           t_img;

typedef struct s_data
{
    void    *mlx;
    void    *win;
    t_img   img;
}               t_data;

int window(void);
int main(int ac, char **av);
int ft_strncmp(const char *s1, const char *s2, size_t n);

#endif