/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:46:13 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/07/02 18:03:47 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_win_data	mlx_data;

	check_args(argc, argv);
	fdf_init(&mlx_data.fdf, argv[1]);
	mlx_start(&mlx_data);
	plot(mlx_data, mlx_data.fdf);
	mlx_put_image_to_window(mlx_data.mlx, mlx_data.mlx_win,
		mlx_data.img.img, MENU_WIDTH, 0);
	event_hook(&mlx_data);
	mlx_loop(mlx_data.mlx);
	clean_program(&mlx_data, &mlx_data.fdf);
}
