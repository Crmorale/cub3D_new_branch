/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 22:00:00 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/08/20 21:37:13 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * Verifica que haya exactamente un jugador en el mapa
 */
static int	check_player_count(char **map)
{
	int	i;
	int	j;
	int	player_count;

	player_count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || 
				map[i][j] == 'E' || map[i][j] == 'W')
				player_count++;
			j++;
		}
		i++;
	}
	return (player_count == 1);
}

/**
 * Verifica que el mapa esté cerrado (rodeado de paredes)
 */
static int	check_closed_map(char **map)
{
	int	i;
	int	j;

	// Verificar primera y última fila
	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1' && map[0][i] != ' ')
			return (0);
		i++;
	}
	
	// Encontrar última fila
	i = 0;
	while (map[i + 1])
		i++;
	
	j = 0;
	while (map[i][j])
	{
		if (map[i][j] != '1' && map[i][j] != ' ')
			return (0);
		j++;
	}
	
	// Verificar primera y última columna de cada fila
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' && map[i][0] != ' ')
			return (0);
		j = ft_strlen(map[i]) - 1;
		if (j >= 0 && map[i][j] != '1' && map[i][j] != ' ')
			return (0);
		i++;
	}
	return (1);
}

/**
 * Guarda la posición inicial del jugador
 */
static void	save_player_position(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || 
				map[i][j] == 'E' || map[i][j] == 'W')
			{
				data->game.spawn_x = j;
				data->game.spawn_y = i;
				data->game.spawn_dir = map[i][j];
				map[i][j] = '0';  // Convertir a espacio vacío
				return ;
			}
			j++;
		}
		i++;
	}
}

/**
 * Valida el mapa completo
 */
void	validate_map(void)
{
	t_data	*data;

	data = get_pdata(NULL);
	if (!data->game.map)
		error_msg("ERROR: No map found\n");
	
	if (!check_player_count(data->game.map))
		error_msg("ERROR: Map must have exactly one player\n");
	
	if (!check_closed_map(data->game.map))
		error_msg("ERROR: Map must be closed by walls\n");
	
	save_player_position(data->game.map, data);
}
