/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routine_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:43:44 by jait-chd          #+#    #+#             */
/*   Updated: 2025/08/08 16:06:28 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo)
{
	if (check_death(philo))
		return ;
	print_status(philo, "is thinking");
	usleep(1000);
}

void	*philo_routine(void *ptr)

{
	t_philo *philo;

	philo = (t_philo *)ptr;
	//geter
	if (philo->id % 2 == 0 || philo->id == philo->access->n)
		usleep(1000);
	if (philo->access->n == 1)
	{
		print_status(philo, "has taken a fork");
		usleep(philo->access->time_t_die * 1000);
		return (NULL);
	}
	while (!check_death(philo))
	{
		if (take_forks(philo))
		{
			eating(philo);
			put_forks(philo);
		}
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
