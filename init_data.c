/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:21:41 by crmorale          #+#    #+#             */
/*   Updated: 2025/08/25 20:39:05 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_textinfo(t_textinfo *info)
{
	int i;

	if (!info)
		return ;

	info->no_path = NULL;
	info->so_path = NULL;
	info->we_path = NULL;
	info->ea_path = NULL;

	i = 0;
	while (i < 3)
	{
		info->floor[i] = -1;
		info->ceiling[i] = -1;
		i++;
	}

	info->has_no = 0;
	info->has_so = 0;
	info->has_we = 0;
	info->has_ea = 0;
	info->has_c = 0;
	info->has_f = 0;
}