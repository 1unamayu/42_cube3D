/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:45:06 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/19 10:09:36 by javi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"
#include "parser.h"

int	main(int argn, char *argv[])
{
	if (argn != 2)
	{
		printf(KRED"Error\n"KWHT"CUBE3D: Incorrect number of arguments."KNRM"\n");
		printf(KBLU"CUBE3D: Usage ./cube3d <mapfile.cub>");
				}
	else if (ft_is_valid_input_file(argv) == TRUE)
	{
		printf(KBLU"\nLoading %s ...\n",argv[1]);
		printf(KNRM);
		if (ft_is_valid_map(argv[1]) == TRUE)
		{
			ft_parse_map();
		}
	}
	exit(0);
}
