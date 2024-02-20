/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_parse_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 11:27:35 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/20 14:14:30 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "game_struct.h"
/**
 * @brief Prints an error message to the console in a formatted way.
 *
 * This function takes an error message string and displays it with formatting
 * likely using terminal color codes. It then returns `FALSE`.
 *
 * @param error_text Pointer to a null-terminated character string
 				     containing the error message.
 *
 * @return `FALSE`, indicating an error condition.
 */
t_data	*ft_show_parse_error(const char *error_text)
{
	ft_putstr_fd(KRED"Error\n", 2);
	ft_putstr_fd(KWHT"CUBE3D PARSER:", 2);
	printf("%s \n", error_text);
	return (NULL);
}