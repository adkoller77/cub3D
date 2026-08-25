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

int	parse_map(int fd, t_game *game, char *line)
{
	int		i;
	char	*modif_line;
	char	**tmp;

	i = 0;
	while (line && line[0] != '\0' && line[0] != '\n')
	{
		modif_line = ft_strchr(line, '\n');
		if (modif_line)
			*modif_line = '\0';
		tmp = realloc(game->map.grid, sizeof(char *) * (i + 1));
		if (tmp == NULL)
			return (free(line), print_error("Memory allocation failed"));
		game->map.grid = tmp;
		game->map.grid[i] = line;
		i++;
		line = get_next_line(fd);
	}
	free(line);
	game->map.size = i;
	close(fd);
	return (pad_map(game));
}
