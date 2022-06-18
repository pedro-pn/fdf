/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:50:22 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/18 15:05:13 by ppaulo-d         ###   ########.fr       */
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

void	plot_rows(t_win_data mlx_data, t_fdf fdf)
{
	int	center_x;
	int	center_y;
	int	row;
	int	column;
	int	x;
	int	y;
	int yk;
	t_bresendata cord;

	row = 0;
	column = 0;
	center_y = (SCREEN_LENGTH / 2) - (fdf.num_rows / 2) * SIZE_LINE; // colocar dentro da struct fdf
	center_x = (SCREEN_WIDTH / 2) - ((fdf.num_columns - 1) / 2) * SIZE_LINE;
	while (column < fdf.num_columns)
	{
		row = 0;
		x = center_x + (SIZE_LINE * column); 
		while (row < fdf.num_rows - 1)
		{
			y = (row * SIZE_LINE) + center_y;
			yk = y + SIZE_LINE;
			if (fdf.matrix[row][column] == fdf.matrix[row + 1][column])
			{
				cord = get_bresendata(x, y, x, yk); // esssas duas funções podem ser chamadas
				bresen_alg(&(mlx_data.img), cord); // em uma outra função. Vai -
			}									   // facilitar modificações na matrix
			row++;
		}
		column++;
	}
}

void	plot_lines_iso(t_win_data mlx_data, t_fdf fdf)
{
	int	center_x;
	int	center_y;
	int	row;
	int	column;
	int	x;
	int	y;
	int xk;
	int	yk;
	t_bresendata cord;

	row = 0;
	column = 0;
	//center_y = (SCREEN_LENGTH / 2) - (fdf.num_rows / 2) * (SIZE_LINE/4); // colocar dentro da struct fdf
//	center_x = (SCREEN_WIDTH / 2) + ((fdf.num_columns - 1) / 2) * (SIZE_LINE/8);
	while (row < fdf.num_rows)
	{
		column = 0;
		y = fdf.start_y + (row * SIZE_LINE / 4);
		x = fdf.start_x - (row * SIZE_LINE / 4);
		while (column < fdf.num_columns - 1)
		{
			xk = x + (SIZE_LINE / 4);
			yk = y + (SIZE_LINE / 4) + (fdf.matrix[row][column] - fdf.matrix[row][column + 1]);
		//	if (fdf.matrix[row][column] == fdf.matrix[row][column + 1])
		//	{
				cord = get_bresendata(x, y, xk, yk); // esssas duas funções podem ser chamadas
				bresen_alg(&(mlx_data.img), cord); // em uma outra função. Vai -
		//	}									   // facilitar modificações na matrix
			column++;
			y = yk;
			x = xk;
		}
		row++;
	}
}

void	plot_rows_iso(t_win_data mlx_data, t_fdf fdf)
{
	int	center_x;
	int	center_y;
	int	row;
	int	column;
	int	x;
	int	y;
	int xk;
	int	yk;
	t_bresendata cord;

	row = 0;
	column = 0;
	//center_y = (SCREEN_LENGTH / 2) - (fdf.num_rows / 2) * (SIZE_LINE/4); // c/olocar dentro da struct fdf
//	center_x = (SCREEN_WIDTH / 2) + ((fdf.num_columns - 1) / 2) * (SIZE_LINE/8);
	while (column < fdf.num_columns)
	{
		row = 0;
		y = fdf.start_y + (column * SIZE_LINE / 4);
		x = fdf.start_x + (column * SIZE_LINE / 4);
		while (row < fdf.num_rows - 1)
		{
			xk = x - (SIZE_LINE / 4);
			yk = y + (SIZE_LINE / 4) + fdf.matrix[row][column] - fdf.matrix[row + 1][column];
		//	if (fdf.matrix[row][column] == fdf.matrix[row][column + 1])
		//	{
				cord = get_bresendata(x, y, xk, yk); // esssas duas funções podem ser chamadas
				bresen_alg(&(mlx_data.img), cord); // em uma outra função. Vai -
		//	}									   // facilitar modificações na matrix
			row++;
			y = yk;
			x = xk;
		}
		column++;
	}
}

void	get_start_pixels(t_fdf *fdf)
{

	(*fdf).start_x = (SCREEN_WIDTH / 2) - (((*fdf).num_columns * SIZE_LINE / 8)
		 - ((*fdf).num_rows * SIZE_LINE / 8));
	(*fdf).start_y = (SCREEN_LENGTH / 2) - (((*fdf).num_columns * SIZE_LINE / 8)
		 + ((*fdf).num_rows * SIZE_LINE / 8));

}