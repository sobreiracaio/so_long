/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:22:08 by crocha-s          #+#    #+#             */
/*   Updated: 2023/07/10 18:05:46 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_move (t_game *so_long)
{
	return((!is_same_point(so_long->curr, so_long->next) && get_tile(s_long, so_long->next)) != WALL); 	
}

void move_player(t_game *s1, t_map *map)
{
	static t_tile previous;
	previous = SPACE;
	
	map->tiles[s1->curr.y][s1->curr.x] = previous;
	if (get_tile(s1,s1->next) != COIN)
		previous = map->tiles[s1->next.y][s11->next.x];
	else
		previous = SPACE;
	map->tiles[s1->next.y][s1->next.x] = PLAYER;
	render_tile(sl, (t_point){sl->curr.x, sl->curr.y});
	render_tile(sl, (t_point){sl->next.x, sl->next.y});
	sl->curr = sl->next;
	
}