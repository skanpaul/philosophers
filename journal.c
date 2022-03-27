/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   journal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:43:17 by ski               #+#    #+#             */
/*   Updated: 2022/03/27 12:43:19 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

/* ************************************************************************** */
void print_has_taken_a_fork(t_philo *p)
{
	pthread_mutex_lock(&p->d->mtx_journal);
	ft_printf("%d %d has take a fork\n", p->stamp_takefork, p->id_philo);
	pthread_mutex_unlock(&p->d->mtx_journal);
}

/* ************************************************************************** */
void print_is_eating(t_philo *p)
{
	pthread_mutex_lock(&p->d->mtx_journal);
	ft_printf("%d %d is eating\n", p->stamp_eat, p->id_philo);
	pthread_mutex_unlock(&p->d->mtx_journal);
}

/* ************************************************************************** */
void print_is_sleeping(t_philo *p)
{
	pthread_mutex_lock(&p->d->mtx_journal);
	ft_printf("%d %d is sleeping\n", p->stamp_sleep, p->id_philo);
	pthread_mutex_unlock(&p->d->mtx_journal);
}

/* ************************************************************************** */
void print_is_thinking(t_philo *p)
{
	pthread_mutex_lock(&p->d->mtx_journal);
	ft_printf("%d %d is thinking\n", p->stamp_think, p->id_philo);
	pthread_mutex_unlock(&p->d->mtx_journal);
}

/* ************************************************************************** */
void print_is_died(t_philo *p)
{
	pthread_mutex_lock(&p->d->mtx_journal);
	ft_printf("%d %d died\n", p->stamp_died, p->id_philo);
	pthread_mutex_unlock(&p->d->mtx_journal);
}
/* ************************************************************************** */

/* 
• Tout changement d’état d’un philosophe doit être formatté comme suit :

◦ timestamp_in_ms X has taken a fork 

◦ timestamp_in_ms X is eating

◦ timestamp_in_ms X is sleeping

◦ timestamp_in_ms X is thinking

◦ timestamp_in_ms X died 

*/
