/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 23:45:30 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/04/20 01:07:12 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	counter;
	int		value;

	counter = 0;
	value = 0;
	while ((counter < n) && (s1[counter] || s2 [counter]))
	{
		value = (unsigned char) s1[counter] - (unsigned char) s2[counter];
		if (value != 0)
			return (value);
		counter++;
	}
	return (value);
}
