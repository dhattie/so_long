/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:43:24 by dhattie           #+#    #+#             */
/*   Updated: 2021/12/26 20:43:25 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_print_img_txt(t_button *p, int m_sz)
{
	mlx_string_put(p->mlx, p->mlx_win, 5, m_sz * p->size_img - 30,
		0xFFFF00, "Steps: ");
	mlx_string_put(p->mlx, p->mlx_win, 70, m_sz * p->size_img - 30,
		0xFFFF00, ft_itoa(p->steps));
}

void	ft_game_status(t_button *p)
{
	int		m_sz;
	int		kol;

	kol = p->collections;
	m_sz = 0;
	while (p->map_array[m_sz])
		m_sz++;
	m_sz++;
	if (p->map_array[p->j][p->i] == 69 && p->status_step == 0 && !kol)
		mlx_string_put(p->mlx, p->mlx_win, 5, ++m_sz * p->size_img - 30,
			0xFFFF00, "You win");
	if (p->map_array[p->j][p->i] == 70 && p->status_step == 0)
		mlx_string_put(p->mlx, p->mlx_win, 5, ++m_sz * p->size_img - 30,
			0xFFFF00, "Game over");
	if (!kol)
		if (p->map_array[p->j][p->i] == 'E')
			p->status = 1;
	if (p->map_array[p->j][p->i] == 'F')
		p->status = 1;
}
