/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:54:12 by crocha-s          #+#    #+#             */
/*   Updated: 2023/07/04 21:42:34 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void clean_tiles(char **tiles)
{
    size_t i;
    
    i = 0;
    
    if (!tiles)
        return;
    while (tiles[i])
        free (tiles[i++]);
    free (tiles);
}

void clean_map(t_map *map)
{
    if(!map)
        return;
    clean_tiles(map->tiles)
    free(map);
}

void game_wipe(t_game *so_long)
{
    if(!so_long)
        return;
    if(so_long->map)
        clean_map(so_long->map);
}

int quit_game (t_game *so_long)
{
    data_wipe(so_long);
    exit(EXIT_SUCCESS);    
}