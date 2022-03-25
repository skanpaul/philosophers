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
void create_philospher(t_data *d)
{
	int i;	
	
	d->philo = (t_philo *)malloc(d->max_philo * sizeof(t_philo));

	// Activer flag living: 
	i = 0;
	while (i < d->max_philo)
	{
		d->philo[i].living = true;
		i++;
	}
}

/* ************************************************************************** */
int give_life(t_data *d)
{
	int i;
	int res;

	i = 0;
	while (i < d->max_philo)
	{
		res = pthread_create(d->philo[i].id, NULL, &philo_life, (void *)d);
		if (res != 0)
			return (ERROR);
		i++;
	}
	return (NO_ERROR);
}

/* ************************************************************************** */