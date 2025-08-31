/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:37:02 by texenber          #+#    #+#             */
/*   Updated: 2025/08/31 13:17:44 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	window_init(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_printf ("malloc error in mlx_init");
		exit(EXIT_FAILURE);
	}
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, data->name);
	if (!data->win)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		ft_printf ("malloc error in mlx_new_window");
		exit(EXIT_FAILURE);
	}
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img.img)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		ft_printf ("malloc error in mlx_new_image");
		exit(EXIT_FAILURE);
	}
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
}
