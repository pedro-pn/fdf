/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:43:22 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/04/13 19:01:32 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	counter;

	counter = (int) ft_strlen(s);
	while (counter >= 0)
	{
		if ((unsigned char) s[counter] == (unsigned char) c)
			return (&((char *)s)[counter]);
		counter--;
	}
	return (NULL);
}
