/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:51:27 by dhattie           #+#    #+#             */
/*   Updated: 2021/12/26 20:51:29 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_print_img_txt(t_button *p, int m_sz)
{
	m_sz = 0;
	printf("steps = %i \n", p->steps);
	if (p->map_array[p->j][p->i] == 69)
		printf("You win \n");
	if (p->map_array[p->j][p->i] == 70)
		printf("Game over \n");
}

void	ft_game_status(t_button *p)
{
	int	kol;

	kol = p->collections;
	if (!kol)
		if (p->map_array[p->j][p->i] == 'E')
			p->status = 1;
	if (p->map_array[p->j][p->i] == 'F')
		p->status = 1;
}
