/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_finished.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:00:21 by ski               #+#    #+#             */
/*   Updated: 2022/03/27 14:00:23 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

/* ************************************************************************** */
bool has_finished_to_eat(t_philo *p)
{
	int timestamp;

	timestamp = get_timestamp();

	if (timestamp - p->stamp_eat >= p->d->time_to_eat)
		return (true);

	return (false);
}

/* ************************************************************************** */
bool has_finished_to_sleep(t_philo *p)
{
	int timestamp;

	timestamp = get_timestamp();

	if (timestamp - p->stamp_sleep >= p->d->time_to_sleep)
		return (true);

	return (false);
}

/* ************************************************************************** */