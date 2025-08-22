/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:43:04 by jait-chd          #+#    #+#             */
/*   Updated: 2025/08/08 15:53:06 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	setup_table(t_table *args, t_philo *philos, int i)
{
	philos[i].id = i + 1;
	philos[i].left = i;
	philos[i].right = (i + 1) % args->n;
	philos[i].access = args;
	philos[i].meals_eaten = 0;
	philos[i].last_meal_time = args->start_time;
}
