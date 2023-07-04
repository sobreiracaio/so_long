/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 16:59:44 by crocha-s          #+#    #+#             */
/*   Updated: 2023/07/03 21:31:36 by admin            ###   ########.fr       */
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

int validate_tiles()
