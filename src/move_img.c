/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 17:31:34 by dhattie           #+#    #+#             */
/*   Updated: 2021/12/26 17:31:39 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_move_img(t_button *p, void *img, int x, int y)
{
	mlx_put_image_to_window(p->mlx, p->mlx_win, img, x, y);
}

int	mouse_esc(t_button *player)
{
	printf("You are close the game\n");
	if (player->mlx)
	{
		mlx_destroy_window(player->mlx, player->mlx_win);
		player->mlx_win = NULL;
	}
	exit(0);
}

void	ft_check_player(char **map_array)
{
	int		i;
	int		j;
	int		player;

	player = 0;
	i = -1;
	while (map_array[++i])
	{
		j = -1;
		while (map_array[i][++j])
		{
			if (ft_strchr(&map_array[i][++j], 'P'))
				player++;
		}
	}
	if (player > 1)
	{
		printf("Error\n The player must be alone \n");
		exit(0);
	}
}

void	ft_init_player(t_button *key)
{
	int		i;
	int		j;

	i = -1;
	while (key->map_array[++i])
	{
		j = -1;
		while (key->map_array[i][++j])
		{
			if (key->map_array[i][j] == 80)
			{
				key->i = j;
				key->j = i;
				break ;
			}
		}
	}
}

void	ft_init_collections(t_button *key)
{
	int		i;
	int		j;
	int		collections;

	collections = 0;
	i = -1;
	while (key->map_array[++i])
	{
		j = -1;
		while (key->map_array[i][++j])
		{
			if (key->map_array[i][j] == 'C')
				collections++;
		}
	}
	key->collections = collections;
}
