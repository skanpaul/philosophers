/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:55:08 by ski               #+#    #+#             */
/*   Updated: 2022/03/22 11:55:09 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

/* ************************************************************************** */
// int main(int argc, char **argv)
int main()
{
	t_data	d;	
	t_philo *philo_list;
	pthread_mutex_t *mtx_fork_list; 
	int wait_time;

	philo_list = NULL;
	mtx_fork_list = NULL;

	// 1) DONNÉES DU JEUX -----------------------------------------
	init_data(&d); 
	// ------------------------------------------------------------
	// if(save_arg(argc, argv, &d) == ERROR)
	// 	return (ERROR);
	// ------------------------------------------------------------
	if ((check_game_data(&d)) == ERROR)
		return (ERROR);

	wait_time = d.time_die / 10;
	// ------------------------------------------------------------

	// 2) CREER LES FOURCHETTES -----------------------------------
	if((mtx_fork_list = create_mtx_fork_set(&d)) == NULL)
		return (ERROR);
	d.mtx_fork_set = mtx_fork_list;

	// 3) INIT ALL MUTEX: 1) mtx_fork_set 2) mtx_printf 3) mtx_all_living
	if ((mtx_init_all(mtx_fork_list, &d)) == ERROR)
		return (ERROR);

	// 4) CREER DONNEES PHILOSOPHERS ------------------------------
	if ((philo_list = create_philospher(&d)) == NULL)
		return (ERROR);

	d.philo_list = philo_list;
	assign_fork_to_philo(mtx_fork_list, philo_list, &d);

	// 5) DONNER LA VIE AU PHILOSOPGHER ---------------------------
	if ((give_life(philo_list, &d)) == ERROR)
		return (ERROR);

	// 6) DES QU UN PHILOSOPHER MEURT, LE PROGRAMME S-ARRETE ------

	while (d.all_living)
	{
		usleep (d.time_die * 1000);
	}

	// DESTROY ALL MUTEX: 1) mtx_fork_set 2) mtx_printf 3) mtx_all_living
	mtx_destroy_all(mtx_fork_list, &d);

	if (mtx_fork_list)
		free(mtx_fork_list);
	if (philo_list)
		free(philo_list);
	
	return (NO_ERROR);
}

/* ************************************************************************** */

