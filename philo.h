/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:56:26 by ski               #+#    #+#             */
/*   Updated: 2022/03/22 11:56:27 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H
/* ************************************************************************** */
# define	NO_ERROR	0
# define	ERROR		1
/* ************************************************************************** */
# define	TXT_ERR_ARG	"ERROR: wrong argument number\n"
# define	TXT_ERR_CNT	"ERROR: argument NOT countable\n"
/* ************************************************************************** */
# include <sys/time.h>
# include <stdio.h>
# include <stdbool.h>
# include <pthread.h>
# include <unistd.h>
/* ************************************************************************** */
typedef struct s_data
{
	int				n_philo;	
	int 			time_to_die;	// after the last meal
	int 			time_to_eat;
	int 			time_to_sleep;
	int 			max_eat;		//number_of_times_each_philosopher_must_eat;

} t_data;
/* ************************************************************************** */
typedef struct s_philo
{
	pthread_t		*id;
	pthread_mutex_t	*fourchette;
} t_philo;
/* ************************************************************************** */
int		ft_strlen(char *str);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
bool	is_countable(char *str);
int		save_arg(int argc, char **argv, t_data *d);

/* ************************************************************************** */

#endif


/* ------------------- */
// memset, printf, malloc, free, write,
// usleep, 
// gettimeofday, 
/* ------------------- */
// pthread_create, 
// pthread_detach, 
// pthread_join, 
/* ------------------- */
// pthread_mutex_init, 
// pthread_mutex_destroy, 
// pthread_mutex_lock, 
// pthread_mutex_unlock
/* ------------------- */