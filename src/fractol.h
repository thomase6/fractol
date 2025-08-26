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

// colors
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define GREEN 0x00FF00
# define RED 0xFF0000
# define BLUE 0x0000FF
# define COOLBLUE 0x0066FF

// libraries
#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "/home/texenber/CC/fractol/include/libft/libft.h"

typedef struct s_complex
{
    double  x;
    double  y;
}           t_complex;

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
    char    *name;
    void    *mlx;
    void    *win;
    t_img   img;
    // hook variables // TO DO
    double  escape_value;
    int     iter_def;
}           t_data;


int main(int ac, char **av);

// *** libft functions used ***
int ft_strncmp(const char *s1, const char *s2, size_t n);

// *** window creation ***
void window_init(t_data *data);

// *** fractal render ***
void fractal_render(t_data *data);

// *** color the screen ***
void    handle_pixel(int x, int y, t_data *data);
void my_mlx_put_pixel(t_img *img, int x, int y, int color);

// *** mlx hook functions ***
int key_press(int keycode, t_data *data);

// *** utils ***
double map(double unscaled_num, double new_max, double new_min, double old_max, double old_min);
t_complex square_complex(t_complex z);
t_complex sum_complex(t_complex z1, t_complex z2);

// *** free and destroy ***
int ft_exit(t_data *data);

#endif