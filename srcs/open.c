/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:23:32 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/23 14:03:05 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_init(t_fdf *fdf, char *file_name)
{
	fdf->num_rows = count_lines(file_name);
	fdf->map = fill_map(file_name, fdf->num_rows);
	fdf->matrix_color = malloc(sizeof(int *) * (fdf->num_rows + 1));
	fdf->matrix_color[fdf->num_rows] = NULL;
	fdf->num_columns = get_columns_matrix(fdf->map);
	get_matrix(fdf);
	fdf->tile_size = get_tile_size(fdf->num_rows, fdf->num_columns);
	get_start_pixels(fdf);
	fdf->z_factor = 2;
}

void	mlx_start(t_win_data *mlx_data)
{
	mlx_data->mlx = mlx_init();
	mlx_data->mlx_win = mlx_new_window(mlx_data->mlx, SCREEN_WIDTH,
			SCREEN_LENGTH, "fdf");
	create_img(mlx_data);
}

int	get_tile_size(int row, int column)
{
	int	tile_size;
	int	total_area;

	total_area = SCREEN_WIDTH * SCREEN_LENGTH / 4;
	tile_size = round(sqrt(total_area / (tan(0.463646716)
					* pow(row + column - 2, 2))));
	if (tile_size < 2)
		return (2);
	return (tile_size);
}
