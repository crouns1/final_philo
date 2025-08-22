/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:41:20 by jait-chd          #+#    #+#             */
/*   Updated: 2025/08/10 21:53:46 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_philo_death(t_table *args, int i)
{
	long	current_time;
	long	last_meal;
	long	time_since_meal;

	pthread_mutex_lock(&args->set);
	if (args->is_dead)
	{
		pthread_mutex_unlock(&args->set);
		return (1);
	}
	current_time = time_stamp_sch();
	last_meal = args->philos[i].last_meal_time;
	time_since_meal = current_time - last_meal;
	if (time_since_meal >= args->time_t_die)
	{
		args->is_dead = 1;
		pthread_mutex_lock(&args->print);
		printf("%ld %d died\n", current_time - args->start_time,
			args->philos[i].id);
		pthread_mutex_unlock(&args->print);
		pthread_mutex_unlock(&args->set);
		return (1);
	}
	pthread_mutex_unlock(&args->set);
	return (0);
}

void	*monitor(void *ptr)
{
	t_table	*args;
	int		i;

	args = (t_table *)ptr;
	while (1)
	{
		i = 0;
		while (i < args->n)
		{
			if (check_philo_death(args, i))
				return (NULL);
			i++;
		}
		if (all_philos_full(args))
		{
			pthread_mutex_lock(&args->set);
			args->is_dead = 1;
			pthread_mutex_unlock(&args->set);
			return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}
