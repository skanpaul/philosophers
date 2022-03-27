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
	

	// DONNÉES DU JEUX
	init_data(&d); 

	// CREER LES FOURCHETTES
	if((create_fourchette(&d)) == ERROR)
		return (ERROR);

	// INITIALISER FOURCHETTE ET JOURNAL
	if ((init_fourchette(&d)) == ERROR)
		return (ERROR);

	// CREER DONNEES PHILOSOPHERS
	if ((philo = create_philospher(&d)) == NULL)
		return (ERROR);	

	// DONNER LA VIE AU PHILOSOPGHER



	// DES QU UN PHILOSOPHER MEURT, LE PROGRAMME S-ARRETE


	// DETRUIRE FOURCHETTE ET JOURNAL
	destroy_fourchette(&d);

	return (NO_ERROR);
}

/* ************************************************************************** */
void *philo_life(void *arg)
{
	t_philo *philo;
	pthread_mutex_t *fourchette;
	pthread_mutex_t f_gauche;
	pthread_mutex_t f_droite;

	philo = (t_philo *)arg;
	fourchette = philo->d->fourchette;

	f_gauche = init_f_gauche(fourchette, philo);
	f_droite = init_f_gauche(fourchette, philo);

	// LOOP: TANT QUE PHILO EST VIVANT ---------------------------------------
	while (philo->living == true)
	{
		
		// A QUEL MOMENT LE PHILOSOPHER DOIT IL MANGER		
		
		// ATTENDRE FOURCHETTE GAUCHE ET DROITE POUR MANGER
		pthread_mutex_lock(&f_gauche);
		pthread_mutex_lock(&f_droite);


		
		pthread_mutex_lock(&f_droite);
		pthread_mutex_lock(&f_gauche);
			// timestamp

		// MANGER --> prendre le temps de manger --> TIMER DE MORT au début du repas
			// timestamp
		
		// DORMIR --> prendre le temps de dormir
			// timestamp

		// PENSER --> prendre le temps de penser
			// timestamp
	}
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

