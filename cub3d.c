/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmorale <crmorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:01:23 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/09/01 22:51:15 by crmorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	key_hook(mlx_key_data_t keydata, void *param)
{
	mlx_t	*mlx;

	mlx = (mlx_t *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(mlx);
}


int	main(int ac, char **av)
{
	mlx_t	*mlx;
	t_data	data;

	if (ac != 2)
		error_msg("Error\nPlease, run Cub3D with exactly one argument.\n");

	// Inicializar el sistema de memoria
		//iniciar a 0 los datos de las texturas.???? init data
	ft_memset(&data, 0, sizeof(t_data));//meter dentro de init data
	get_pdata(&data);


	// WHOLE FILE PARSING
	check_and_parse_file(&data)
	
	//test
	char	**array;
	int		i;
	check_extension(av[1]);
	array = read_file(av[1]);
	if (array == NULL)
		printf("Error: No se pudo leer el archivo del test\n");
	else
	{
		i = 0;
		printf("Contenido del archivo:\n"CI);
		while (array[i])
		{
			printf("Línea %d: %s", i + 1, array[i]);
			i++;
		}
	}
	cu_parse_map(array, 0);
	printf(RES"\nContenido de data->game.map:\n");
	if (data.game.map != NULL)
	{
		i = 0;
		while (data.game.map[i])
		{
			printf(GR"Línea %d: %s\n"RES, i + 1, data.game.map[i]);
			i++;
		}
	}
	else
	{
		printf("Error: data.game.map is NULL\n");
	}






	mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", true);
	if (!mlx)
	{
		fprintf(stderr, "Error: MLX42 init failed.\n");
		return (EXIT_FAILURE);
	}
	//Hook ESC to close
	mlx_key_hook(mlx, key_hook, mlx);
	//Run main loop
	mlx_loop(mlx);

	// Cleanup MLX42 internals
	mlx_terminate(mlx);
	//Use the function for free all the data stored manually
	mem_clear();
	return (EXIT_SUCCESS);
}
