/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:30:47 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/27 17:08:29 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#define XK_Escape                        53
int	ft_key_press(t_gamedata *gdata);
int	ft_button_close(t_gamedata *gdata);


int	key_hook(int keycode, t_gamedata *data)
{
	//printf("\n key = %d", keycode);
	if (keycode == XK_Escape)
	{
		printf("salida de escape. hacer frees\n");
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	if (keycode == 13 || keycode == 126) // move forward
	{
		printf("W");
		data->player.pos.y += .3 * data->player.dir.y;
	
	}
	if (keycode == 0) 
	{
		printf("A");
		ft_strafe_left(&data->player, STRAFE_SPEED);
		//data->player.pos.x -= .3* data->player.dir.x;
	}
	if (keycode == 1 || keycode == 125) //move back
	{
		printf("S");
		data->player.pos.y -= .3* data->player.dir.y;
	}
	if (keycode == 2)
	{
		printf("D");
		ft_strafe_right(&data->player, STRAFE_SPEED);
		//data->player.pos.x += .3* data->player.dir.x;
	}
	if (keycode == 123)
	{
		ft_rotate_player(&data->player, ROTATION_SPEED);
	}
	if (keycode == 124)
	{
		ft_rotate_player(&data->player, -ROTATION_SPEED);
	}
	if (keycode == 49)
	{
		printf("SPACE");
		
	}
	ft_start_draw(data);
	printf("salida pos.x = %f pos.y = %f\n", data->player.pos.x, data->player.pos.y);
	return (keycode);
}

void	ft_start_hooks(t_gamedata *gdata)
{
	mlx_hook(gdata->win, 2,1L<<0, key_hook, gdata);
	//mlx_hook(gdata->win, 33, 0L,  ft_key_press, gdata);
	//mlx_key_hook(gdata->win, key_hook, gdata);
	mlx_hook(gdata->win, 17, 0, ft_button_close, gdata);
}

int	ft_key_press(t_gamedata *gdata)
{
	printf("\n\nKEY\n %c", gdata->map->map2d[0][0]);
	
	return (0);
}

int	ft_button_close(t_gamedata *gdata)
{
	(void)gdata;
	//ft_free_map(gdata);
	ft_putstr_fd("\rProgram terminated successfully", 1);
	//close_game(gdata);
	exit (0);
}



