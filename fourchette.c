/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fourchette.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:54:33 by ski               #+#    #+#             */
/*   Updated: 2022/03/25 13:54:35 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

/* ************************************************************************** */
int init_fourchette(t_data *d)
{
	int i;

	i = 0;
	while (i < d->max_philo)
	{
		if((pthread_mutex_init(d->philo[i].fourchette, NULL)) != 0)
			return (ERROR);
		i++;
	}

	return (NO_ERROR);
}

/* ************************************************************************** */
void destroy_fourchette(t_data *d)
{
	int i;

	i = 0;
	while (i < d->max_philo)
	{
		pthread_mutex_destroy(d->philo[i].fourchette);
		i++;
	}
}