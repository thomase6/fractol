/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putlowerhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 07:27:42 by texenber          #+#    #+#             */
/*   Updated: 2025/06/10 10:01:09 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	putlowerhex(unsigned int un)
{
	const char	*hex = "0123456789abcdef";
	int			count;

	count = 0;
	if (un >= 0 && un <= 15)
	{
		write(1, &hex[un], 1);
		count++;
	}
	if (un > 15)
	{
		count += putlowerhex(un / 16);
		count += putlowerhex(un % 16);
	}
	return (count);
}
