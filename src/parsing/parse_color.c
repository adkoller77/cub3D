#include "cub3d.h"

int	parse_rgb(char *line, int *color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < 3)
	{
		if (!ft_isdigit(line[i]))
			return (print_error("Invalid color format"));
		color[j] = ft_atoi(line + i);
		if (color[j] < 0 || color[j] > 255)
			return (print_error("Color value out of range"));
		while (ft_isdigit(line[i]))
			i++;
		if (j < 2 && line[i] != ',')
			return (print_error("Invalid color format"));
		if (line[i] == ',')
			i++;
		j++;
	}
	if (line[i] != '\0')
		return (print_error("Invalid color format"));
	return (0);
}

int	parse_color(char *line, t_game *game, int is_floor)
{
	int		i;
	char	*modif_line;

	i = 1;
	if (line[1] != ' ')
		return (print_error("Missing space after color identifier"));
	while (line[i] == ' ')
		i++;
	modif_line = ft_strchr(line, '\n');
	if (modif_line)
		*modif_line = '\0';
	if (line[i] == '\0')
		return (print_error("Missing color value"));
	if (is_floor)
	{
		if (game->map.floor_color[0] != -1)
			return (print_error("Duplicate floor color definition"));
		return (parse_rgb(line + i, game->map.floor_color));
	}
	if (game->map.ceil_color[0] != -1)
		return (print_error("Duplicate ceiling color definition"));
	return (parse_rgb(line + i, game->map.ceil_color));
}
