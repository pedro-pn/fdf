/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:39:23 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/04/21 16:01:31 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	s_len;
	size_t	index;
	char	*map_str;

	if (s == NULL || (*f) == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	map_str = (char *) malloc((s_len * sizeof(char)) + 1);
	if (!map_str)
		return (NULL);
	index = 0;
	while (index < s_len)
	{
		map_str[index] = (*f)(index, s[index]);
		index++;
	}
	map_str[index] = 0;
	return (map_str);
}
