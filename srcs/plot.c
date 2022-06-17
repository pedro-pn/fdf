/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:50:22 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/16 23:26:30 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plot_lines(t_win_data mlx_data, t_fdf fdf)
{
	int	center_x;
	int	center_y;
	int	row;
	int	column;
	int	x;
	int	y;
	int xk;
	t_bresendata cord;

	row = 0;
	column = 0;
	center_y = (SCREEN_LENGTH / 2) - (fdf.num_rows / 2) * SIZE_LINE; // colocar dentro da struct fdf
	center_x = (SCREEN_WIDTH / 2) - ((fdf.num_columns - 1) / 2) * SIZE_LINE;
	while (row < fdf.num_rows)
	{
		column = 0;
		y = center_y + (SIZE_LINE * row); 
		while (column < fdf.num_columns - 1)
		{
			x = (column * SIZE_LINE) + center_x;
			xk = x + SIZE_LINE;
			if (fdf.matrix[row][column] == fdf.matrix[row][column + 1])
			{
				cord = get_bresendata(x, y, xk, y); // esssas duas funções podem ser chamadas
				bresen_alg(&(mlx_data.img), cord); // em uma outra função. Vai -
			}									   // facilitar modificações na matrix
			column++;
		}
		row++;
	}
}
// i = 0;
// j = 0;
// while (j < 19)
// {
// 	i = 0;
// 	y = meio_x + (20*j);
// 	while (i < num_lines - 1)
// 	{
// 		x = (i*20) + meio_y;
// 		xk = x + 20;
// 		if (matrix[i][j] == matrix[i+1][j])
// 		{
// 			cord = get_bresendata(y, x, y, xk);
// 			bresen_alg(&(mlx_data.img), cord);	
// 		}
// 		i++;
// 	}
// 	j++;
// }