/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:00:11 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/21 19:01:00 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	hexa_index(char n)
{
	int		index;
	char	*base;

	index = 0;
	base = "0123456789ABCDEF";
	while (base[index])
	{
		if (n == base[index] || ft_toupper(n) == base[index])
			return (index);
		index++;
	}
	return (0);
}

int	htoi(char *hptr)
{
	int	len_hptr;
	int	counter;
	int	htoi;

	counter = 0;
	htoi = 0;
	len_hptr = ft_strlen(hptr) - 1;
	while (len_hptr > 1)
	{
		htoi += pow(16, counter) * hexa_index(hptr[len_hptr]);
		len_hptr--;
		counter++;
	}
	return (htoi);
}
