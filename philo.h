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
# define	DISPLAY_INFO	1
/* ************************************************************************** */
# define	NO_ERROR	0
# define	ERROR		1
/* ************************************************************************** */
# define	TXT_ERR_ARG	"ERROR: wrong argument number\n"
# define	TXT_ERR_CNT	"ERROR: argument NOT countable\n"
/* ************************************************************************** */
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <unistd.h>
# include <stdarg.h>
/* ************************************************************************** */
typedef struct s_data t_data;
typedef struct s_philo t_philo;
/* ************************************************************************** */
typedef struct s_data
{
	/* -------------------------- */
	int				max_philo;	
	int 			time_die;	// after the last meal
	int 			time_eat;
	int 			time_sleep;
	int 			max_eat;		//number_of_times_each_philosopher_must_eat;
	/* -------------------------- */
	bool			all_living;
	t_philo			*philo_list;
	/* -------------------------- */
	pthread_mutex_t	*mtx_fork_set;
	pthread_mutex_t mtx_printf;
	pthread_mutex_t mtx_all_living;
	/* -------------------------- */
} t_data;
/* ************************************************************************** */
typedef struct s_philo
{
	/* -------------------------- */
	pthread_t	thread;
	/* -------------------------- */
	int		id;
	bool	living;
	/* -------------------------- */
	pthread_mutex_t *fork_left;
	pthread_mutex_t *fork_right;
	/* -------------------------- */
	int		stp_fork;
	int		stp_eat;
	int		stp_sleep;
	int		stp_think;
	int		stp_died;
	/* -------------------------- */
	t_data			*d;
	/* -------------------------- */
} t_philo;
/* ************************************************************************** */
void	init_data(t_data *d);
int		check_game_data(t_data *d);
int		save_arg(int argc, char **argv, t_data *d);
/* -------------------------------------------------------------------------- */
t_philo	*create_philospher(t_data *d);
int		give_life(t_philo *philo, t_data *d);
void 	*thread_life(void *arg);
/* -------------------------------------------------------------------------- */
pthread_mutex_t *create_mtx_fork_set(t_data *d);
// int		create_mtx_fork_set(t_data *d);
void	assign_fork_to_philo(pthread_mutex_t *f, t_philo *p, t_data *d);
/* -------------------------------------------------------------------------- */
int		mtx_init_all(pthread_mutex_t *mutex_fork_list, t_data *d);
void	mtx_destroy_all(pthread_mutex_t *mutex_fork_list, t_data *d);
/* -------------------------------------------------------------------------- */
bool	is_this_philo_dead(t_philo *p);
bool	is_any_philo_dead(t_philo *p);
/* -------------------------------------------------------------------------- */
int		get_timestamp();
void	set_all_timestamp_from_start_eating(t_philo *p);
/* -------------------------------------------------------------------------- */
void 	print_has_taken_a_fork(t_philo *p);
void 	print_is_eating(t_philo *p);
void 	print_is_sleeping(t_philo *p);
void 	print_is_thinking(t_philo *p);
void	print_is_died(t_philo *p);
/* -------------------------------------------------------------------------- */
bool	has_finished_to_eat(t_philo *p);
bool	has_finished_to_sleep(t_philo *p);
/* -------------------------------------------------------------------------- */
int		ft_strlen(char *str);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
bool	is_countable(char *str);
void	ft_msleep(int time_ms);
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
