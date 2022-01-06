/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:14:21 by ldatilio          #+#    #+#             */
/*   Updated: 2022/01/06 21:18:52 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_press(int keycode, t_game *game)
{
	int	line;
	int	col;

	line = game->map.player.y;
	col = game->map.player.x;
	if (keycode == KEY_W || keycode == KEY_UP)
		line --;
	if (keycode == KEY_A || keycode == KEY_LEFT)
		col --;
	if (keycode == KEY_S || keycode == KEY_DOWN)
		line ++;
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		col ++;
	if (keycode == KEY_ESC)
		exit_click(game);
	move_hero(game, line, col);
	return (0);
}

void	move_hero(t_game *game, int line, int col)
{
	int	x;
	int	y;

	x = game->map.player.x;
	y = game->map.player.y;
	if (check_move(game, line, col) == TRUE)
	{
		if (game->map.map[line][col] == 'C')
			game->map.collectible--;
		game->map.map[y][x] = '0';
		game->map.player.y = line;
		game->map.player.x = col;
	}
	render_game(game);
}

int	check_move(t_game *game, int line, int col)
{
	if (game->map.map[line][col] == 'E' &&
		game->map.collectible == 0)
	{
		printf("\033[0;32mVICTORY!\n\033[0m");
		free_map(game);
		free_images(game);
		exit(EXIT_SUCCESS);
	}
	if (game->map.map[line][col] != 'E' &&
		game->map.map[line][col] != '1')
	{
		game->count_move++;
		printf("moves: %02d\n", game->count_move);
		return (TRUE);
	}
	else
		return (FALSE);
}
