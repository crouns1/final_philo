/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routine_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:43:44 by jait-chd          #+#    #+#             */
/*   Updated: 2025/08/12 01:00:56 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo)
{
	long	think_time;

	if (check_death(philo))
		return ;
	print_status(philo, "is thinking");
	if (philo->access->n % 2 == 1)
	{
		think_time = philo->access->time_t_eat * 2 - philo->access->time_t_sleep;
		if (think_time > 0)
			sleepo(philo, think_time * 1000);
		else
			sleepo(philo, 500);
	}
	else
	{
		think_time = philo->access->time_t_eat - philo->access->time_t_sleep;
		if (think_time > 0)
			usleep(think_time * 1000);
		else
			usleep(100);
	}
}

void	*philo_routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		usleep(1000);
	if (philo->access->n == 1)
	{
		print_status(philo, "has taken a fork");
		usleep(philo->access->time_t_die * 1000);
		return (NULL);
	}
	while (!check_death(philo))
	{
		if (!take_forks(philo))
			break ;
		eating(philo);
		put_forks(philo);
		if (check_death(philo))
			break ;
		sleeping(philo);
		if (check_death(philo))
			break ;
		thinking(philo);
	}
	return (NULL);
}
