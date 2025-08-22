/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:45:50 by jait-chd          #+#    #+#             */
/*   Updated: 2025/08/08 15:48:58 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_table *args, t_philo *philos)
{
	int			i;
	pthread_t	monitor_thread;

	i = 0;
	while (i < args->n)
	{
		if (pthread_create(&philos[i].thread, NULL, philo_routine, &philos[i]))
			return (0);
		i++;
	}
	if (pthread_create(&monitor_thread, NULL, monitor, args))
		return (0);
	pthread_join(monitor_thread, NULL);
	i = 0;
	while (i < args->n)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	return (1);
}
