/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:04:56 by ski               #+#    #+#             */
/*   Updated: 2022/03/27 14:04:58 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

/* ************************************************************************** */
void *thread_life(void *arg)
{
	t_philo *p;
	int wait_time;

	p = (t_philo *)arg;

	// p->fork_left = identify_fork_left(p->d->mtx_fork_set, p);
	// p->fork_right = identify_fork_right(p->d->mtx_fork_set, p);

	printf("PHILO [id:%d] is ALIVE\n", p->id);

	// LOOP: TANT QUE PHILO EST VIVANT ---------------------------------------
	while (1)
	// while (!is_any_philo_dead(p))
	{
		// ATTENDRE 1ere FOURCHETTE -------------------

		printf("PHILO [id:%d] WAIT fork left\n", p->id);
		pthread_mutex_lock(p->fork_left);
		printf("PHILO [id:%d] TOOK fork left\n", p->id);
		if (is_this_philo_dead(p))	goto is_dead; // IS DEAD?
		if (is_any_philo_dead(p)) return (arg);
		p->stp_fork = get_timestamp();
		print_has_taken_a_fork(p);

		// ATTENDRE 2eme FOURCHETTE -------------------
		pthread_mutex_lock(p->fork_right);
		if (is_this_philo_dead(p))	goto is_dead; // IS DEAD?
		if (is_any_philo_dead(p)) return (arg);
		p->stp_fork = get_timestamp();
		print_has_taken_a_fork(p);
		
		// MANGE
		set_all_timestamp_from_start_eating(p);
		print_is_eating(p);
		wait_time = p->d->time_eat;
		while (1)
		{
			wait_time = wait_time / 2;
			usleep(wait_time);
			if (is_this_philo_dead(p))	goto is_dead; // IS DEAD? ;
			if (is_any_philo_dead(p)) return (arg);
			if(has_finished_to_eat(p)) 	break;
		}

		// RENDRE FOURCHETTE
		pthread_mutex_lock(p->fork_right);
		pthread_mutex_lock(p->fork_left);

		// DORS
		print_is_sleeping(p);
		wait_time = p->d->time_sleep;
		while (1) 
		{
			wait_time = wait_time / 2;
			usleep(wait_time);
			if (is_this_philo_dead(p))	goto is_dead; // IS DEAD? ;
			if (has_finished_to_sleep(p))	break;
			if (is_any_philo_dead(p)) return (arg);
		}

		// PENSE
		wait_time = p->d->time_die - p->d->time_eat - p->d->time_sleep;
		wait_time = wait_time / 2;
		print_is_thinking(p);
		// ??? WHEN SHOULD THE PHILOSOPHE EAT
		usleep(wait_time);
		if (is_this_philo_dead(p))	goto is_dead; // IS DEAD? ;
		if (is_any_philo_dead(p)) return (arg);
					
	}
	// END-LOOP --------------------------------------------------------------

is_dead:
	// EST MORT
	print_is_died(p);
	p->living = false;

	pthread_mutex_lock(&p->d->mtx_all_living);
	p->d->all_living = false;
	pthread_mutex_lock(&p->d->mtx_all_living);


	printf("PHILO [id:%d] is DEAD\n", p->id);

	return (arg);
}


/* ************************************************************************** */


