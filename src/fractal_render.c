/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:00:09 by texenber          #+#    #+#             */
/*   Updated: 2025/09/01 09:27:25 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	mandelbrot(t_complex z, int x, int y, t_data *data)
{
	t_complex	c;
	int			i;
	int			color;

	c.x = z.x;
	c.y = z.y;
	i = 0;
	while (i < data->iter_def && (z.x * z.x + z.y * z.y <= 4))
	{
		z = sum_complex(square_complex(z), c);
		i++;
	}
	if (i < data->iter_def)
		color = map(i + 1, GREEN, BLUE, data->iter_def);
	else
		color = BLACK;
	my_mlx_put_pixel(&data->img, x, y, color);
}

void	julia(t_complex z, int x, int y, t_data *data)
{
	t_complex	c;
	int			i;
	int			color;

	c.x = data->j_x;
	c.y = data->j_y;
	i = 0;
	while (i < data->iter_def && (z.x * z.x + z.y * z.y < 4))
	{
		z = sum_complex(square_complex(z), c);
		i++;
	}
	if (i < data->iter_def)
		color = map(i + 1, GREEN, BLUE, data->iter_def);
	else
		color = BLACK;
	my_mlx_put_pixel(&data->img, x, y, color);
}

void	handle_pixel(int x, int y, t_data *data)
{
	t_complex	z;

	z.x = (map(x, +2, -2, WIDTH) * data->zoom) + data->shift_x;
	z.y = (map(y, -2, +2, HEIGHT) * data->zoom) + data->shift_y;
	if (ft_strncmp(data->name, "julia", 5) == 0)
		julia(z, x, y, data);
	else if (ft_strncmp(data->name, "mandelbrot", 11) == 0)
		mandelbrot(z, x, y, data);
	else
	{
		ft_printf("Unknown Fractal Type\n");
		exit(EXIT_FAILURE);
	}
}

void	fractal_render(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}
