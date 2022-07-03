/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:41:17 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/07/03 13:24:35 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	print_menu_2(t_win_data *mlx_data);

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
	mlx_string_put(mlx, win, 40, 115, MANUAL_C, "Up: UP Key");
	mlx_string_put(mlx, win, 40, 130, MANUAL_C, "Down: DOWN key");
	mlx_string_put(mlx, win, 40, 145, MANUAL_C, "Left: LEFT key");
	mlx_string_put(mlx, win, 40, 160, MANUAL_C, "Right: RIGHT key");
	mlx_string_put(mlx, win, 20, 185, TITLE_C, "Rotations");
	mlx_string_put(mlx, win, 40, 200, MANUAL_C, "X-axis = 'W' and 'S'");
	mlx_string_put(mlx, win, 40, 215, MANUAL_C, "Y-axis = 'A' and 'D'");
	mlx_string_put(mlx, win, 40, 230, MANUAL_C, "Z-axis = 'Q' and 'E'");
	mlx_string_put(mlx, win, 20, 255, TITLE_C, "Zoom");
	mlx_string_put(mlx, win, 40, 270, MANUAL_C, "Zoom in: '+'");
	mlx_string_put(mlx, win, 40, 285, MANUAL_C, "Zoom out: '-'");
	mlx_string_put(mlx, win, 20, 310, TITLE_C, "Z-axis");
	mlx_string_put(mlx, win, 40, 325, MANUAL_C, "Increase: '>'");
	mlx_string_put(mlx, win, 40, 340, MANUAL_C, "Decrease: '<'");
	print_menu_2(mlx_data);
}

static void	print_menu_2(t_win_data *mlx_data)
{
	void	*mlx;
	void	*win;

	mlx = mlx_data->mlx;
	win = mlx_data->mlx_win;
	mlx_string_put(mlx, win, 20, 365, TITLE_C, "Projection");
	mlx_string_put(mlx, win, 40, 380, MANUAL_C, "Isometric: 'I'");
	mlx_string_put(mlx, win, 40, 395, MANUAL_C, "Orthographic: 'O'");
	mlx_string_put(mlx, win, 20, 420, TITLE_C, "Mouse control");
	mlx_string_put(mlx, win, 40, 435, MANUAL_C, "Left button: translation");
	mlx_string_put(mlx, win, 40, 450, MANUAL_C, "Right button: rotation");
	mlx_string_put(mlx, win, 40, 465, MANUAL_C, "Scroll u/d: zoom in/out");
	mlx_string_put(mlx, win, 40, 480, MANUAL_C, "Shift + scroll: z-axis");
	mlx_string_put(mlx, win, 20, 505, TITLE_C, "Reset: 'R'");
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
