/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:14:58 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/04/13 18:57:13 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	counter;
	size_t	little_len;
	char	*big_ptr;

	counter = 0;
	little_len = ft_strlen(little);
	if (little[counter] == '\0')
		return ((char *)big);
	if (!*big)
		return (NULL);
	while (counter < len)
	{
		if ((! ft_strncmp(&big[counter], little, little_len))
			&& little_len <= len - counter)
		{
			big_ptr = &((char *)big)[counter];
			return (big_ptr);
		}
		counter++;
	}
	return (NULL);
}
