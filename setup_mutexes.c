/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_mutexes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:42:53 by jait-chd          #+#    #+#             */
/*   Updated: 2025/08/11 17:44:12 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
int	setup_mutexes(t_table *args)
{
	int	i;

	i = 0;
	// pthread_mutex_t help;
	// memset(&help, 0, sizeof(help));
	// pthread_mutex_t *helppp = {0};
	// helppp = malloc(sizeof(pthread_mutex_t));
	args->forks = malloc(sizeof(pthread_mutex_t) * args->n);
	if (!args->forks)
		return 1;
	// args->print = help;
	// args->set = help;
	// args->forks = help;
	while (i < args->n)
	{
		if(!pthread_mutex_init(&args->forks[i], NULL))
			return 1;
		i++;
	}
	
	if(!pthread_mutex_init(&args->print, NULL))
		return 1;
	if(!pthread_mutex_init(&args->set, NULL))
		return 1;
	return 0;
}

void	destroy_mutexes(t_table *args)
{
	int	i;

	i = 0;
	while (i < args->n)
	{
		pthread_mutex_destroy(&args->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&args->print);
	pthread_mutex_destroy(&args->set);
	free(args->forks);
	free(args->philos);
	
}
