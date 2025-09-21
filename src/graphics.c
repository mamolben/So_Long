/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimoli <marimoli@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:47:06 by marimoli          #+#    #+#             */
/*   Updated: 2025/03/22 17:47:09 by marimoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_frame(t_game *game)
{
	int	size;

	size = game->tile_size;
	game->player_frames[0] = mlx_xpm_file_to_image(game->graphics.mlx,
			"textures/xpm/P.xpm", &size, &size);
	game->player_frames[1] = mlx_xpm_file_to_image(game->graphics.mlx,
			"textures/xpm/P1.xpm", &size, &size);
	game->player_frames[2] = mlx_xpm_file_to_image(game->graphics.mlx,
			"textures/xpm/P2.xpm", &size, &size);
}

void	load_textures(t_game *game)
{
	int	size;

	size = game->tile_size;
	game->sprites.player = mlx_xpm_file_to_image(game->graphics.mlx,
			"textures/xpm/P.xpm", &size, &size);
	game->sprites.floor = mlx_xpm_file_to_image(game->graphics.mlx,
			"textures/xpm/0.xpm", &size, &size);
	game->sprites.wall = mlx_xpm_file_to_image(game->graphics.mlx,
			"textures/xpm/1.xpm", &size, &size);
	game->sprites.coin = mlx_xpm_file_to_image(game->graphics.mlx,
			"textures/xpm/C.xpm", &size, &size);
	game->sprites.exit = mlx_xpm_file_to_image(game->graphics.mlx,
			"textures/xpm/E.xpm", &size, &size);
	move_frame(game);
	if (!game->sprites.player || !game->sprites.floor || !game->sprites.wall
		|| !game->sprites.coin || !game->sprites.exit)
		error_exit(game, "Error cargando sprites");
}

static void	put_tile(t_game *game, int x, int y, char tile)
{
	void	*img;

	img = NULL;
	if (tile == WALL)
		img = game->sprites.wall;
	if (tile == FLOOR || tile == PLAYER)
		img = game->sprites.floor;
	if (game->player.x == x && game->player.y == y)
		img = game->sprites.player;
	if (tile == COIN)
		img = game->sprites.coin;
	if (tile == EXIT)
		img = game->sprites.exit;
	if (img)
		mlx_put_image_to_window(game->graphics.mlx, game->graphics.win,
			img, x * game->tile_size, y * game->tile_size);
}

void	paint(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			put_tile(game, x, y, game->map[y][x]);
			x++;
		}
		y++;
	}
}

int	main_loop(t_game *game)
{
	paint(game);
	return (0);
}
