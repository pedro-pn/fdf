/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:18:53 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/21 22:01:47 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_matrix_color(t_fdf *fdf, char **row_splt, int row)
{
	int		column;
	char	*hexaptr;

	column = 0;
	fdf->matrix_color[row] = malloc(sizeof(int) * fdf->num_columns);
	while (row_splt[column])
	{
		hexaptr = ft_strchr(row_splt[column], ',');
		if (hexaptr)
			(fdf->matrix_color)[row][column] = htoi(hexaptr++);
		else
			(fdf->matrix_color)[row][column] = 0X00FFFFFF;
		column++;
	}
}
