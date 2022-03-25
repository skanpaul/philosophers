/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:55:08 by ski               #+#    #+#             */
/*   Updated: 2022/03/22 11:55:09 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

/* ************************************************************************** */
void *philosopher(void *arg);

/* ************************************************************************** */
// int main(int argc, char **argv)
int main()
{
	int i;
	t_data	d;	

	
	d.n_philo = 3;	
	d.time_to_die = 10 * 1000;	// after the last meal
	d.time_to_eat = 2 * 1000;
	d.time_to_sleep = 5 * 1000;
	d.max_eat = 10 * 1000;

	/* ------------------------------------------------------ */
	pthread_mutex_init(&d.padlock, NULL);
	/* ------------------------------------------------------ */




	i = 0;
	while (i < d.n_philo)
	{
		
	}
	


	pthread_create(&d.id_philo, NULL, &philosopher, (void *)&d);

	pthread_join(d.id_philo, NULL);	









	/* ------------------------------------------------------ */
	pthread_mutex_destroy(&d.padlock);
	/* ------------------------------------------------------ */
	return (NO_ERROR);
}

/* ************************************************************************** */
void *philosopher(void *arg)
{
	t_data *d;

	d = (t_data *)arg;	
	/* ------------------------------------------------------ */

	pthread_mutex_lock(&d->padlock);
	// variable to protect or code to protect
	pthread_mutex_unlock(&d->padlock);

	/* ------------------------------------------------------ */
	return ((void *) NULL);
	return (NO_ERROR);
}

/* ************************************************************************** */


	// struct timeval chrono;

	// int ms1;
	// int ms2;


	// gettimeofday(&chrono, NULL);
	// ms1 = chrono.tv_usec;

	// gettimeofday(&chrono, NULL);
	// ms2 = chrono.tv_usec;

	// printf("ms1: %d\n", ms1);
	// printf("ms1: %d\n", ms2);


	// /* ------------------------------------------------------ */
	// if (argc != 5 && argc != 6)
	// {
	// 	write(1, TXT_ERR_ARG, ft_strlen(TXT_ERR_ARG));
	// 	return (ERROR);
	// }
	// /* ------------------------------------------------------ */
	// if((save_arg(argc, argv, &d)) == ERROR)
	// {
	// 	write(1, TXT_ERR_CNT, ft_strlen(TXT_ERR_CNT));
	// 	return (ERROR);
	// }
	// /* ------------------------------------------------------ */