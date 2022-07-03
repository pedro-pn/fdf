/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 03:06:59 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/07/03 14:12:21 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "color.h"
# include "keys.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>

# define SCREEN_WIDTH 1024
# define SCREEN_HEIGHT 600
# define MENU_WIDTH 200
# define ISO_ANG 0.523599
# define ISOMETRIC 1
# define ORTHOGRAPHIC 2

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

typedef struct s_plot
{
	int	x;
	int	y;
	int	xk;
	int	yk;
	int	z;
}			t_plot;

typedef struct s_fdf
{
	int		num_columns;
	int		num_rows;
	int		**matrix;
	int		**matrix_color;
	char	**map;
	int		move_x;
	int		move_y;
	int		tile_size;
	int		projection;
	float	z_factor;
	double	alpha;
	double	beta;
	double	gamma;
}			t_fdf;

typedef struct s_win_data
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	t_img	menu;
	t_fdf	fdf;
	t_mouse	mouse;
}				t_win_data;

// Bresenham's algorithm
t_bresendata	get_bresendata(t_plot p1, t_plot pk);
t_bresendata	fix_bresen(int x1, int y1, int xk, int yk);
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
void			fdf_default(t_fdf *fdf);
void			create_img(t_win_data *mlx_data);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
// Error handling functions
void			error(char *error_str);
void			check_args(int argc, char *argv[]);
// Projection
int				get_tile_size(int row, int column);
void			plot(t_win_data mlx_data, t_fdf fdf);
t_plot			get_plot(int x, int y, t_fdf fdf);
void			isometric(int *x, int *y, int z);
void			reproject(t_win_data *mlx_data);
// Projection utils
void			zoom(int key, t_win_data *mlx_data);
void			move(int key, t_win_data *mlx_data);
void			change_z(int key, t_win_data *mlx_data);
void			reset_position(t_win_data *mlx_data);
void			rotate(int key, t_win_data *mlx_data);
void			rotate_x(t_plot *p_set, t_fdf fdf);
void			rotate_y(t_plot *p_set, t_fdf fdf);
void			rotate_z(t_plot *p_set, t_fdf fdf);
void			projection_type(int key, t_win_data *mlx_data);
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
void			get_row_color(t_fdf fdf, int x, int y, t_color *color);
void			get_column_color(t_fdf fdf, int x, int y, t_color *color);
void			get_distance(t_bresendata cord, t_color *color);
int				get_color(t_color color, t_bresendata cord);
void			invert_color(t_color *color);
// Menu
void			create_menu(t_win_data *mlx_data);
void			paint_menu(t_img *menu);
// Events
void			event_hook(t_win_data *mlx_data);
int				mouse_release(int button, int x, int y, void *mlx_data);
int				mouse_press(int button, int x, int y, void *mlx_data);
int				mouse_move(int x, int y, void *mlx_data);
void			mouse_rotate(int x, int y, t_win_data *mlx_data);
void			mouse_translate(int x, int y, t_win_data *mlx_data);
int				key_press(int key, void *mlx_data);

#endif
