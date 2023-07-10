/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crocha-s <crocha-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:39:41 by crocha-s          #+#    #+#             */
/*   Updated: 2023/07/10 17:48:12 by crocha-s         ###   ########.fr       */
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
	so_long->sp[S1].img = mlx_xpm_file_to_image(so_long->display.mlx, FS1, &(so_long->sp[W1].width), &(so_long->sp[S1].height));
	so_long->sp[C1].img = mlx_xpm_file_to_image(so_long->display.mlx, FC1, &(so_long->sp[W1].width), &(so_long->sp[C1].height));
	so_long->sp[E1].img = mlx_xpm_file_to_image(so_long->display.mlx, FE1, &(so_long->sp[W1].width), &(so_long->sp[E1].height));
	so_long->sp[P1].img = mlx_xpm_file_to_image(so_long->display.mlx, FP1, &(so_long->sp[W1].width), &(so_long->sp[P1].height));
}

int render_move(t_game *so_long)
{
	if(!check_move(so_long))
		return (0);
	//put terminal outputs for the moves
	if(get_tile(so_long, so_long->next) == COIN)
		so_long->coins++;
	else if(get_tile(so_long, so_long->next) == EXIT && so_long->coins == so_long->map->coins)
		quit_game(so_long);
	move_player(so_long, so_long->map):
	return (0);
	
}