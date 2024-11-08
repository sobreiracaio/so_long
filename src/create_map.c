/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 19:37:12 by admin             #+#    #+#             */
/*   Updated: 2023/09/25 15:42:51 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_map	*create_map(t_uint cols, t_uint rows)
{
	t_map	*map;

	map = ft_calloc(1, sizeof (t_map));
	if (!map)
		return (NULL);
	map->tiles = ft_calloc((rows + 1), sizeof (char *));
	if (!map->tiles)
	{
		free(map);
		return (NULL);
	}
	map->cols = cols;
	map->rows = rows;
	return (map);
}

int	get_rows(t_game *so_long, char *file)
{
	int		fd;
	int		rows;
	char	*line;

	rows = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error(so_long, "Could not open file!");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		rows++;
	}
	close(fd);
	return (rows);
}

void	read_map(t_game *so_long, char *file)
{
	int		fd;
	char	*line;
	t_uint	i;

	i = -1;
	so_long->map = create_map(0, get_rows(so_long, file));
	if (!so_long->map)
		exit(1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit(1);
	while (++i < so_long->map->rows)
	{
		line = get_next_line(fd);
		if (!line)
			exit(1);
		so_long->map->tiles[i] = ft_strtrim (line, "\n");
		if (!so_long->map->tiles[i])
			exit(1);
		free(line);
	}
	close (fd);
}
