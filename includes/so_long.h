/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimoli <marimoli@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 18:20:21 by marimoli          #+#    #+#             */
/*   Updated: 2025/05/20 18:30:36 by marimoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*Librerias del sistema*/
# include <unistd.h> //write
# include <stdlib.h> //EXIT_SUCCESS, malloc,
# include <fcntl.h> //open, O_RDONLY
# include <stdio.h> //printf, perror
# include <X11/X.h> //keycode
# include <X11/keysym.h> //keycode
/*Minilibx*/
# include "mlx.h"
/*Headers del Proyecto*/
# include "structs.h"
# include "utils.h"
# include "check.h"
# include "map.h"
# include "player.h"
# include "graphics.h"
# include "game.h"

#endif //SO_LONG_H
