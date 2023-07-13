/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:21:08 by crocha-s          #+#    #+#             */
/*   Updated: 2023/07/12 21:17:55 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int exit_error (t_game *so_long, char *message)
{
	clean_game(so_long);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

int	flood_fill(t_map *map, t_point curr, char **path)
{
     static t_uint coins;
	 static int exit;

	 coins = 0;
	 exit = 0;
	 
	if (path[curr.y][curr.x] == WALL)
		return (0);
	if (path[curr.y][curr.x] == COIN)
		coins++;
	if (path[curr.y][curr.x] == EXIT)
		exit = 1;
	path[curr.y][curr.x] = WALL;
	flood_fill(map,(t_point){curr.x + 1, curr.y}, path);
	flood_fill(map,(t_point){curr.x - 1, curr.y}, path);
	flood_fill(map,(t_point){curr.x, curr.y + 1}, path);
	flood_fill(map,(t_point){curr.x, curr.y - 1}, path);
	return (coins = map->coins && exit == 1);
}

void check_file (char *file)
{
	size_t i;
	
	i = ft_strlen(file);
	if(i<= 4)
	{
		exit_error(NULL, "Invalid file name!");
	}
	else if (!ft_strnstr((file + i - 4), ".ber", 4))
		exit_error(NULL, "Invalid file extension!");
}

int is_same_point(t_point a, t_point b)
{
	return (a.x == b.x && a.y == b.y);
}

t_tile get_tile(t_game *so_long, t_point p)
{
	return (so_long->map->tiles[p.y][p.x]);
}