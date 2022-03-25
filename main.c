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

	init_data(&d); // A REMPLACER PAR LECTURE DE ARGC ET ARGV

	// CREER DONNEES PHILOSOPHERS
	if (   (philo = create_philospher(&d))    == NULL)
		return (ERROR);	

	// INITIALISER FOURCHETTE ET JOURNAL
	if ((init_fourchette(&d)) == ERROR)
		return (ERROR);

	// DONNER LA VIE AU PHILOSOPGHER



	// DES QU UN PHILOSOPHER MEURT, LE PROGRAMME S-ARRETE


	// DETRUIRE FOURCHETTE ET JOURNAL

	destroy_fourchette(&d);
}

/* ************************************************************************** */
void *philo_life(void *arg)
{
	t_data *d;

	d = (t_data *)arg;

	// LOOP: TANT QUE PHILO EST VIVANT ---------------------------------------

		// ATTENDRE FOURCHETTE POUR MANGER
			// timestamp

		// MANGER --> prendre le temps de manger --> TIMER DE MORT au début du repas
			// timestamp
		
		// DORMIR --> prendre le temps de dormir
			// timestamp

		// PENSER --> prendre le temps de penser
			// timestamp

	// END-LOOP --------------------------------------------------------------


	// EST MORT
		
		// timestamp


	return (arg);
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

