/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:46:13 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/16 22:59:37 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys.h"

int main()
{
	// void	*mlx;
	// void	*mlx_win;
	t_win_data	mlx_data;
	int i;
	int j;
	int x;
	int y;
	int xk;
	// int **matrix;
	// char	**map;
	t_fdf	fdf;
	//int	*exit_func;
//	int yk;
//	exit_func = &(exit_win)(int key, void *param)));
	//t_img	img;
	t_bresendata	cord;
	

	fdf.num_rows = count_lines("./maps/42.fdf");
	fdf.map = fill_map("./maps/42.fdf", fdf.num_rows);
	fdf.matrix = get_matrix(fdf.map, fdf.num_rows);
	fdf.num_columns = 19;
	// ft_printf("ROWS: %d\n COLUMNS: %d\n", fdf.num_rows, fdf.num_columns);
	// return 0;
	mlx_data.mlx = mlx_init();
	mlx_data.mlx_win = mlx_new_window(mlx_data.mlx, SCREEN_WIDTH, SCREEN_LENGTH, "fdf");
	mlx_data.img.img = mlx_new_image(mlx_data.mlx, SCREEN_WIDTH, SCREEN_LENGTH);
	mlx_data.img.addr = mlx_get_data_addr(mlx_data.img.img, &(mlx_data.img.bits_per_pixel), &(mlx_data.img.line_length), &(mlx_data.img.endian));
//	x = 1;
//	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	//bren_alg(&img, 0, 0, 60, 40);
	i = 0;
	j = 0;
	ft_printf("%d\n", fdf.matrix[5][j]);
	int meio_x;
	int meio_y;
	meio_y = (600/2) - (fdf.num_rows/2) * 20;
	meio_x = (800 / 2) - (18 / 2) * 20;
	// while (j < fdf.num_rows)
	// {
	// 	i = 0;
	// 	y = meio_y + (20*j);
	// 	while (i < 18)
	// 	{
	// 		x = (i*20) + meio_x;
	// 		xk = x + 20;
	// 		if (fdf.matrix[j][i] == fdf.matrix[j][i+1])
	// 		{
	// 			cord = get_bresendata(x, y, xk, y);
	// 			bresen_alg(&(mlx_data.img), cord);
	// 		}
	// 		i++;
	// 	}
	// 	j++;
	// }
	plot_lines(mlx_data, fdf);
	ft_printf("xxxxxxxxxxxxxxxxxxxxx");
	i = 0;
	j = 0;
	while (j < 19)
	{
		i = 0;
		y = meio_x + (20*j);
		while (i < fdf.num_rows - 1)
		{
			x = (i*20) + meio_y;
			xk = x + 20;
			if (fdf.matrix[i][j] == fdf.matrix[i+1][j])
			{
				cord = get_bresendata(y, x, y, xk);
				bresen_alg(&(mlx_data.img), cord);	
			}
			i++;
		}
		j++;
	}
	//cord = get_bresendata(X, Y, XK, YK); // pega os (x, y) (x, y) pra formatar
	//bresen_alg(&img, cord); // plota formatado
	// while (x < 50)
	// {
	// 	y = 5 * x + 58;
	// 	my_mlx_pixel_put(&img, x, y, 0X00FF0000);
	// 	x++;
	// }
	mlx_put_image_to_window(mlx_data.mlx, mlx_data.mlx_win, mlx_data.img.img, 0, 0);
	mlx_key_hook(mlx_data.mlx_win, &exit_win, &mlx_data);
	mlx_loop(mlx_data.mlx);
	mlx_destroy_display(mlx_data.mlx);
	free(mlx_data.mlx);
	clean_matrix((void **) fdf.matrix);
	clean_matrix((void **) fdf.map);
}

