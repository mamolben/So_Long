/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_structure.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimoli <marimoli@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 16:49:04 by marimoli          #+#    #+#             */
/*   Updated: 2025/06/14 11:46:00 by marimoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_rectangle(char **map)
{
	int	i;
	int	length;

	if (!map || !map[0])
		return (0);
	length = (int) ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != length)
			return (0);
		i++;
	}
	return (1);
}

void	validate_map_row_length(t_game *game)
{
	int		expected_len;
	int		current_len;
	int		i;
	char	msg[100];

	if (!game || !game->map || !game->map[0])
		error_exit(game, "No carga correctamente el mapa");
	expected_len = ft_strlen(game->map[0]);
	i = 1;
	while (game->map[i])
	{
		current_len = ft_strlen(game->map[i]);
		if (current_len != expected_len)
		{
			snprintf(msg, sizeof(msg),
				"Error: fila %d tiene longitud %d, de %d", i, current_len,
				expected_len);
			error_exit(game, msg);
		}
		i++;
	}
}

int	validate_map_structure(t_game *game)
{
	validate_map_row_length(game);
	if (!map_enclosed(game))
		return (0);
	return (1);
}
