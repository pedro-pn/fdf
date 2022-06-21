/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:18:53 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/21 19:29:35 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color(t_iso iso, char **map)
{
	char	**splitted_row;
	char	*hexaptr;
	int		color;

	splitted_row = ft_split(map[iso.row], ' ');
	hexaptr = ft_strchr(splitted_row[iso.column], ',');
	if (hexaptr)
		color = htoi(hexaptr++);
	else
		color = 0X00FFFFFF;
	clean_matrix((void **) splitted_row);
	return (color);
}
