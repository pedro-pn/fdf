/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:46:13 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/21 15:51:37 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys.h"


int main(int argc, char *argv[])
{
	t_win_data	mlx_data;
	t_fdf		fdf;
	
	check_args(argc, argv);
	fdf_init(&fdf, argv[1]);
	mlx_start(&mlx_data);
	plot_iso(mlx_data, fdf);

	mlx_put_image_to_window(mlx_data.mlx, mlx_data.mlx_win,
			mlx_data.img.img, 0, 0);
	mlx_key_hook(mlx_data.mlx_win, &exit_win, &mlx_data);
	mlx_loop(mlx_data.mlx);
	mlx_destroy_display(mlx_data.mlx);
	free(mlx_data.mlx);
	clean_matrix((void **) fdf.matrix);
	clean_matrix((void **) fdf.map);
}

