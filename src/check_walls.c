/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimoli <marimoli@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:05:50 by marimoli          #+#    #+#             */
/*   Updated: 2025/05/17 17:05:53 by marimoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	wall_line(char *line, int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (line[i] != WALL)
			return (0);
		i++;
	}
	return (1);
}

int	map_enclosed(t_game *game)
{
	int	width;
	int	height;
	int	i;

	width = game->width;
	height = game->height;
	if (!wall_line(game->map[0], width)
		|| !wall_line(game->map[height - 1], width))
		error_exit(game, "Error: Pared superior o inferior sin cerrar");
	i = 0;
	while (i < height)
	{
		if (!game->map[i])
			error_exit(game, "Fila nula en el mapa");
		if (game->map[i][0] != WALL || game->map[i][width - 1] != WALL)
			error_exit(game, "Pared izquierda o derecha sin cerrar");
		i++;
	}
	return (1);
}

void	check_wall_error(t_game *game)
{
	if (!map_enclosed(game))
		error_exit(game, "Mapa no esta cerrado");
}
