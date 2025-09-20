/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimoli <marimoli@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 22:06:48 by marimoli          #+#    #+#             */
/*   Updated: 2025/09/20 16:22:43 by marimoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#ifdef _linux_	

void	destroy_linux_display(t_game *game)
{
	mlx_destroy_display(game->graphics.mlx);
	free(game->graphics.mlx);
}
#else

void	destroy_linux_display(t_game *game)
{
	(void)game;
}
#endif

void	free_map_resources(t_game *game)
{
	if (game->map)
		free_split(game->map);
}

void	free_graphics_resources(t_game *game)
{
	if (game->graphics.mlx)
	{
		free_images(game);
		if (game->graphics.win)
			mlx_destroy_window(game->graphics.mlx, game->graphics.win);
		destroy_linux_display(game);
	}
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	free_map_resources(game);
	free_graphics_resources(game);
}
