/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_game_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:39:06 by ski               #+#    #+#             */
/*   Updated: 2022/03/27 16:39:09 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

/* ************************************************************************** */
int check_game_data(t_data *d)
{
	if (DISPLAY_INFO == 0)
		return (NO_ERROR);

	if (d->time_to_eat > d->time_to_die)
	{
		ft_printf("time to eat CAN NOT BE longer than time to die\n");
		return (ERROR);
	}

	if (d->time_to_eat + d->time_to_sleep > d->time_to_die)
	{
		ft_printf("time to eat PLUS time to sleep CAN NOT BE longer than time to die\n");
		return (ERROR);
	}

	return (NO_ERROR);
}


