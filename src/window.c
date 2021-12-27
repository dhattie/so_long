/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:22:48 by dhattie           #+#    #+#             */
/*   Updated: 2021/12/26 16:22:50 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_change_foe_img(t_button *p)
{
	int		i;
	int		j;
	void	*foe1;
	void	*foe2;

	foe1 = ft_get_list_img(p->head, "foe1");
	foe2 = ft_get_list_img(p->head, "foe2");
	i = -1;
	while (p->map_array[++i])
	{
		j = -1;
		while (p->map_array[i][++j])
		{
			if (p->map_array[i][j] == 70)
			{
				if (p->steps % 2 == 0)
					mlx_put_image_to_window(p->mlx, p->mlx_win, foe1, j
						* p->size_img, i * p->size_img);
				else
					mlx_put_image_to_window(p->mlx, p->mlx_win, foe2, j
						* p->size_img, i * p->size_img);
			}
		}
	}
}

void	ft_move_player(t_button *p, int temp_i, int temp_j)
{
	void	*img_p;
	void	*img_e;
	void	*fon;
	int		m_sz;

	m_sz = 0;
	fon = ft_get_list_img(p->head, "fon");
	img_p = ft_get_list_img(p->head, "player");
	img_e = ft_get_list_img(p->head, "empty");
	p->steps++;
	if (p->status == 0)
	{
		ft_move_img(p, img_e, p->i * p->size_img, p->j * p->size_img);
		p->i = temp_i;
		p->j = temp_j;
		ft_move_img(p, img_p, p->i * p->size_img, p->j * p->size_img);
		ft_change_foe_img(p);
		while (p->map_array[m_sz])
			m_sz++;
		ft_move_img(p, fon, 0, m_sz * p->size_img);
		ft_move_img(p, fon, 50, m_sz * p->size_img);
		m_sz++;
		ft_print_img_txt(p, m_sz);
	}
}

void	ft_init_img_map(t_button *key, void *mlx, void *mlx_win, t_img *head)
{
	key->mlx = mlx;
	key->mlx_win = mlx_win;
	key->head = head;
	key->size_img = 50;
	key->steps = 0;
	key->status = 0;
	key->status_step = 0;
	ft_init_player(key);
	ft_init_collections(key);
}

static void	ft_static(int key, t_button *p, int temp_i, int temp_j)
{
	if (p->map_array[temp_j][temp_i] != 49)
	{
		if (p->map_array[temp_j][temp_i] == 'C')
			p->collections--;
		if (key == KEY_W || key == KEY_S || key == KEY_D || key == KEY_A)
		{
			if (p->map_array[temp_j][temp_i] == 'E' && !p->collections)
				ft_move_player(p, temp_i, temp_j);
			else if (p->map_array[temp_j][temp_i] != 'E')
				ft_move_player(p, temp_i, temp_j);
		}
	}
	ft_game_status(p);
}

int	key_pressed(int key, t_button *p)
{
	int		temp_i;
	int		temp_j;

	temp_i = p->i;
	temp_j = p->j;
	if (key == KEY_W)
		temp_j--;
	else if (key == KEY_S)
		temp_j++;
	else if (key == KEY_D)
		temp_i++;
	else if (key == KEY_A)
		temp_i--;
	else if (key == KEY_ESC)
	{
		printf("Pressed ESC button. Exit game\n");
		exit(0);
	}
	ft_static(key, p, temp_i, temp_j);
	return (0);
}
