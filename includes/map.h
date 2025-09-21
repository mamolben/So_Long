/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimoli <marimoli@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:23:41 by marimoli          #+#    #+#             */
/*   Updated: 2025/05/20 18:38:17 by marimoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

int		count_lines(char **map_array);
char	**load_map(int fd, t_game *game);
char	*read_map_to_str(int fd);

#endif
