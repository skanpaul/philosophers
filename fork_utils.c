/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:02:17 by ski               #+#    #+#             */
/*   Updated: 2022/03/27 16:02:19 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

/* ************************************************************************** */
int create_mtx_fork_set(t_data *d)
{
	d->mtx_fork_set = (pthread_mutex_t *) malloc(d->max_philo * sizeof(pthread_mutex_t));
	if (d->mtx_fork_set == NULL)
		return (ERROR);

	return (NO_ERROR);
}

/* ************************************************************************** */
pthread_mutex_t identify_fork_left(pthread_mutex_t *f, t_philo *p)
{
	pthread_mutex_t f_gauche;
	f_gauche = f[p->id_philo - 1];
	return (f_gauche);
}

/* ************************************************************************** */
pthread_mutex_t identify_fork_right(pthread_mutex_t *f, t_philo *p)
{
	pthread_mutex_t f_droite;

	// POUR QU UN SEUL PHILOSOPERS
	if (p->d->max_philo == 1)
		f_droite = f[0];
	else // POUR 2 PHILOSOPHERS OU PLUS
	{
		// LE DERNIER
		if (p->id_philo == p->d->max_philo)		
			f_droite = f[0];
		// ENTRE LE 2EME ET L-AVANT DERNIER
		else 
			f_droite = f[p->id_philo];
	}
	return (f_droite);
}

/* ************************************************************************** */