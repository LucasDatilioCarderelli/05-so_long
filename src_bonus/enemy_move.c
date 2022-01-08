/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:37:59 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/01/09 00:17:13 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ai_enemy_move(t_game *game, int x, int y);
int	check_enemy(char future_position);

void	move_enemy(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'V')
			{
				if (ai_enemy_move(game, x, y))
				{
					x++;
					y++;
				}
			}
			x++;
		}
		y++;
	}
}

int	ai_enemy_move(t_game *game, int x, int y)
{
	if (check_enemy(game->map.map[y + 1][x]) && game->map.player.y > y)
	{
		game->map.map[++y][x] = 'V';
		game->map.map[y - 1][x] = '0';
	}
	else if (check_enemy(game->map.map[y][x + 1]) && game->map.player.x > x)
	{
		game->map.map[y][++x] = 'V';
		game->map.map[y][x - 1] = '0';
	}
	else if (check_enemy(game->map.map[y - 1][x]) && game->map.player.y < y)
	{
		game->map.map[--y][x] = 'V';
		game->map.map[y + 1][x] = '0';
	}
	else if (check_enemy(game->map.map[y][x - 1]) && game->map.player.x < x)
	{
		game->map.map[y][--x] = 'V';
		game->map.map[y][x + 1] = '0';
	}
	else
		return (0);
	return (1);
}

int	check_enemy(char future_position)
{
	if (future_position != '1' && future_position != 'V' && \
	future_position != 'E' && future_position != 'C')
		return (TRUE);
	return (FALSE);
}
