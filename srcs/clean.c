/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:28:33 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/21 16:16:03 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	clean_matrix(void **matrix)
{
	int	matrix_index;

	matrix_index = 0;
	while (matrix[matrix_index])
	{
		free(matrix[matrix_index]);
		matrix_index++;
	}
	free(matrix);
	return (matrix_index);
}
