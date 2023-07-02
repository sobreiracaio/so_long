/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 19:18:02 by admin             #+#    #+#             */
/*   Updated: 2023/07/02 22:02:19 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H



# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"
# include "../lib/mlx/mlx_int.h"


typedef unsigned int t_uint; 
typedef struct s_map
{
    char **tiles;
    t_uint cols;
    t_uint rows;
    t_uint coins;
    t_uint exits;
    t_uint players;
    
} t_map;

typedef struct s_coords
{
    t_uint x;
    t_uint y;
    
} t_coords;

typedef struct s_graphics
{
    void *mlx;
    void *win;
    void *img;
    char *addr;
} t_graphics;

typedef struct s_sprite
{
    void *img;
    int height;
    int width;
} t_sprite;


typedef struct s_game
{
    t_map *map;
    t_coords curr;
    t_coords next;
    t_graphics display;
    t_sprite *sprite;
    t_uint coins;
    t_uint moves;
        
} t_game;



#endif