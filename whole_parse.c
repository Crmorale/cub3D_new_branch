/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whole_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmorale <crmorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:42:11 by crmorale          #+#    #+#             */
/*   Updated: 2025/09/02 00:15:58 by crmorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void check_and_parse_file(char *file_name, t_data *data)
{

	char	**map_array;
	int		i;
	
	check_file(file_name);
	parse_textures(file_name, data->game.textures, &i);
	cu_parse_map(map_array, &i);
	//meter map_validation
}