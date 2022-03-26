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
int create_fourchette(t_data *d)
{
	d->fourchette = (pthread_mutex_t *) malloc(d->max_philo * sizeof(pthread_mutex_t));
	if (d->fourchette == NULL)
		return (ERROR);

	return (NO_ERROR);
}
/* ************************************************************************** */
int init_fourchette(t_data *d)
{
	int i;

	i = 0;
	while (i < d->max_philo)
	{
		if((pthread_mutex_init(&d->fourchette[i], NULL)) != 0)
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
		pthread_mutex_destroy(&d->fourchette[i]);
		i++;
	}
}

/* ************************************************************************** */
pthread_mutex_t init_f_gauche(pthread_mutex_t *f, t_philo *p)
{
	if (p->d->max_philo == 1)
		return (f[0]);
	else 
	{
		if (d)
	}
}


/* ************************************************************************** */
pthread_mutex_t init_f_droite(pthread_mutex_t *f, t_philo *p)
{
	if (p->d->max_philo == 1)
		return (f[0]);
	else
	{

	}
}

/* ************************************************************************** */