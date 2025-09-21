/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimoli <marimoli@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:56:30 by marimoli          #+#    #+#             */
/*   Updated: 2025/06/14 11:48:25 by marimoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_content_errors(t_game *game)
{
	if (game->player_count != 1)
		error_exit(game, "Mapa con un jugador");
	if (game->collectible < 1)
		error_exit(game, "Mapa con una moneda");
	if (game->exit_count < 1)
		error_exit(game, "Mapa con una exit");
}

int	validate_map_content(t_game *game)
{
	if (!check_exit_and_player(game->map))
		error_exit(game, "Debe tener al menos un jugador y una salida");
	if (!check_player_way(game))
		error_exit(game, "No tienes todas las monedas o no alcanzas a salir");
	check_map_content_errors(game);
	return (1);
}

int	check_layout(t_game *game)
{
	if (!game->map || !game->map[0])
		error_exit(game, "Mapa vacío o inválido");
	if (!validate_map_structure(game))
		error_exit(game, "Estructura de mapa inválida.");
	if (!map_enclosed(game))
		error_exit(game, "El mapa debe estar rodeado de paredes.");
	count_map_elements(game);
	if (!validate_map_content(game))
		error_exit(game, "Contenido del mapa inválido");
	return (1);
}

int	check_all_coins_and_exit(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == COIN)
				return (printf("se han encontrado monedas\n"), 0);
			x++;
		}
		y++;
	}
	if (game->map[game->player.y][game->player.x] == EXIT)
		return (1);
	return (0);
}
