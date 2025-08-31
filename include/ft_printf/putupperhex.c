/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putupperhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 07:25:41 by texenber          #+#    #+#             */
/*   Updated: 2025/06/10 09:59:23 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	putupperhex(unsigned int un)
{
	const char	*hex = "0123456789ABCDEF";
	int			count;

	count = 0;
	if (un >= 0 && un <= 15)
	{
		write(1, &hex[un], 1);
		count++;
	}
	if (un > 15)
	{
		count += putupperhex(un / 16);
		count += putupperhex(un % 16);
	}
	return (count);
}
