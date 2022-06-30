/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:58:39 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/29 21:51:24 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

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

int	key_handle(int key, void *mlx_data);

#endif
