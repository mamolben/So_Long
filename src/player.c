/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimoli <marimoli@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:39:10 by marimoli          #+#    #+#             */
/*   Updated: 2025/06/14 12:13:45 by marimoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	handle_coin(t_game *game, int x, int y)
{
	game->score++;
	game->collectibles_found--;
	game->map[y][x] = FLOOR;
	printf("Moneda recogida. Restan: %d\n", game->collectibles_found);
}

static int	handle_exit(t_game *game)
{
	if (check_all_coins_and_exit(game))
	{
		printf("¡YOUR WIN!!! %d movimientos!\n", game->player.move_count);
		exit_game(game);
	}
	else
	{
		printf("Aún faltan monedas.\n");
		return (0);
	}
	return (0);
}

int	move_player(t_game *game, int move_x, int move_y)
{
	int	new_x;
	int	new_y;

	new_x = game->player.x + move_x;
	new_y = game->player.y + move_y;
	game->step_counter++;
	game->current_frame = (game->step_counter % 2) + 1;
	if (!check_move_valid(game, new_x, new_y))
	{
		printf("Movimiento inválido\n");
		return (0);
	}
	game->player.x = new_x;
	game->player.y = new_y;
	if (game->map[new_y][new_x] == COIN)
		handle_coin(game, new_x, new_y);
	else if (game->map[new_y][new_x] == EXIT)
		return (handle_exit(game));
	game->player.move_count++;
	printf("Movimientos: %d\n", game->player.move_count);
	paint(game);
	return (1);
}
