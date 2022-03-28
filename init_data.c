/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:54:33 by ski               #+#    #+#             */
/*   Updated: 2022/03/25 13:54:35 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

/* ************************************************************************** */
void init_data(t_data *d)
{
	d->max_philo		= 6;	
	d->time_die 		= 10 * 1000;	// after the beginning of last meal
	d->time_eat 		= 2 * 1000;
	d->time_sleep 		= 2 * 1000;
	d->max_eat 			= 10;
	d->all_living		= true;

	printf("[%d] philosophers\n", d->max_philo);
	printf("Time to die \t[%d ms]\n", d->time_die);
	printf("Time to eat \t[%d ms]\n", d->time_eat);
	printf("Time to sleep \t[%d ms]\n", d->time_sleep);
	printf("Maximum meal \t[%d]\n", d->max_eat);
	printf("\n");

}

/* ************************************************************************** */

	// /* ------------------------------------------------------ */
	// if (argc != 5 && argc != 6)
	// {
	// 	write(1, TXT_ERR_ARG, ft_strlen(TXT_ERR_ARG));
	// 	return (ERROR);
	// }
	// /* ------------------------------------------------------ */
	// if((save_arg(argc, argv, &d)) == ERROR)
	// {
	// 	write(1, TXT_ERR_CNT, ft_strlen(TXT_ERR_CNT));
	// 	return (ERROR);
	// }
	// /* ------------------------------------------------------ */