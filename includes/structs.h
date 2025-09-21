/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marimoli <marimoli@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:11:37 by marimoli          #+#    #+#             */
/*   Updated: 2025/05/20 18:36:41 by marimoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/*Const make map*/
# define PLAYER 'P'
# define COIN 'C'
# define FLOOR '0'
# define WALL '1'
# define EXIT 'E'

/*Struct player*/
typedef struct s_player
{
	int	x;
	int	y;
	int	health;
	int	move_count;
}	t_player;

/*Struct sprites (texturas/imágenes)*/
typedef struct s_sprites
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*coin;
	void	*exit;
}	t_sprites;

/*Gráficos: mlx y ventana*/
typedef struct s_graphics
{
	void	*mlx;
	void	*win;
}	t_graphics;

/* game */
typedef struct s_game
{
	t_graphics	graphics;
	t_player	player;
	t_sprites	sprites;
	void		*player_frames[3];
	int			current_frame;
	int			step_counter;	
	char		**map;
	int			width;
	int			height;	
	int			score;
	int			**visited;
	int			exit_reached;
	int			collectibles_found;
	int			collectible;
	int			player_count;
	int			exit_count;	
	int			coin_count;	
	int			tile_size;
}	t_game;

#endif //STRUCTS_H
