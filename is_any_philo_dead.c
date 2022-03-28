/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_any_philo_dead.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:08:24 by ski               #+#    #+#             */
/*   Updated: 2022/03/27 16:08:25 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

/* ************************************************************************** */
bool is_any_philo_dead(t_philo *p)
{
	bool answer;

	pthread_mutex_lock(&p->d->mtx_all_living);
	//-----------------------------------------
	if(p->d->all_living == true)
		answer = false;
	else
		answer = true;
	//-----------------------------------------
	pthread_mutex_unlock(&p->d->mtx_all_living);
	return (answer);
}

/* ************************************************************************** */