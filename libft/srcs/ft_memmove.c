/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 04:57:31 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/04/23 01:16:57 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	counter;

	if (&((unsigned char *)src)[0] < &((unsigned char *)dest)[0])
		counter = n - 1;
	else
		counter = 0;
	while (counter < (int) n && counter >= 0)
	{
		((unsigned char *)dest)[counter] = ((unsigned char *)src)[counter];
		if (&((unsigned char *)src)[0] < &((unsigned char *)dest)[0])
			counter--;
		else
			counter++;
	}
	return (dest);
}
