/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimoli <marimoli@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:45:38 by marimoli          #+#    #+#             */
/*   Updated: 2025/06/14 11:47:18 by marimoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char **map_array)
{
	int	i;

	i = 0;
	while (map_array[i])
		i++;
	return (i);
}

static char	*add_buffer_to_map_str(char *map_str, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(map_str, buffer);
	free(map_str);
	return (tmp);
}

char	*read_map_to_str(int fd)
{
	char	buffer[1024 + 1];
	char	*map_str;
	int		bytes;

	map_str = malloc(1);
	if (!map_str)
		return (NULL);
	map_str[0] = '\0';
	bytes = read(fd, buffer, 1024);
	while (bytes > 0)
	{
		buffer[bytes] = '\0';
		map_str = add_buffer_to_map_str(map_str, buffer);
		if (!map_str)
			return (NULL);
		bytes = read(fd, buffer, 1024);
	}
	if (bytes < 0)
	{
		return (free(map_str), NULL);
	}
	return (map_str);
}

char	**load_map(int fd, t_game *game)
{
	char	*map_str;
	char	**map_array;

	map_str = read_map_to_str(fd);
	if (!map_str)
		error_exit(game, "Mapa vacio");
	map_array = ft_split(map_str, '\n');
	free(map_str);
	if (!map_array || !map_array[0])
		error_exit(game, "Mapa vacio en fila");
	game->height = count_lines(map_array);
	game->width = ft_strlen(map_array[0]);
	game->map = map_array;
	count_map_elements(game);
	return (map_array);
}
