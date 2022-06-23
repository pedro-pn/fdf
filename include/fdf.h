/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 03:06:59 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/23 11:56:29 by ppaulo-d         ###   ########.fr       */
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
# define SCREEN_LENGTH 768

# ifndef X
#  define X 0
# endif

# ifndef Y
#  define Y 0
# endif

# ifndef XK
#  define XK 60
# endif

# ifndef YK
#  define YK 40
# endif

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		color;
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
}			t_fdf;

typedef struct s_win_data
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	t_fdf	fdf;
}				t_win_data;

int				mod_x(int x);
void			draw_line_1(t_img *img, t_bresendata cord);
void			draw_line_2(t_img *img, t_bresendata cord);
void			draw_line_3(t_img *img, t_bresendata cord);
void			draw_line_4(t_img *img, t_bresendata cord);
void			bresen_alg(t_img *img, t_bresendata cord);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
t_bresendata	get_bresendata(int x1, int y1, int xk, int yk);
void			get_matrix(t_fdf *fdf);
int				count_lines(char *file_name);
char			**fill_map(char *file_name, int lines);
int				exit_win(void *mlx_data);
int				get_rows(char **splitted_line);
void			clean_matrix(void **matrix);
void			plot_iso(t_win_data mlx_data, t_fdf fdf);
void			plot_rows_iso(t_win_data mlx_data, t_fdf fdf);
void			get_start_pixels(t_fdf *fdf);
void			plot_columns_iso(t_win_data mlx_data, t_fdf fdf, t_iso *iso);
int				get_columns_matrix(char **map);
void			check_args(int argc, char *argv[]);
void			error(char *error_str);
void			check_format(char *file_name);
void			fdf_init(t_fdf *fdf, char *file_name);
void			mlx_start(t_win_data *mlx_data);
int				get_tile_size(int row, int column);
int				htoi(char *hptr);
void			get_matrix_color(t_fdf *fdf, char **row_splt, int row);
int				key_handle(int key, void *mlx_data);
void			clean_program(t_win_data *mlx_data, t_fdf *fdf);
void			create_img(t_win_data *mlx_data);
void			zoom(int key, t_win_data *mlx_data);
void			move(int key, t_win_data *mlx_data);

#endif
