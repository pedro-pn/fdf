/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:19:58 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/23 14:03:11 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(char *error_str)
{
	ft_printf("%s\n", error_str);
	exit(1);
}

void	check_args(int argc, char *argv[])
{
	int	fd;

	if (argc < 2)
		error("Invalid number of arguments.");
	if (argc > 2)
		error("Too much arguments! Only one is necessary.");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error("Cannot read file.");
	close(fd);
	check_format(argv[1]);
}

void	check_format(char *file_name)
{
	int	len_fname;

	len_fname = ft_strlen(file_name);
	if ((ft_strncmp(&(file_name[len_fname - 4]), ".fdf", 4)))
		error("Invalid file format.");
}
