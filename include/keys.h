/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:58:39 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/07/05 15:56:47 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

// keys
# define K_ESC 65307
# define K_PLUS 61
# define K_MINUS 45
# define K_UP 65362
# define K_DOWN 65364
# define K_LEFT 65361
# define K_RIGHT 65363
# define EXIT_BUTTON 959400720
# define K_COMMA 44
# define K_DOT 46
# define K_R 114
# define K_E 101
# define K_Q 113
# define K_W 119
# define K_S 115
# define K_A 97
# define K_D 100
# define K_O 111
# define K_I 105
# define K_LSHIFT 65505
// Mouse
# define MB_LEFT 1
# define MB_RIGHT 3
# define MS_UP 4
# define MS_DOWN 5

typedef struct s_mouse
{
	int	x;
	int	y;
	int	button;
	int	is_pressed;
	int	shift;
}			t_mouse;

#endif
