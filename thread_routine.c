/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:43:29 by jait-chd          #+#    #+#             */
/*   Updated: 2025/08/22 13:56:00 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0 || philo->id == philo->access->n)
		return (take_forks_even(philo));
	else
		return (take_forks_odd(philo));
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->access->forks[philo->left]);
	pthread_mutex_unlock(&philo->access->forks[philo->right]);
}

void	eating(t_philo *philo)
{
	if (check_death(philo))
		return ;
	pthread_mutex_lock(&philo->access->set);
	philo->last_meal_time = time_stamp_sch();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->access->set);
	print_status(philo, "is eating");
	usleep(philo->access->time_t_eat * 1000);
}

void	sleeping(t_philo *philo)
{
	if (check_death(philo))
		return ;
	print_status(philo, "is sleeping");
	usleep(philo->access->time_t_sleep * 1000);
}
