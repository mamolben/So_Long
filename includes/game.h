/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimoli <marimoli@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:24:07 by marimoli          #+#    #+#             */
/*   Updated: 2025/06/14 11:44:01 by marimoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "so_long.h"

void	free_game(t_game *game);
void    free_grapics_resources(t_game *game);
void    free_map_resources(t_game *game);
void    free_images(t_game *game);
void    destroy_linux_display(t_game *game);
void	update_player_sprite(t_game *game);
int		check_move_valid(t_game *game, int x, int y);
void	error_exit(t_game *game, const char *msg);
void	exit_game(t_game *game);

#endif
