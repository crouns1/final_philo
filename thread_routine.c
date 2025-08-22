/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:43:29 by jait-chd          #+#    #+#             */
/*   Updated: 2025/08/08 15:50:16 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void sleepo(t_philo *philo, long time)
{
	if(time >= philo->access->time_t_die * 1000)
	{
		usleep(philo->access->time_t_die * 1000);
		return;
	}
	else 
	{
		usleep(time);
		return;
	}
}

int	take_forks(t_philo *philo)
{
	if (philo->access->n == 1)
		return (0);
	if (philo->id % 2 == 0)
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
	long	current_time;

	if (check_death(philo))
		return ;
	current_time = time_stamp_sch();
	pthread_mutex_lock(&philo->access->set);
	if (philo->access->is_dead)
	{
		pthread_mutex_unlock(&philo->access->set);
		return ;
	}
	philo->last_meal_time = current_time;
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->access->set);
	print_status(philo, "is eating");
	sleepo(philo, philo->access->time_t_eat * 1000);
}

void	sleeping(t_philo *philo)
{
	if (check_death(philo))
		return ;
	print_status(philo, "is sleeping");
	sleepo(philo, philo->access->time_t_sleep * 1000);
}
