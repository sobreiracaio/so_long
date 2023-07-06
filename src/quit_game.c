/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:54:12 by crocha-s          #+#    #+#             */
/*   Updated: 2023/07/06 17:44:01 by crocha-s         ###   ########.fr       */
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
    game_wipe(so_long);
    exit(EXIT_SUCCESS);    
}