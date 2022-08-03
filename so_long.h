/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jm <jm@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:56:20 by jcoelho-          #+#    #+#             */
/*   Updated: 2022/07/25 11:56:10 by jm               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              HEADERS
*/
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>

# include "libft.h"
# include "mlx.h"

# define MLX_ERROR		1
# define MLX_SSUCCESS	0

# define WINDOW_WIDTH	500
# define WINDOW_HEIGHT	500

# define IMG_RES		32

// KEY
# define K_ESC			53
# define K_W			13
# define K_A			0
# define K_S			1
# define K_D			2
# define K_UP			126
# define K_DOWN			125
# define K_LEFT			123
# define K_RIGHT		124 

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              STRUCTURE 
*/

typedef struct s_img
{
	void		*mlx_img;
}	t_img;

typedef struct s_player
{
	int			x;
	int			y;
	int			count;
	int			img_len;
	t_img		sprite;
	int			step;
}	t_player;

typedef struct s_map
{
	char		**map;
	int			width;
	int			height;
	int			exit;
}	t_map;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_x;
	int			win_y;
	int			max_money_count;
	int			money_count;
	t_img		img;
	t_player	player;
	t_map		map;
	t_img		floor;
	t_img		exitc;
	t_img		exito;
	t_img		wall;
	t_img		money;
}	t_data;

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              FUNCTION 
*/

int		ft_close(void);
void	malloc_struct(t_data *data, int len, char **s);
void	send_error(t_data *data, char *message);

int		init_data(t_data *data);
void	init_texture(t_data *data);

int		malloc_map(t_data *data, char *path);
int		parse_map(t_data *data, char *path);
int		deal_key(int key, void *param);
void	move(t_data *data, int new_x, int new_y);

void	valid_map(t_data *data);
int		first_last(t_data *data);
int		content_map(t_data *data);
void	valid_player(t_data *data);
void	valid_money(t_data *data);
void	valid_exit(t_data *data);

void	render(t_data *data);
void	render_exito(t_data *data, int i, int j);
void	render_exitc(t_data *data, int i, int j);
void	render_floor(t_data *data, int i, int j);
void	render_player(t_data *data, int i, int j);
void	render_wall(t_data *data, int i, int j);
void	render_money(t_data *data, int i, int j);

void	finish(t_data *data);

#endif