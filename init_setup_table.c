/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_setup_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 21:40:20 by jait-chd          #+#    #+#             */
/*   Updated: 2025/08/11 14:19:15 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	*init_shell(int c, char **v)
{
	t_table	*shell;
	t_philo	*philos;

	shell = malloc(sizeof(t_table));
	if (!shell)
		return (NULL);
	shell->n = ft_atoi(v[1]);
	shell->time_t_die = ft_atoi(v[2]);
	shell->time_t_eat = ft_atoi(v[3]);
	shell->time_t_sleep = ft_atoi(v[4]);
	if (c == 6)
		shell->max_meals = ft_atoi(v[5]);
	else
		shell->max_meals = -1;
	shell->is_dead = 0;
	shell->start_time = time_stamp_sch();
	philos = malloc(sizeof(t_philo) * shell->n);
	if (!philos)
	{
		free(shell);
		return (NULL);
	}
	shell->philos = philos;
	return (shell);
}

int	setup_env(t_table *table)
{
	int	i;

	i = 0;
	if (!setup_mutexes(table))
		return (0);
	while (i < table->n)
	{
		setup_table(table, table->philos, i);
		i++;
	}
	if (!create_threads(table, table->philos))
	{
		destroy_mutexes(table);
		return (0);
	}
	destroy_mutexes(table);
	return (1);
}
