/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_mutexes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:42:53 by jait-chd          #+#    #+#             */
/*   Updated: 2025/08/10 21:45:30 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	setup_mutexes(t_table *args)
// {
// 	int	i;

// 	i = 0;
// 	args->forks = malloc(sizeof(pthread_mutex_t) * args->n);
// 	if (!args->forks)
// 			return 1;
// 	while (i < args->n)
// 	{
// 		if(!pthread_mutex_init(&args->forks[i], NULL))
// 			return 1;
// 		i++;
// 	}
// 	if(!pthread_mutex_init(&args->print, NULL))
// 		return 1;
// 	if(!pthread_mutex_init(&args->set, NULL))
// 		return 1;
// 	return 0;
// }
// setup_mutexes.c

int setup_mutexes(t_table *args)
{
    int i = 0;

    args->forks = malloc(sizeof(pthread_mutex_t) * args->n);
    if (!args->forks)
        return 0; // failure

    while (i < args->n) {
        if (pthread_mutex_init(&args->forks[i], NULL) != 0)
            return 0; // failure
        i++;
    }
    if (pthread_mutex_init(&args->print, NULL) != 0)
        return 0;
    if (pthread_mutex_init(&args->set, NULL) != 0)
        return 0;

    return 1; // SUCCESS  (matches setup_env's `if (!setup_mutexes(...))`)
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
