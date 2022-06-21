/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:52:23 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/21 16:14:49 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**fill_map(char *file_name, int lines)
{
	char	**map;
	int		fd;
	int		map_index;

	if (lines > 0)
		map = malloc(sizeof(*map) * (lines + 1));
	else
		return (NULL);
	if (!map)
		return (NULL);
	map_index = 0;
	fd = open(file_name, O_RDONLY);
	while (map_index <= lines)
	{
		map[map_index] = get_next_line(fd);
		map_index++;
	}
	close(fd);
	return (map);
}

int	count_lines(char *file_name)
{
	char	*line;
	int		fd;
	int		num_lines;

	fd = open(file_name, O_RDONLY);
	num_lines = 0;
	line = get_next_line(fd);
	while (line)
	{
		num_lines++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (num_lines);
}

int	get_rows(char **splitted_line)
{
	int	index;

	index = 0;
	while (splitted_line[index])
	{
		index++;
	}
	return (index);
}

int	**get_matrix(char **map, int num_lines)
{
	int		**matrix;
	char	**line_splitted;
	int		map_index;
	int		matrix_row;

	matrix = malloc(sizeof(*matrix) * (num_lines + 1));
	matrix[num_lines] = NULL;
	map_index = 0;
	while (map_index < num_lines)
	{
		matrix_row = 0;
		line_splitted = ft_split(map[map_index], ' ');
		matrix[map_index] = malloc(sizeof(**matrix) * get_rows(line_splitted));
		while (line_splitted[matrix_row])
		{
			matrix[map_index][matrix_row] = ft_atoi(line_splitted[matrix_row]);
			free(line_splitted[matrix_row]);
			matrix_row++;
		}
		free(line_splitted);
		map_index++;
	}
	return (matrix);
}

int	get_columns_matrix(char **map)
{
	int		i;
	char	**splitted;

	i = 0;
	splitted = ft_split(map[0], ' ');
	while (splitted[i])
		i++;
	clean_matrix((void **) splitted);
	return (i);
}
