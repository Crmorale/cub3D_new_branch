/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 19:48:00 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/08/25 20:40:12 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cu_savemap(char **file, int start)
{
	int		i;
	int		j;
	int		line_len;
	char	**map;
	t_data	*data;
	int		player_count = 0;

	i = start;
	while (file[i])
		i++;
	map = smalloc(sizeof(char *) * (i - start + 1));
	if (!map)
		error_msg("ERROR: parse_map.c: cu_savemap: malloc FAILED\n");
	map[i - start] = NULL;
	i = 0;
	while (file[start])
	{
		j = 0;
		// Calcular longitud de la línea
		while (file[start][j] != '\n' && file[start][j] != '\0')
			j++;
		line_len = j;
		
		// Asignar memoria para la línea
		map[i] = smalloc(sizeof(char) * (line_len + 1));
		if (!map[i])
			error_msg("ERROR: parse_map.c: cu_savemap: malloc FAILED\n");
		
		// Copiar caracteres válidos y contar posiciones del jugador
		j = 0;
		while (j < line_len)
		{
			if (file[start][j] == 'N' || file[start][j] == 'S' || 
				file[start][j] == 'E' || file[start][j] == 'W')
			{
				player_count++;
				if (player_count > 1)
					error_msg("ERROR: parse_map.c: cu_savemap: MULTIPLE PLAYER POSITIONS FOUND\n");
				map[i][j] = file[start][j];
			}
			else if (file[start][j] == '0' || file[start][j] == '1' || 
					 file[start][j] == ' ')
			{
				map[i][j] = file[start][j];
			}
			else
				error_msg("ERROR: parse_map.c: cu_savemap: BAD CHARACTER FOR MAP\n");
			j++;
		}
		map[i][j] = '\0';  // Terminar string
		start++;
		i++;
	}
	
	// Validar que se encontró exactamente una posición del jugador
	if (player_count == 0)
		error_msg("ERROR: parse_map.c: cu_savemap: NO PLAYER POSITION FOUND\n");
	if (player_count != 1)
		error_msg("ERROR: parse_map.c: cu_savemap: EXACTLY ONE PLAYER POSITION REQUIRED\n");
	data = get_pdata(NULL);
	data->game.map = map;
}

/**
 * We found the first line where
 */
void	cu_parse_map(char **file, int start)//debería poder entrar el valor de i justo por donde nos hemos quedado parseando texturas y colores.
{
	int		j;
	bool	map_found;

	if (!file)
		error_msg("ERROR: parse_map.c: cu_parse_map: file = NULL\n");
	map_found = 0;
	//vamos a limpiar primero las lineas que solo tienen espacio
	while (file[start])
	{
		j = 0;
		//checkea la linea entera
		while (file[start][j] !='\n' && file[start][j] != '\0')
		{
			if (file[start][j] == '1')
			{
				map_found = 1;
				break ;
			}
			j++;
		}
		//si la linea tiene 
		if (map_found == 1)
			break ;
		start++;
	}
	cu_savemap(file, start);
	sfree(file);
}
