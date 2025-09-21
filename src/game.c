/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimoli <marimoli@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:34:42 by marimoli          #+#    #+#             */
/*   Updated: 2025/05/20 23:05:42 by marimoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player_sprite(t_game *game)
{
	if (game->sprites.player)
		mlx_destroy_image(game->graphics.mlx, game->sprites.player);
	game->sprites.player = mlx_xpm_file_to_image(game->graphics.mlx,
			"textures/xpm/P.xpm", &game->tile_size, &game->tile_size);
	if (!game->sprites.player)
	{
		write(2, "Error cargando jugador sprite\n", 29);
		exit(EXIT_FAILURE);
	}
}

int	check_move_valid(t_game *game, int x, int y)
{
	char	tile;

	if (x < 0 || x >= game->width || y < 0 || y >= game->height)
		return (0);
	tile = game->map[y][x];
	if (tile == WALL)
		return (0);
	return (1);
}

void	error_exit(t_game *game, const char *msg)
{
	free_game(game);
	fprintf(stderr, "%s\n", msg);
	exit(1);
}

void	exit_game(t_game *game)
{
	free_game(game);
	printf("Saliendo del juego...\n");
	exit(0);
}
