/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:54:33 by ski               #+#    #+#             */
/*   Updated: 2022/03/25 13:54:35 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

/* ************************************************************************** */
int init_all_mutex(t_data *d)
{
	int i;

	i = 0;
	while (i < d->max_philo)
	{
		if((pthread_mutex_init(&d->mtx_fork_set[i], NULL)) != 0)
			return (ERROR);
		i++;
	}

	if (pthread_mutex_init(&d->mtx_journal, NULL) != 0)
		return (ERROR);

	if (pthread_mutex_init(&d->mtx_all_living, NULL) != 0)
		return (ERROR);

	return (NO_ERROR);
}

/* ************************************************************************** */
void destroy_all_mutex(t_data *d)
{
	int i;

	i = 0;
	while (i < d->max_philo)
	{
		pthread_mutex_destroy(&d->mtx_fork_set[i]);
		i++;
	}
	pthread_mutex_destroy(&d->mtx_journal);	
	
	pthread_mutex_destroy(&d->mtx_all_living);	
}

/* ************************************************************************** */