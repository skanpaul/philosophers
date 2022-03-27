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
	t_philo *philo; 
	int wait_time;

	// 1) DONNÉES DU JEUX -----------------------------------------
	init_data(&d); 
	
	// if(save_arg(argc, argv, &d) == ERROR)
	// 	return (ERROR);

	if ((check_game_data(&d)) == ERROR)
		return (ERROR);

	wait_time = d.time_to_die / 10;
	// ------------------------------------------------------------

	// 2) CREER LES FOURCHETTES -----------------------------------
	if((create_mtx_fork_set(&d)) == ERROR)
		return (ERROR);

	// 3) INIT ALL MUTEX: 1) mtx_fork_set 2) mtx_journal 3) mtx_all_living
	if ((init_all_mutex(&d)) == ERROR)
		return (ERROR);

	// 4) CREER DONNEES PHILOSOPHERS ------------------------------
	if ((philo = create_philospher(&d)) == NULL)
		return (ERROR);	

	// 5) DONNER LA VIE AU PHILOSOPGHER ---------------------------
	if ((give_life(philo, &d)) == ERROR)
		return (ERROR);

	// 6) DES QU UN PHILOSOPHER MEURT, LE PROGRAMME S-ARRETE ------

	while (d.all_living) 
		usleep (wait_time);

	// DESTROY ALL MUTEX: 1) mtx_fork_set 2) mtx_journal 3) mtx_all_living
	destroy_all_mutex(&d);

	return (NO_ERROR);
}

/* ************************************************************************** */

