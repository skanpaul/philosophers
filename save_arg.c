/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:02:51 by ski               #+#    #+#             */
/*   Updated: 2022/03/25 12:02:53 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

/* ************************************************************************** */
int save_arg(int argc, char **argv, t_data *d)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (!is_countable(argv[i]))
		{
			printf("one of the argument are not countable\n");
			return (ERROR);
		}
		i++;
	}
	d->max_philo = ft_atoi(argv[1]);
	d->time_die = ft_atoi(argv[2]);
	d->time_eat = ft_atoi(argv[3]);
	d->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		d->max_eat = ft_atoi(argv[5]);
	d->all_living		= true;
	return (NO_ERROR);
}

/* ************************************************************************** */