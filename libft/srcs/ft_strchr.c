/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:12:33 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/04/13 18:54:31 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		counter;
	int		len_s;

	counter = 0;
	len_s = (int) ft_strlen(s);
	while (counter <= len_s)
	{
		if (s[counter] == (unsigned char) c)
			return (&((char *)s)[counter]);
		counter++;
	}
	return (NULL);
}
