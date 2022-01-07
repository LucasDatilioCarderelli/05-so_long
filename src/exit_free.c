/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:13:34 by ldatilio          #+#    #+#             */
/*   Updated: 2022/01/07 20:44:58 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	mlx_destroy_image(game->vars.mlx, game->exit.img);
	mlx_destroy_image(game->vars.mlx, game->coins.img);
	mlx_destroy_image(game->vars.mlx, game->hero.img);
	mlx_destroy_window(game->vars.mlx, game->vars.win);
	mlx_destroy_display(game->vars.mlx);
	free(game->vars.mlx);
}
