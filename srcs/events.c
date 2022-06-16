/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:00:15 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/16 20:56:15 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys.h"

int	exit_win(int key, void *param)
{
	if (key == ESC)
	{
		mlx_clear_window(((t_win_data *)param)->mlx, ((t_win_data *)param)->mlx_win);
		mlx_destroy_window(((t_win_data *)param)->mlx, ((t_win_data *)param)->mlx_win);
		mlx_destroy_image(((t_win_data *)param)->mlx, ((t_win_data *)param)->img.img);
		mlx_loop_end(((t_win_data *)param)->mlx);
	//	mlx_destroy_display(((t_win_data *)param)->mlx);
	}
	return (0);
}
