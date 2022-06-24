/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:52:23 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/06/23 16:18:10 by ppaulo-d         ###   ########.fr       */
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

void	get_matrix(t_fdf *fdf)
{
	char	**row_splitted;
	int		row;
	int		column;

	fdf->matrix = malloc(sizeof(int *) * (fdf->num_rows + 1));
	fdf->matrix[fdf->num_rows] = NULL;
	row = 0;
	while (row < fdf->num_rows)
	{
		column = 0;
		row_splitted = ft_split(fdf->map[row], ' ');
		get_matrix_color(fdf, row_splitted, row);
		fdf->matrix[row] = malloc(sizeof(int) * fdf->num_columns);
		while (row_splitted[column])
		{
			fdf->matrix[row][column] = ft_atoi(row_splitted[column]);
			free(row_splitted[column]);
			column++;
		}
		free(row_splitted);
		row++;
	}
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
