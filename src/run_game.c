/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:50:25 by admin             #+#    #+#             */
/*   Updated: 2023/07/18 19:18:01 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	run_game(char *file)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	ft_printf("Done bzero\n");
	read_map(&game, file);
	ft_printf("Done read map\n");
	validate_map(&game);
	ft_printf("Done validate map\n");
	launch_mlx(&game, game.map);
	ft_printf("Done launch mlx\n");
	load_assets(&game);
	ft_printf("Done assets\n");
	render_map(&game, game.map);
	ft_printf("Done rendermap\n");
	mlx_hook(game.display.win, ON_KEYPRESS, KEYPRESS_MASK, check_key, &game);
	mlx_hook(game.display.win, ON_CLOSE, CLOSE_MASK, quit_game, &game);
	mlx_loop_hook(game.display.mlx, render_move, &game);
	mlx_loop(game.display.mlx);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		exit_error(NULL, "Invalid number of arguments.");
	check_file(av[1]);
	run_game(av[1]);
}