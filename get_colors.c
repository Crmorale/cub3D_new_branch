/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmorale <crmorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:29:47 by crmorale          #+#    #+#             */
/*   Updated: 2025/08/28 16:03:50 by crmorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int ft_atoi_rgb(const char *str)
{
	int	i;
	int	result;
	
	i = 0;
	result = 0;
	while(str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		return (-1);
	while (str[i] >= 48 && str[i] <= 57) {
		result = result * 10 + str[i] - 48;
		i++;
	}
	if (str[i] != '\0')
		return (-1);
	return (result);
}

int	valid_rgb_value(int n)
{
	return (n >= 0 && n <= 255);
}

/**
 * 
 */
int	parse_rgb_line(char *line, int rgb[3])
{
	char	**parts;
	int		i;

	// saltar espacios
	while ((*line >= 9 && *line <= 13) || *line == 32) // ***CAMBIADOS "c" POR "*line"***
		line++;

	// dividir por coma
	parts = ft_split(line, ','); //añadir split
	if (!parts)
		return (0);

	// comprobar que hay exactamente 3 valores
	i = 0;
	while (i < 3)
	{
		if (!parts[i])
		{
			ft_sfree_split(parts);
			return (0);
		}
		rgb[i] = ft_atoi_rgb(parts[i]);
		if (!valid_rgb_value(rgb[i]))
		{
			ft_sfree_split(parts);
			return (0);
		}
		i++;
	}

	if (parts[3]) // más de 3 valores -> error
	{
		ft_sfree_split(parts);
		return (0);
	}

	ft_sfree_split(parts);
	return (1);
}
