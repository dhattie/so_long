/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:29:36 by dhattie           #+#    #+#             */
/*   Updated: 2021/12/04 18:29:40 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Dayna Hattie on 12/4/21.
//

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h> /** read, close, write*/
# include <fcntl.h> /** open, free */
# include <stdlib.h> /** malloc, free, exit*/
# include <stdio.h> /** printf, perror */
# include <string.h> /** strerror */
# include "../Libft/libft.h"
# include "../minilibx_mms/mlx.h"

typedef struct s_list
{
	void			*img;
	char			*title;
	struct s_list	*next;
}	t_img;

typedef struct s_key
{
	int			i;
	int			j;
	int			collections;
	int			status;
	int			status_step;
	int			steps;
	int			size_img;
	char		player_on_exit;
	void		*mlx;
	void		*mlx_win;
	t_img		*head;
	char		**map_array;
}				t_button;

/** key controls */
# define KEY_ESC			53
# define KEY_A				0
# define KEY_W				13
# define KEY_D				2
# define KEY_S				1

/** mouse controls */
# define X_EVENT_KEY_PRESS	2
# define X_EVENT_MOUSE_EXIT	17

/** functions */
int		map_open(char *argv); /** map_check_access */
void	ft_change_foe_img(t_button *p);
void	ft_game_status(t_button *p);
void	ft_move_player(t_button *p, int temp_i, int temp_j);
void	ft_init_img_map(t_button *key, void *mlx, void *mlx_win, t_img *head);
int		key_pressed(int keycode, t_button *player);
int		check_map_array(char **map_array, int number_lines, int number_columns);
void	push_object_list(t_img **head, char *title, void *img);
void	*ft_get_list_img(t_img *head, char *tittle);
void	ft_put_img_window(void *mlx, void *mlx_win, t_img *head, char **map_ar);
void	*ft_push_mlx_img_list(void *mlx, t_img **head);
void	map_extension_check(char *argv);
char	**map_push_array(int fd, int map_size);
size_t	map_number_lines(int fd);
void	map_arg_check(int fd);
void	ft_move_img(t_button *p, void *img, int x, int y);
void	ft_print_img_txt(t_button *p, int m_sz);
void	*ft_new_window(void *mlx, char **map_array);
int		mouse_esc(t_button *player);
void	ft_check_player(char **map_array);
void	ft_init_player(t_button *key);
void	ft_init_collections(t_button *key);

#endif