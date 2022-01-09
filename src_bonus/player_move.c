/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:26:58 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/01/09 20:49:28 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	key_press(int keycode, t_game *game)
{
	int	line;
	int	col;

	game->map.player_side = keycode;
	line = game->map.player.y;
	col = game->map.player.x;
	if (keycode == KEY_W || keycode == KEY_UP)
		move_hero(game, --line, col);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		move_hero(game, line, --col);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		move_hero(game, ++line, col);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_hero(game, line, ++col);
	if (keycode == KEY_Q || keycode == KEY_ESC)
		exit_click(game);
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
		move_enemy(game);
		render_game(game);
	}
}

int	check_move(t_game *game, int line, int col)
{
	if (game->map.map[line][col] == 'E' &&
		game->map.collectible == 0)
		print_victory(game);
	if (game->map.map[line][col] == 'V')
		print_gameover(game);
	if (game->map.map[line][col] != 'E' &&
		game->map.map[line][col] != '1')
	{
		game->count_move++;
		return (TRUE);
	}
	else
		return (FALSE);
}

void	print_victory(t_game *game)
{
	game->count_move++;
	printf("\033[0;32m");
	printf("VICTORY!!");
	printf("\n\033[0m");
	exit_click(game);
}

void	print_gameover(t_game *game)
{
	game->count_move++;
	printf("\033[0;31m");
	printf("GAMEOVER!");
	printf("\n\033[0m");
	exit_click(game);
}
