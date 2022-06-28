/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:23:32 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/28 20:33:29 by ppaulo-d         ###   ########.fr       */
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
	fdf_default(fdf);
}

void	fdf_default(t_fdf *fdf)
{
	fdf->move_x = 0;
	fdf->move_y = 0;
	fdf->tile_size = get_tile_size(fdf->num_rows, fdf->num_columns);
	fdf->z_factor = 2;
	get_start_pixels(fdf);
}

void	mlx_start(t_win_data *mlx_data)
{
	mlx_data->mlx = mlx_init();
	mlx_data->mlx_win = mlx_new_window(mlx_data->mlx, SCREEN_WIDTH,
			SCREEN_HEIGHT, "FdF");
//	print_menu(mlx_data);
	create_img(mlx_data);
	//create_menu(mlx_data);
}

int	get_tile_size(int row, int column)
{
	int	tile_size;
	int	total_area;

	total_area = SCREEN_WIDTH * SCREEN_HEIGHT / 4;
	tile_size = round(sqrt(total_area / (tan(ISO_ANG)
					* pow(row + column - 2, 2))));
	if (tile_size < 2)
		return (2);
	return (tile_size);
}

void	create_img(t_win_data *mlx_data)
{
	mlx_data->img.img = mlx_new_image(mlx_data->mlx, SCREEN_WIDTH - 200,
			SCREEN_HEIGHT);
	mlx_data->img.addr = mlx_get_data_addr(mlx_data->img.img,
			&(mlx_data->img.bits_per_pixel), &(mlx_data->img.line_length),
			&(mlx_data->img.endian));
	paint_image(&mlx_data->img);
}
