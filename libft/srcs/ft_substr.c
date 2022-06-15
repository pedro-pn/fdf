/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 19:58:30 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/04/26 22:40:19 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		mem;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	mem = s_len - start;
	if (mem > (int) len)
		mem = len;
	if (mem <= 0)
		mem = 0;
	sub = (char *) malloc((mem * sizeof(char)) + 1);
	if (sub == NULL)
		return (NULL);
	sub[mem] = 0;
	while (mem > 0)
	{
		sub[mem - 1] = s[start + mem - 1];
		mem--;
	}
	return (sub);
}
