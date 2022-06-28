/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:41:17 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/28 15:45:24 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_menu(t_win_data *mlx_data)
{
	void	*mlx;
	void	*win;

	mlx = mlx_data->mlx;
	win = mlx_data->mlx_win;
	paint_menu(mlx_data);
	mlx_string_put(mlx, win, 90, 20, 0X00FFFFFF, "fdf");
	mlx_string_put(mlx, win, 20, 40, 0X00FFFFFF, "by: ppaulo-d");
	mlx_string_put(mlx, win, 90, 80, 0X00FFFFFF, "MENU");
	mlx_string_put(mlx, win, 20, 100, 0X00FFFFFF, "Moves");
	mlx_string_put(mlx, win, 40, 120, 0X00FFFFFF, "Up: UP KEY");
	mlx_string_put(mlx, win, 40, 135, 0X00FFFFFF, "Down: DOWN KEY");
	mlx_string_put(mlx, win, 40, 150, 0X00FFFFFF, "LEFT: LEFT KEY");
	mlx_string_put(mlx, win, 40, 165, 0X00FFFFFF, "RIGHT: RIGHT KEY");
	mlx_string_put(mlx, win, 20, 185, 0X00FFFFFF, "Zoom");
	mlx_string_put(mlx, win, 40, 205, 0X00FFFFFF, "Zoom in: '+'");
	mlx_string_put(mlx, win, 40, 220, 0X00FFFFFF, "Zoom out: '-'");
	mlx_string_put(mlx, win, 20, 240, 0X00FFFFFF, "Z-axis");
	mlx_string_put(mlx, win, 40, 260, 0X00FFFFFF, "Increase: '>'");
	mlx_string_put(mlx, win, 40, 275, 0X00FFFFFF, "Decrease: '<'");
	mlx_string_put(mlx, win, 20, 305, 0X00FFFFFF, "Reset: 'R'");
}
