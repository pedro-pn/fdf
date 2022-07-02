/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:46:13 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/07/02 17:48:46 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	print_oi(int button, int key, int key2, void *param);
void	mouse_hook(t_win_data *mlx_data);

int	main(int argc, char *argv[])
{
	t_win_data	mlx_data;

	check_args(argc, argv);
	fdf_init(&mlx_data.fdf, argv[1]);
	mlx_start(&mlx_data);
	plot(mlx_data, mlx_data.fdf);
	mlx_put_image_to_window(mlx_data.mlx, mlx_data.mlx_win,
		mlx_data.img.img, MENU_WIDTH, 0);
	mlx_hook(mlx_data.mlx_win, 17, 0, &exit_win, &mlx_data);
	mlx_hook(mlx_data.mlx_win, 2, 1L<<0, &key_press, &mlx_data);
	mouse_hook(&mlx_data);
	mlx_key_hook(mlx_data.mlx_win, &key_handle, &mlx_data);
	mlx_loop(mlx_data.mlx);
	clean_program(&mlx_data, &mlx_data.fdf);
}

int	print_oi(int button, int key, int key2, void *param)
{
	ft_printf("ai");
	ft_printf("%d %d %d %d\n", button, key, key2, *((int *)param));
	return 0;
}
