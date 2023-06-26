/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:01:27 by admin             #+#    #+#             */
/*   Updated: 2023/06/25 17:36:16 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{ 
    t_img img;
    void *mlx_ptr;
    void *mlx_win;
    mlx_ptr = mlx_init();
    mlx_win = mlx_new_window(mlx_ptr, 680, 384, "Hello world!");
    img.img = mlx_new_image (mlx_ptr, 680, 384);
    img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
    my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
    mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 0, 0);
    mlx_loop(mlx_ptr);
}