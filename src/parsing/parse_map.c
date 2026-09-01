#include "cub3d.h"

static int	pad_row(t_game *game, int i, int max_len)
{
	char	*padded;
	int		len;
	int		j;

	len = ft_strlen(game->map.grid[i]);
	if (len == max_len)
		return (0);
	padded = malloc(max_len + 1);
	if (padded == NULL)
		return (print_error("Memory allocation failed"));
	j = 0;
	while (j < len)
	{
		padded[j] = game->map.grid[i][j];
		j++;
	}
	while (j < max_len)
		padded[j++] = ' ';
	padded[max_len] = '\0';
	free(game->map.grid[i]);
	game->map.grid[i] = padded;
	return (0);
}

static int	pad_map(t_game *game)
{
	int	i;
	int	max_len;

	i = 0;
	max_len = 0;
	while (i < game->map.size)
	{
		if ((int)ft_strlen(game->map.grid[i]) > max_len)
			max_len = ft_strlen(game->map.grid[i]);
		i++;
	}
	i = 0;
	while (i < game->map.size)
	{
		if (pad_row(game, i, max_len) == -1)
			return (-1);
		i++;
	}
	return (0);
}

static int	add_map_line(t_game *game, char *line)
{
	char	**arr;
	char	*nl;
	int		i;

	nl = ft_strchr(line, '\n');
	if (nl)
		*nl = '\0';
	arr = malloc(sizeof(char *) * (game->map.size + 1));
	if (arr == NULL)
		return (-1);
	i = 0;
	while (i < game->map.size)
	{
		arr[i] = game->map.grid[i];
		i++;
	}
	arr[i] = line;
	free(game->map.grid);
	game->map.grid = arr;
	game->map.size++;
	return (0);
}

int	parse_map(int fd, t_game *game, char *line)
{
	int	map_ended;

	map_ended = 0;
	while (line)
	{
		if (is_blank_line(line))
			map_ended = 1;
		else if (map_ended)
			return (free(line), close(fd), print_error("Content after map"));
		else if (add_map_line(game, line) == -1)
			return (free(line), close(fd), print_error("Malloc failed"));
		else
			line = NULL;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (check_elements(game) == -1)
		return (-1);
	return (pad_map(game));
}
