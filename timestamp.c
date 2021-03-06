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
	p->stp_eat = timestamp;
	p->stp_sleep = p->stp_eat + p->d->time_eat;
	p->stp_think = p->stp_sleep + p->d->time_sleep;
	p->stp_died = p->stp_eat + p->d->time_die;
}

/* ************************************************************************** */