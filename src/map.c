/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhattie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:28:59 by dhattie           #+#    #+#             */
/*   Updated: 2021/12/04 18:29:02 by dhattie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_extension_check(char *argv)
{
	if (ft_strncmp((argv + ft_strlen(argv) - 4), ".ber", 4) != 0)
	{
		printf("Error\n Invalid file extension");
		exit(1);
	}
}

int	map_open(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n");
		perror("Open() failed");
		exit(1);
	}
	return (fd);
}

char	**map_push_array(int fd, int map_size)
{
	char	*line;
	char	**map_array;
	int		i;

	i = 0;
	map_array = malloc(sizeof (char *) * (map_size + 1));
	while (get_next_line(fd, &line))
	{
		map_array[i++] = ft_strdup(line);
		free(line);
		line = NULL;
	}
	map_array[i] = ft_strdup(line);
	map_array[++i] = NULL;
	free(line);
	line = NULL;
	close(fd);
	return (map_array);
}

size_t	map_number_lines(int fd)
{
	size_t		byte_read;
	size_t		buf_read;
	char		bf[2];

	buf_read = 1;
	byte_read = 1;
	if (fd < 0 || read(fd, 0, 0) < 0)
		return (-1);
	while (buf_read)
	{
		buf_read = read(fd, bf, 1);
		if (*bf == '\n')
			byte_read = byte_read + buf_read;
	}
	close(fd);
	return (byte_read);
}

void	map_arg_check(int fd)
{
	size_t		buf_read;
	char		bf[2];

	buf_read = 1;
	if (fd < 0 || read(fd, 0, 0) < 0)
	{
		printf("Error\n Inpossible open map\n");
		exit(1);
	}
	while (buf_read)
	{
		buf_read = read(fd, bf, 1);
		if (ft_strchr("01CEPF\n", *bf) == NULL)
		{
			printf("Error\n Inpossible characters, symbol = '%i'\n", (int)*bf);
			exit(1);
		}
	}
	close(fd);
}
