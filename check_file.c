/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmorale <crmorale@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 20:08:24 by crmorale          #+#    #+#             */
/*   Updated: 2025/08/19 21:05:55 by crmorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * 
 */
int	check_extension(char *file_name)
{
	int	len;

	len = ft_strlen(file_name);
	if (len <= 4)
		return (0);
	if (!file_name)
		return (0);
	return (file_name[len - 1] == 'b' && file_name[len - 2] == 'u' &&
		file_name[len - 3] == 'c' && file_name[len - 4] == '.');
}

/**
 * 
 */
char	**check_file(char *av)
{
	char	**map_array;

	if (!check_extension(av))
		error_msg("Error\nBad extension.");
	map_array = read_file(av);
	if (!map_array)
		error_msg("Error\nFailed to read file.");
	return (map_array);
}