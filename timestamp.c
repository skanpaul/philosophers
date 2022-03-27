/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 13:19:03 by ski               #+#    #+#             */
/*   Updated: 2022/03/27 13:19:05 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

/* ************************************************************************** */
int get_timestamp()
{
	struct timeval chrono;

	gettimeofday(&chrono, NULL);

	return (chrono.tv_usec);
}

/* ************************************************************************** */
void set_all_timestamp_from_start_eating(t_philo *p)
{
	int timestamp;

	timestamp = get_timestamp();
	p->stamp_eat = timestamp;
	p->stamp_sleep = p->stamp_eat + p->d->time_to_eat;
	p->stamp_think = p->stamp_sleep + p->d->time_to_sleep;
	p->stamp_died = p->stamp_eat + p->d->time_to_die;
}

/* ************************************************************************** */