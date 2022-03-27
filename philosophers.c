/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
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
		philo[i].id_philo = i + 1;
		philo[i].living = true;
		philo[i].d = d;
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
		res = pthread_create(&philo[i].id_thread, NULL, 
								&philo_life, (void *)&philo[i]);
		if (res != 0)
			return (ERROR);
		/* ------------------------------------------------------------- */
		res = pthread_detach(philo[i].id_thread);
		if (res != 0)
			return (ERROR);
		/* ------------------------------------------------------------- */
		i++;
		/* ------------------------------------------------------------- */
	}
	return (NO_ERROR);
}

/* ************************************************************************** */