/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:16:47 by ldatilio          #+#    #+#             */
/*   Updated: 2022/01/06 19:27:11 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	render_game(t_game *game)
{
	render_map(game);
	mlx_put_image_to_window(
		game->vars.mlx, game->vars.win, game->hero.img,
		game->map.player.x * 30, game->map.player.y * 30);
	return (0);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == '0')
				mlx_put_image_to_window(game->vars.mlx, game->vars.win,
					game->floor.img, x * 30, y * 30);
			if (game->map.map[y][x] == '1')
				mlx_put_image_to_window(game->vars.mlx, game->vars.win,
					game->wall.img, x * 30, y * 30);
			if (game->map.map[y][x] == 'C')
				mlx_put_image_to_window(game->vars.mlx, game->vars.win,
					game->coins.img, x * 30, y * 30);
			if (game->map.map[y][x] == 'E')
				mlx_put_image_to_window(game->vars.mlx, game->vars.win,
					game->exit.img, x * 30, y * 30);
			x++;
		}
		y++;
	}
}
