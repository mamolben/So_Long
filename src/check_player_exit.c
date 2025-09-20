/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimoli <marimoli@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:22:13 by marimoli          #+#    #+#             */
/*   Updated: 2025/05/17 17:22:17 by marimoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_exit_and_player(char **map)
{
	int	player;
	int	exit;
	int	i;
	int	j;

	player = 0;
	exit = 0;
	i = 0;
	if (map && map[0])
	{
		while (map[i])
		{
			j = 0;
			while (map[i][j])
			{
				if (map[i][j] == 'P')
					player = 1;
				if (map[i][j] == 'E')
					exit = 1;
				j++;
			}
			i++;
		}
	}
	return (player && exit);
}

int	check_player_way(t_game *game)
{
	game->visited = init_visited_matrix(game);
	if (!game->visited)
		return (0);
	game->exit_reached = 0;
	game->collectibles_found = 0;
	dfs(game->player.x, game->player.y, game);
	free_visited(game->visited, game->height);
	if (game->exit_reached && game->collectibles_found == game->collectible)
		return (1);
	return (0);
}
