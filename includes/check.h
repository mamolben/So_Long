/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimoli <marimoli@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:37:54 by marimoli          #+#    #+#             */
/*   Updated: 2025/06/14 11:43:28 by marimoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

//Estructura del mapa
int		check_map_rectangle(char **map);
void	validate_map_row_length(t_game *game);
int		validate_map_structure(t_game *game);
//Marco del mapa
int		map_enclosed(t_game *game);
void	check_wall_error(t_game *game);
//Validaciones del mapa
void	check_map_content_errors(t_game *game);
int		validate_map_content(t_game *game);
int		check_layout(t_game *game);
int		check_all_coins_and_exit(t_game *game);
// Algoritmo DFS para validar camino
void	free_visited(int **visited, int height);
int		**init_visited_matrix(t_game *game);
int		is_valid_move(int x, int y, t_game *game);
void	dfs(int x, int y, t_game *game);
void	count_map_elements(t_game *game);
//Comprobación de jugador y salida
int		check_exit_and_player(char **map);
int		check_player_way(t_game *game);

#endif
