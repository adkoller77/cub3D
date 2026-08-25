#include "cub3d.h"

int	parse_element(char *line, t_game *game)
{
	if (line[0] == '\n' || line[0] == '\0')
		return (0);
	if (ft_strncmp(line, "NO", 2) == 0)
		return (parse_texture(line, game, 0));
	if (ft_strncmp(line, "SO", 2) == 0)
		return (parse_texture(line, game, 1));
	if (ft_strncmp(line, "EA", 2) == 0)
		return (parse_texture(line, game, 2));
	if (ft_strncmp(line, "WE", 2) == 0)
		return (parse_texture(line, game, 3));
	if (line[0] == 'F')
		return (parse_color(line, game, 1));
	if (line[0] == 'C')
		return (parse_color(line, game, 0));
	return (-2);
}

int	read_cub(int fd, t_game *game)
{
	char	*line;
	int		ret;

	line = get_next_line(fd);
	while (line)
	{
		ret = parse_element(line, game);
		if (ret == -1)
			return (free(line), -1);
		if (ret == -2)
		{
			if (line[0] == '1' || line[0] == '0' || line[0] == ' '
				|| line[0] == 'N' || line[0] == 'S'
				|| line[0] == 'E' || line[0] == 'W')
				return (parse_map(fd, game, line));
			return (free(line), print_error("Unknown element identifier"));
		}
		free(line);
		line = get_next_line(fd);
	}
	if (check_elements(game) == -1)
		return (-1);
	return (0);
}
