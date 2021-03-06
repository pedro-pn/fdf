/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:28:33 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/24 10:50:24 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clean_matrix(void **matrix)
{
	int	matrix_index;

	matrix_index = 0;
	while (matrix[matrix_index])
	{
		free(matrix[matrix_index]);
		matrix_index++;
	}
	free(matrix);
}

void	clean_program(t_win_data *mlx_data, t_fdf *fdf)
{
	mlx_destroy_window(mlx_data->mlx, mlx_data->mlx_win);
	mlx_destroy_display(mlx_data->mlx);
	free(mlx_data->mlx);
	clean_matrix((void **) fdf->matrix);
	clean_matrix((void **) fdf->map);
	clean_matrix((void **) fdf->matrix_color);
}
