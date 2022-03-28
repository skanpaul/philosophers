/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_this_philo_dead.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:40:12 by ski               #+#    #+#             */
/*   Updated: 2022/03/27 14:40:13 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

/* ************************************************************************** */
bool is_this_philo_dead(t_philo *p)
{
	int timestamp;

	timestamp = get_timestamp();
	
	if (timestamp - p->stp_eat >= p->d->time_die)
		return (true);
	return (false);
}

/* ************************************************************************** */