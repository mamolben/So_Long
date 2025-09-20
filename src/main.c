/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimoli <marimoli@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:03:14 by marimoli          #+#    #+#             */
/*   Updated: 2025/03/29 20:04:36 by marimoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game_map(t_game *game, int argc, char **argv)
{
	int		fd;
	size_t	length;

	if (argc != 2)
		error_exit(game, "Usage: ./so_long <map_file>");
	length = ft_strlen(argv[1]);
	if (length < 4 || ft_strncmp(argv[1] + length - 4, ".ber", 4) != 0)
		error_exit(game, "Error: Mapa con extensión .ber");
	fd = open(argv[1], O_RDONLY, 777);
	if (fd == -1)
		error_exit(game, "Error abriendo archivo");
	game->map = load_map(fd, game);
	close(fd);
	if (!game->map)
		error_exit(game, "Error cargando mapa");
	if (!game->width || !game->height)
		error_exit(game, "Dimensiones inválidas");
}

void	init_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == PLAYER)
			{
				game->player.x = x;
				game->player.y = y;
				game->player.move_count = 0;
				return ;
			}
			x++;
		}
		y++;
	}
	free_split(game->map);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	init_game_map(&game, argc, argv);
	init_player(&game);
	printf("width=%d height=%d\n", game.width, game.height);
	if (!check_layout(&game))
		error_exit(&game, "Error layout");
	game.tile_size = 64;
	game.graphics.mlx = mlx_init();
	if (!game.graphics.mlx)
		error_exit(&game, "Error inicializando MLX");
	game.graphics.win = mlx_new_window(game.graphics.mlx, game.width
			* game.tile_size, game.height * game.tile_size, "So Long");
	load_textures(&game);
	update_player_sprite(&game);
	paint(&game);
	mlx_loop_hook(game.graphics.mlx, main_loop, &game);
	mlx_key_hook(game.graphics.win, key_control, &game);
	mlx_loop(game.graphics.mlx);
	return (0);
}
