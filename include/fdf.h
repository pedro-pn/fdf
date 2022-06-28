/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 03:06:59 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/28 13:04:52 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "keys.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define SCREEN_WIDTH 1024
# define SCREEN_HEIGHT 600
# define SCREEN_COLOR 0X001C1522
# define ISO_ANG 0.463646716

typedef struct s_color
{
	int		color;
	int		color_end;
	int		start_point;
	double	distance;
}			t_color;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_color	color;
}				t_img;

typedef struct s_bresendata
{
	int	x1;
	int	y1;
	int	xk;
	int	yk;
	int	dx;
	int	dy;
}			t_bresendata;

typedef struct s_iso
{
	int	row;
	int	column;
	int	x;
	int	y;
	int	xk;
	int	yk;
	int	first_x;
	int	first_y;
}			t_iso;

typedef struct s_fdf
{
	int		num_columns;
	int		num_rows;
	int		**matrix;
	int		**matrix_color;
	char	**map;
	int		start_x;
	int		start_y;
	int		tile_size;
	int		z_factor;
}			t_fdf;

typedef struct s_win_data
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	t_fdf	fdf;
}				t_win_data;

// Bresenham's algorithm
t_bresendata	get_bresendata(int x1, int y1, int xk, int yk);
void			bresen_alg(t_img *img, t_bresendata cord);
void			draw_line_1(t_img *img, t_bresendata cord);
void			draw_line_2(t_img *img, t_bresendata cord);
void			draw_line_3(t_img *img, t_bresendata cord);
void			draw_line_4(t_img *img, t_bresendata cord);
// Read file and build matrix
int				count_lines(char *file_name);
int				get_columns_matrix(char **map);
char			**fill_map(char *file_name, int lines);
void			get_matrix(t_fdf *fdf);
// Create window and image
void			mlx_start(t_win_data *mlx_data);
void			fdf_init(t_fdf *fdf, char *file_name);
void			create_img(t_win_data *mlx_data);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
// Error handling functions
void			error(char *error_str);
void			check_args(int argc, char *argv[]);
void			check_format(char *file_name);
// Isometric projection
void			get_start_pixels(t_fdf *fdf);
int				get_tile_size(int row, int column);
void			plot_iso(t_win_data mlx_data, t_fdf fdf);
void			plot_rows_iso(t_win_data mlx_data, t_fdf fdf);
void			plot_columns_iso(t_win_data mlx_data, t_fdf fdf, t_iso *iso);
// Projection Movements
void			zoom(int key, t_win_data *mlx_data);
void			move(int key, t_win_data *mlx_data);
void			change_z(int key, t_win_data *mlx_data);
// Clean memory and exit program
int				exit_win(void *mlx_data);
void			clean_matrix(void **matrix);
void			clean_program(t_win_data *mlx_data, t_fdf *fdf);
// Utils
int				htoi(char *hptr);
int				mod(int n);
//color
void			paint_image(t_img *img);
void			get_matrix_color(t_fdf *fdf, char **row_splt, int row);
void			get_row_color(t_fdf fdf, t_iso iso, t_color *color);
void			get_column_color(t_fdf fdf, t_iso iso, t_color *color);
void			get_distance(t_bresendata cord, t_color *color);
int				get_color(t_color color, t_bresendata cord);

#endif
