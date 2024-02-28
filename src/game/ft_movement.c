/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:31:34 by javi              #+#    #+#             */
/*   Updated: 2024/02/28 17:27:38 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "game.h"

    // Calcula los nuevos valores de dirección después de la rotación
    // Calcula los nuevos valores del plano de la cámara después de la rotación
void	ft_rotate_player(t_player *player, double rot_speed)
{
    double	oldDirX;
	double	oldPlaneX;

	oldDirX = player->dir.x;
    player->dir.x = player->dir.x * cos(rot_speed) - player->dir.y * sin(rot_speed);
    player->dir.y = oldDirX * sin(rot_speed) + player->dir.y * cos(rot_speed);
    oldPlaneX = player->plane.x;
    player->plane.x = player->plane.x * cos(rot_speed) - player->plane.y * sin(rot_speed);
    player->plane.y = oldPlaneX * sin(rot_speed) + player->plane.y * cos(rot_speed);
}

void ft_strafe_left(t_player *player, double strafe_speed)
{
    player->pos.x -= player->plane.x * strafe_speed;
    player->pos.y -= player->plane.y * strafe_speed;
}

void ft_strafe_right(t_player *player, double strafe_speed)
{
    player->pos.x += player->plane.x * strafe_speed;
    player->pos.y += player->plane.y * strafe_speed;
}

void    ft_move_forward(t_player *player, double movement_speed)
{
    player->pos.x += player->dir.x * movement_speed;
    player->pos.y += player->dir.y * movement_speed;
}

void    ft_move_backwards(t_player *player, double movement_speed)
{
    player->pos.x -= player->dir.x * movement_speed;
    player->pos.y -= player->dir.y * movement_speed;
}