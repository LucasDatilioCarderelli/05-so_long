/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:26:37 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/01/19 01:28:07 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	exit_error(char *s)
{
	printf("\033[0;31m");
	printf("Error:\n%s", s);
	printf("\n\033[0m");
	exit(EXIT_FAILURE);
}

int	exit_click(t_game *game)
{
	printf("Moves: %d\n", game->count_move);
	free_map(game);
	free_images(game);
	exit(1);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.count_line)
	{
		free(game->map.map[i]);
		i++;
	}
	free(game->map.map);
	game->map.map = NULL;
}

void	free_images(t_game *game)
{
	mlx_clear_window(game->vars.mlx, game->vars.win);
	mlx_loop_end(game->vars.mlx);
	mlx_destroy_image(game->vars.mlx, game->wall.img);
	mlx_destroy_image(game->vars.mlx, game->floor.img);
	mlx_destroy_image(game->vars.mlx, game->exit_close.img);
	mlx_destroy_image(game->vars.mlx, game->exit_open.img);
	mlx_destroy_image(game->vars.mlx, game->coins.img);
	mlx_destroy_image(game->vars.mlx, game->hero_right.img);
	mlx_destroy_image(game->vars.mlx, game->hero_left.img);
	mlx_destroy_image(game->vars.mlx, game->hero_up.img);
	mlx_destroy_image(game->vars.mlx, game->hero_down.img);
	mlx_destroy_image(game->vars.mlx, game->enemy_ld.img);
	mlx_destroy_image(game->vars.mlx, game->enemy_lu.img);
	mlx_destroy_image(game->vars.mlx, game->enemy_rd.img);
	mlx_destroy_image(game->vars.mlx, game->enemy_ru.img);
	mlx_destroy_window(game->vars.mlx, game->vars.win);
	mlx_destroy_display(game->vars.mlx);
	free(game->vars.mlx);
}
