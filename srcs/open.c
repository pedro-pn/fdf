/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:23:32 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/21 13:53:32 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_args(int argc, char *argv[])
{
	int	fd;

	if (argc < 2)
		error("Invalid number of arguments.");
	if (argc > 2)
		error("Too much arguments! Only one is necessary.");
	check_format(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error("Cannot read file.");
}

void	check_format(char *file_name)
{
	int	len_fname;

	len_fname = ft_strlen(file_name);
	if ((ft_strncmp(&(file_name[len_fname - 4]), ".fdf", 4)))
		error("Invalid file format.");
}

void	fdf_init(t_fdf *fdf, char *file_name)
{
	fdf->num_rows = count_lines(file_name);
	fdf->map = fill_map(file_name, fdf->num_rows);
	fdf->matrix = get_matrix(fdf->map, fdf->num_rows);
	fdf->num_columns = get_columns_matrix(fdf->map);
	get_start_pixels(fdf);
}

void	mlx_start(t_win_data *mlx_data)
{
	mlx_data->mlx = mlx_init();
	mlx_data->mlx_win = mlx_new_window(mlx_data->mlx, SCREEN_WIDTH,
			SCREEN_LENGTH, "fdf");
	mlx_data->img.img = mlx_new_image(mlx_data->mlx, SCREEN_WIDTH,
			SCREEN_LENGTH);
	mlx_data->img.addr = mlx_get_data_addr(mlx_data->img.img,
			&(mlx_data->img.bits_per_pixel), &(mlx_data->img.line_length),
			&(mlx_data->img.endian));
}
