/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:50:25 by admin             #+#    #+#             */
/*   Updated: 2023/07/15 18:30:16 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	run_game(char *file)
{
	t_game	sl;

	ft_bzero(&sl, sizeof(t_game));
	ft_printf("Done bzero\n");
	read_map(&sl, file);
	ft_printf("Done read map\n");
	validate_map(&sl);
	ft_printf("Done validate map\n");
	launch_mlx(&sl, sl.map);
	ft_printf("Done launch mlx\n");
	load_assets(&sl);
	ft_printf("Done assets\n");
	render_map(&sl, sl.map);
	ft_printf("Done rendermap\n");
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