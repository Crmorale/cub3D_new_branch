/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 21:25:11 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/08/20 20:56:06 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * READING THE FILE
 * Saves the (map).cub into one string
 * 
 * Queremos recibir un archivo y convertirlo en un array separado por saltos de linea
 */
char	**read_file(const char *filename)
{
	int		fd;
	char	*line;
	char	**array;
	char	**tmp;
	int		i;
	int		j;

	//abrimos el archivo
	fd = sopen(filename, O_RDONLY, -1);
	if (fd < 0)
		return (NULL);

	array = smalloc(sizeof(char *)); // array vacío
	if (!array)
		//ERROR
	array[0] = NULL;
	i = 0;

	//creamos un bucle para automatizar todas las demas posibles lineas si existieran
	while ((line = get_next_line(fd)) != NULL)
	{
		// reservar nuevo array con 1 slot más
		tmp = smalloc(sizeof(char *) * (i + 2));
		// copiar punteros existentes
		j = -1;
		while (++j < i)
			tmp[j] = array[j];
		// añadir nueva línea
		tmp[i] = line;
		tmp[i + 1] = NULL;

		sfree(array);   // liberar solo el array (no sus strings)
		array = tmp;
		i++;
	}

	sclose(fd);//fix sclose!!

	return (array);
}




//Split the text into lines
// lines = ft_split(line, '\n');  // libft function

/*

4️⃣ Parsing keys
c
Copy
Edit
int parse_rgb(char *line, t_rgb *color)
{
    // line format: "F 220,100,0"
    // skip first char
    char **nums = ft_split(line + 1, ',');
    if (!nums || !nums[0] || !nums[1] || !nums[2])
        return 0;
    color->r = ft_atoi(nums[0]);
    color->g = ft_atoi(nums[1]);
    color->b = ft_atoi(nums[2]);
    // free split
    for (int i = 0; nums[i]; i++)
        free(nums[i]);
    free(nums);
    return 1;
}

int parse_texture(char *line, char **texture)
{
    while (*line && *line != ' ')
        line++;
    while (*line == ' ')
        line++;
    if (!*line)
        return 0;
    *texture = ft_strdup(line);
    return 1;
}
5️⃣ Parsing map & spawn
c
Copy
Edit
int is_spawn(char c)
{
    return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int validate_map_line(char *line, t_game *game, int y)
{
    for (int x = 0; line[x]; x++)
    {
        char c = line[x];
        if (!(c == '0' || c == '1' || c == ' ' || is_spawn(c)))
            return 0;
        if (is_spawn(c))
        {
            if (game->spawn_dir) // already found
                return 0;
            game->spawn_dir = c;
            game->spawn_x = x;
            game->spawn_y = y;
        }
    }
    return 1;
}

char **extract_map(char **lines, t_game *game)
{
    int start = 0;
    while (lines[start] && !ft_strchr("01NSEW ", lines[start][0]))
        start++;

    int height = 0;
    while (lines[start + height])
        height++;

    game->map_height = height;
    char **map = malloc(sizeof(char *) * (height + 1));
    for (int i = 0; i < height; i++)
    {
        map[i] = ft_strdup(lines[start + i]);
        if (!validate_map_line(map[i], game, i))
        {
            // cleanup
            for (int j = 0; j <= i; j++) free(map[j]);
            free(map);
            return NULL;
        }
    }
    map[height] = NULL;
    return map;
}
6️⃣ Putting it together
c
Copy
Edit
int parse_cub(char *filename, t_game *game)
{
    char *line = read_file(filename);
    if (!line)
        return 0;

    char **lines = ft_split(line, '\n');
    free(line);
    if (!lines)
        return 0;

    for (int i = 0; lines[i]; i++)
    {
        if (ft_strncmp(lines[i], "NO", 2) == 0) parse_texture(lines[i], &game->no);
        else if (ft_strncmp(lines[i], "SO", 2) == 0) parse_texture(lines[i], &game->so);
        else if (ft_strncmp(lines[i], "WE", 2) == 0) parse_texture(lines[i], &game->we);
        else if (ft_strncmp(lines[i], "EA", 2) == 0) parse_texture(lines[i], &game->ea);
        else if (lines[i][0] == 'F') parse_rgb(lines[i], &game->floor);
        else if (lines[i][0] == 'C') parse_rgb(lines[i], &game->ceil);
    }

    game->map = extract_map(lines, game);
    
    // free lines array
    for (int i = 0; lines[i]; i++) free(lines[i]);
    free(lines);

    if (!game->map || !game->spawn_dir || !game->no || !game->so || !game->we || !game->ea)
        return 0;

    return 1;
}
✅ Deliverable

Call parse_cub("example.cub", &game) in main.

On success, game has all textures, colors, map, spawn position.

On error, everything is freed and program can exit with message.

Only allowed functions are used.





*/