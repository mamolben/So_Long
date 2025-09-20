/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimoli <marimoli@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:29:32 by marimoli          #+#    #+#             */
/*   Updated: 2025/09/20 16:30:10 by marimoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_player_frames(t_game *game)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (game->player_frames[i])
			mlx_destroy_image(game->graphics.mlx, game->player_frames[i]);
		i++;
	}
}

void	free_images(t_game *game)
{
	if (game->sprites.player)
		mlx_destroy_image(game->graphics.mlx, game->sprites.player);
	if (game->sprites.floor)
		mlx_destroy_image(game->graphics.mlx, game->sprites.floor);
	if (game->sprites.wall)
		mlx_destroy_image(game->graphics.mlx, game->sprites.wall);
	if (game->sprites.coin)
		mlx_destroy_image(game->graphics.mlx, game->sprites.coin);
	if (game->sprites.exit)
		mlx_destroy_image(game->graphics.mlx, game->sprites.exit);
	free_player_frames(game);
}
