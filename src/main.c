/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:20:00 by dhattie           #+#    #+#             */
/*   Updated: 2021/12/04 20:20:02 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*ft_new_window(void *mlx, char **map_array)
{
	int		i;
	int		j;
	void	*mlx_win;

	i = 0;
	while (map_array[++i])
	{
		j = 0;
		while (map_array[i][j])
			j++;
	}
	i = i + 2;
	mlx_win = mlx_new_window(mlx, j * 50, i * 50, "Dhattie");
	return (mlx_win);
}

char	**ft_check_map(char *path)
{
	int		map_lines;
	char	**map_array;

	map_array = NULL;
	map_extension_check(path);
	map_arg_check(map_open(path));
	map_lines = map_number_lines(map_open(path));
	map_array = map_push_array(map_open(path), map_lines);
	check_map_array(map_array, map_lines, ft_strlen(map_array[0]));
	return (map_array);
}

int	main(int argc, char **argv)
{
	char		**map_array;
	void		*mlx;
	void		*mlx_win;
	t_img		*window;
	t_button	player;

	if (argc == 2)
	{
		map_array = ft_check_map(argv[1]);
		mlx = mlx_init();
		ft_push_mlx_img_list(mlx, &window);
		mlx_win = ft_new_window(mlx, map_array);
		ft_put_img_window(mlx, mlx_win, window, map_array);
		player.map_array = map_array;
		ft_init_img_map(&player, mlx, mlx_win, window);
		mlx_hook(mlx_win, X_EVENT_KEY_PRESS, 0, &key_pressed, &player);
		mlx_hook(mlx_win, X_EVENT_MOUSE_EXIT, 0, &mouse_esc, &player);
		mlx_loop(mlx);
	}
	else
	{
		printf("Error\n Indicate the map\n");
		exit(0);
	}
	return (0);
}
