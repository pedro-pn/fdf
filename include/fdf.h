/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 03:06:59 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/15 03:18:55 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	mod_x(int x);
void	draw_line_1(t_data *img, int x1, int y1, int xk, int yk);
void	draw_line_2(t_data *img, int x1, int y1, int xk, int yk);
void	draw_line_3(t_data *img, int x1, int y1, int xk, int yk);
void	draw_line_4(t_data *img, int x1, int y1, int xk, int yk);
void	bren_alg(t_data *img, int x1, int y1, int xk, int yk);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
#endif
