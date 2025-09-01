/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 03:43:05 by crmorale          #+#    #+#             */
/*   Updated: 2025/08/26 20:22:29 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	save_map_data(char **map_array)
{
	int			i;
	t_data		*data;
	t_textinfo	*tex;

	i = 0;
	data = get_pdata(NULL);

	//Almacenar los datos principales
	parse_textures(map_array, data->game.textures, &i);
	cu_parse_map(map_array, i);
	cu_checkmap(NULL);
	//Iniciar la informacion de la ubicación del jugador
}
