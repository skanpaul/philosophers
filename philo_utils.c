/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:54:33 by ski               #+#    #+#             */
/*   Updated: 2022/03/25 13:54:35 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"
/* ************************************************************************** */
t_philo *create_philospher(t_data *d)
{
	t_philo *philo;
	int i;	
	
	if((philo = (t_philo *)malloc(d->max_philo * sizeof(t_philo))) == NULL)
		return (NULL);
	i = 0;
	while (i < d->max_philo)
	{
		philo[i].id = i + 1;
		philo[i].living = true;
		philo[i].d = d;
		philo[i].stp_fork = get_timestamp();
		philo[i].stp_eat = philo[i].stp_fork;
		philo[i].stp_sleep = philo[i].stp_fork;
		philo[i].stp_think = philo[i].stp_fork;
		philo[i].stp_died = philo[i].stp_fork;
		i++;
	}
	return (philo);
}

/* ************************************************************************** */
int give_life(t_philo *philo, t_data *d)
{
	int i;
	int res;

	i = 0;
	while (i < d->max_philo)
	{
		/* ------------------------------------------------------------- */
		res = pthread_create(&philo[i].thread, NULL, 
								&thread_life, (void *)&philo[i]);
		if (res != 0)
			return (ERROR);
		/* ------------------------------------------------------------- */
		res = pthread_detach(philo[i].thread);
		if (res != 0)
			return (ERROR);
		/* ------------------------------------------------------------- */
		i++;
		/* ------------------------------------------------------------- */
	}
	return (NO_ERROR);
}

/* ************************************************************************** */