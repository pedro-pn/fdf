/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:41:17 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/28 22:48:05 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	print_menu(t_win_data *mlx_data)
{
	void	*mlx;
	void	*win;

	mlx = mlx_data->mlx;
	win = mlx_data->mlx_win;
	mlx_string_put(mlx, win, 90, 20, TITLE_C, "FdF");
	mlx_string_put(mlx, win, 20, 40, AUTHOR_C, "by: ppaulo-d");
	mlx_string_put(mlx, win, 90, 80, TITLE_C, "MENU");
	mlx_string_put(mlx, win, 20, 100, TITLE_C, "Moves");
	mlx_string_put(mlx, win, 40, 120, MANUAL_C, "Up: UP KEY");
	mlx_string_put(mlx, win, 40, 135, MANUAL_C, "Down: DOWN KEY");
	mlx_string_put(mlx, win, 40, 150, MANUAL_C, "LEFT: LEFT KEY");
	mlx_string_put(mlx, win, 40, 165, MANUAL_C, "RIGHT: RIGHT KEY");
	mlx_string_put(mlx, win, 20, 185, TITLE_C, "Zoom");
	mlx_string_put(mlx, win, 40, 205, MANUAL_C, "Zoom in: '+'");
	mlx_string_put(mlx, win, 40, 220, MANUAL_C, "Zoom out: '-'");
	mlx_string_put(mlx, win, 20, 240, TITLE_C, "Z-axis");
	mlx_string_put(mlx, win, 40, 260, MANUAL_C, "Increase: '>'");
	mlx_string_put(mlx, win, 40, 275, MANUAL_C, "Decrease: '<'");
	mlx_string_put(mlx, win, 20, 305, TITLE_C, "Reset: 'R'");
}

void	create_menu(t_win_data *mlx_data)
{
	mlx_data->menu.img = mlx_new_image(mlx_data->mlx, MENU_WIDTH,
			SCREEN_HEIGHT);
	mlx_data->menu.addr = mlx_get_data_addr(mlx_data->menu.img,
			&(mlx_data->menu.bits_per_pixel), &(mlx_data->menu.line_length),
			&(mlx_data->menu.endian));
	paint_menu(&mlx_data->menu);
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win,
		mlx_data->menu.img, 0, 0);
	print_menu(mlx_data);
}
