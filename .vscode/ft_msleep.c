/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_this_philo_dead.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 14:40:12 by ski               #+#    #+#             */
/*   Updated: 2022/03/27 14:40:13 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

/* ************************************************************************** */
void ft_msleep(int time_ms)
{
    int time_us;

    time_us = time_ms * 1000;
    
    usleep(time_us);
}