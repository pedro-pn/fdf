/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:37:38 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/04/19 03:59:21 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int		counter;
	size_t	length;

	counter = 0;
	length = 0;
	while (src[length])
		length++;
	while ((counter < (int) size - 1 || (int) size < 0) && src[counter])
	{
		dst[counter] = src[counter];
		counter++;
	}
	if (size != 0)
		dst[counter] = '\0';
	return (length);
}
