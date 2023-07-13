/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:50:25 by admin             #+#    #+#             */
/*   Updated: 2023/07/12 20:58:58 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	run_game(char *file)
{
	t_game	sl;

	ft_bzero(&sl, sizeof(t_game));
	read_map(&sl, file);
	validate_map(&sl);
	launch_mlx(&sl, sl.map);
	load_assets(&sl);
	render_map(&sl, sl.map);
	mlx_hook(sl.display.win, ON_KEYPRESS, KEYPRESS_MASK, check_key, &sl);
	mlx_hook(sl.display.win, ON_CLOSE, CLOSE_MASK, quit_game, &sl);
	mlx_loop_hook(sl.display.mlx, render_move, &sl);
	mlx_loop(sl.display.mlx);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		exit_error(NULL, "Invalid number of arguments.");
	check_file(av[1]);
	run_game(av[1]);
}