/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:44:27 by admin             #+#    #+#             */
/*   Updated: 2023/06/25 17:32:12 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//# include <mlx.h>
# include "../lib/mlx/mlx.h"

typedef struct s_img
{
    void *img;
    char * addr;
    int bpp;
    int line_len;
    int endian;
} t_img;

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);

#endif