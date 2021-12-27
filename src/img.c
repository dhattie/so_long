/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:21:08 by dhattie           #+#    #+#             */
/*   Updated: 2021/12/26 16:21:10 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_map_array(char **map_array, int number_lines, int number_columns)
{
	int		i;
	int		j;

	j = -1;
	while (map_array[0][++j])
	{
		if (map_array[0][j] != '1' || map_array[number_lines - 1][j] != '1' ||
			number_lines >= number_columns)
		{
			printf("Error\n Horizontal wall destroyed\n");
			exit(1);
		}
	}
	i = -1;
	while (map_array[++i])
	{
		if (map_array[i][0] != '1' || map_array[i][number_columns - 1] != '1'
			|| ft_strlen(map_array[i]) != number_columns)
		{
			printf("Error\n Vertical wall destroyed \n");
			exit(1);
		}
	}
	ft_check_player(map_array);
	return (0);
}

void	push_object_list(t_img **head, char *title, void *img)
{
	t_img	*obj;

	if (head)
	{
		obj = (t_img *)malloc(sizeof(t_img));
		if (obj == NULL)
		{
			printf("Error\n can't give memory for list \n");
			exit(1);
		}
		obj->title = title;
		obj->img = img;
		obj->next = *head;
		*head = obj;
	}
	else
	{
		printf("Error\n list objects is empty \n");
		exit(1);
	}
}

void	*ft_get_list_img(t_img *head, char *tittle)
{
	if (head)
	{
		while (head)
		{
			if (head->title == tittle)
				return (head->img);
			head = head->next;
		}
	}
	printf("Error\n list objects is empty \n");
	exit(1);
}

void	ft_put_img_window(void *mlx, void *mlx_win, t_img *head, char **map_ar)
{
	int		i;
	int		j;
	void	*img;

	i = -1;
	while (map_ar[++i])
	{
		j = -1;
		while (map_ar[i][++j])
		{
			if (map_ar[i][j] == 49)
				img = ft_get_list_img(head, "wall");
			else if (map_ar[i][j] == 67)
				img = ft_get_list_img(head, "collectable");
			else if (map_ar[i][j] == 80)
				img = ft_get_list_img(head, "player");
			else if (map_ar[i][j] == 69)
				img = ft_get_list_img(head, "exit");
			else if (map_ar[i][j] == 48)
				img = ft_get_list_img(head, "empty");
			else if (map_ar[i][j] == 70)
				img = ft_get_list_img(head, "foe1");
			mlx_put_image_to_window(mlx, mlx_win, img, j * 50, i * 50);
		}
	}
}

void	*ft_push_mlx_img_list(void *mlx, t_img **head)
{
	void	*img;
	int		x;
	int		y;

	img = mlx_png_file_to_image(mlx, "./images/collectable.png", &x, &y);
	push_object_list(head, "collectable", img);
	img = mlx_png_file_to_image(mlx, "./images/empty.png", &x, &y);
	push_object_list(head, "empty", img);
	img = mlx_png_file_to_image(mlx, "./images/exit.png", &x, &y);
	push_object_list(head, "exit", img);
	img = mlx_png_file_to_image(mlx, "./images/player.png", &x, &y);
	push_object_list(head, "player", img);
	img = mlx_png_file_to_image(mlx, "./images/wall.png", &x, &y);
	push_object_list(head, "wall", img);
	img = mlx_png_file_to_image(mlx, "./images/foe1.png", &x, &y);
	push_object_list(head, "foe1", img);
	img = mlx_png_file_to_image(mlx, "./images/foe2.png", &x, &y);
	push_object_list(head, "foe2", img);
	img = mlx_png_file_to_image(mlx, "./images/fon.png", &x, &y);
	push_object_list(head, "fon", img);
	return (mlx);
}
