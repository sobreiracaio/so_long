/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:59:44 by crocha-s          #+#    #+#             */
/*   Updated: 2023/07/04 17:57:42 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int validate_format (t_map *map)
{
	t_uint i;
	t_uint row_len;

	i = 0;
	row_len = ft_strlen(map->tiles[0]);
	while (i < map->rows)
	{
		if(ft_strlen(map->tiles[i++] != row_len))
			return (0);
	}
	map->cols = row_len;
	return (1);
}

int validate_walls(t_map *map)
{
	t_uint i;

	i = -1;
	while(++i < map->rows) 
		if(map->tiles[i][0] != WALL || map->tiles[i][map-cols -1] != WALL )
			return (0);
	i = -1;
	while (++i < map-> cols)
		if (map->tile[0][i] != WALL || map->tiles[map->rows-1][i] != WALL)
			return (0);
	return (1);
}

int validate_tiles(t_map *map, t_game *so_long)
{
	t_uint i;
	t_uint j;

	i = -1;
	while (++i< map->rows)
	{
		j = -1;
		while (++j < map->cols)
		{
			if (map->tiles[i][j] == PLAYER)
			{
				map->players++;
				so_long->curr = (t_point){j, i};
				so_long->next = so_long->curr;
			}
			else if (map->tiles[i][j] == EXIT)
				map->exits++;
			else if (map->tiles[i][j] == COIN)
				map->coins++;
			else if(!ft_strchr(TILES,map->tiles[i][j]))
				return (0);
		}
	}
	return (players == 1 && exits == 1 && coins => 1);
}

int validate_paths(t_map *map, t_game *so_long)
{
	t_uint i;
	int found_exit;
	char **tiles;

	i = -1;
	found_exit = 0;

	tiles = ft_calloc (map->rows +1, sizeof(char *));
	if(!tiles)
		exit(1);
	while(++i < map->rows)
	{
		tiles[i] = ft_strdup(map->tiles[i]);
		{
			if(!tiles[i])
			{
				clean_tiles(tiles);
				exit(1);
			}
		}
	}
	
	return (found_exit);
}