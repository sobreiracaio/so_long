/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:39:41 by crocha-s          #+#    #+#             */
/*   Updated: 2023/07/07 17:58:06 by crocha-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void launch_mlx (t_game *so_long, t_map *map)
{
	so_long->display.mlx = mlx.init();

	if(!so_long->display.mlx)
		exit_error(So_long, "Mlx start failed!")
	so_long->display.win = mlx_new_window(so_long->display.mlx, map->cols * SIZE, map->rows * SIZE, "so_long");
	if(!so_long->display.win)
		exit_error(so_long, "Error creating window!")
}

void load_assets(t_game *so_long)
{
	so_long->sp = malloc (SPRITES * sizeof(t_sprite));
	if(!so_long->sp)
		exit_error(so_long, "Failed to allocate sprites on memory!")
	so_long->sp[W1].img = mlx_xpm_file_to_image(so_long->display.mlx, FW1, &(so_long->sp[W1].width), &(so_long->sp[W1].height));
}