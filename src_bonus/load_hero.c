/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_hero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldatilio <ldatilio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:37:59 by mjose-ye          #+#    #+#             */
/*   Updated: 2022/01/07 12:38:06 by ldatilio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	load_hero(t_game *game)
{
	game->hero_right.img = mlx_xpm_file_to_image(game->vars.mlx, \
	HERO_R, &game->hero_right.width, \
	&game->hero_right.height);
	game->hero_left.img = mlx_xpm_file_to_image(game->vars.mlx, \
	HERO_L, &game->hero_left.width, \
	&game->hero_left.height);
	game->hero_up.img = mlx_xpm_file_to_image(game->vars.mlx, \
	HERO_U, &game->hero_up.width, \
	&game->hero_up.height);
	game->hero_down.img = mlx_xpm_file_to_image(game->vars.mlx, \
	HERO_D, &game->hero_down.width, \
	&game->hero_down.height);
}
