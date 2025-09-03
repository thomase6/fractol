/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 08:49:44 by texenber          #+#    #+#             */
/*   Updated: 2025/09/03 09:38:45 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// window size
# define WIDTH 500
# define HEIGHT 500

// x11 keycodes
# define ESC 65307
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364
# define PLUS 65451
# define MINUS 65453
# define SCROLLUP 4
# define SCROLLDOWN 5

// colors
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define GREEN 0x00FF00
# define RED 0xFF0000
# define BLUE 0x0000FF
# define PINK 0xFF33FF
# define COOLBLUE 0x0066FF

// libraries
# include <mlx.h>
# include <stdlib.h>
# include "../include/libft/libft.h"
# include "../include/ft_printf/libftprintf.h"

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_data
{
	char	*name;
	void	*mlx;
	void	*win;
	t_img	img;
	double	escape_value;
	int		iter_def;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	j_x;
	double	j_y;
}				t_data;

int			main(int ac, char **av);

// *** libft and printf functions ***
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *s);
int			ft_printf(const char *format, ...);
double		ft_atof(char *str);

// *** mlx_utils.c ***
void		data_init(t_data *data);
void		event_handler(t_data *data);
int			key_press(int keycode, t_data *data);
int			mouse_press(int button, int x, int y, t_data *data);
int			ft_exit(t_data *data);

// *** window_init.c ***
void		window_init(t_data *data);

// *** math_utils.c ***
double		map(double unscaled_num, double new_max,
				double new_min, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

// *** fractal_render ***
void		fractal_render(t_data *data);
void		handle_pixel(int x, int y, t_data *data);
void		my_mlx_put_pixel(t_img *img, int x, int y, int color);
void		mandelbrot(t_complex z, int x, int y, t_data *data);
void		julia(t_complex z, int x, int y, t_data *data);

#endif