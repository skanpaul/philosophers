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
int	mtx_init_all(pthread_mutex_t *mutex_fork_list, t_data *d)
{
	int i;

	i = 0;
	while (i < d->max_philo)
	{
		if((pthread_mutex_init(&mutex_fork_list[i], NULL)) != 0)
			return (ERROR);
		i++;
	}

	if (pthread_mutex_init(&d->mtx_printf, NULL) != 0)
		return (ERROR);

	if (pthread_mutex_init(&d->mtx_all_living, NULL) != 0)
		return (ERROR);

	return (NO_ERROR);
}

/* ************************************************************************** */
void mtx_destroy_all(pthread_mutex_t *mutex_fork_list, t_data *d)
{
	int i;

	i = 0;
	while (i < d->max_philo)
	{
		pthread_mutex_destroy(&mutex_fork_list[i]);
		i++;
	}
	pthread_mutex_destroy(&d->mtx_printf);	
	
	pthread_mutex_destroy(&d->mtx_all_living);	
}

/* ************************************************************************** */