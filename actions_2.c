/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:14:28 by jait-chd          #+#    #+#             */
/*   Updated: 2025/08/10 20:14:07 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_forks_odd(t_philo *philo)
{
	pthread_mutex_lock(&philo->access->forks[philo->left]);
	if (check_death(philo))
	{
		pthread_mutex_unlock(&philo->access->forks[philo->left]);
		return (0);
	}
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->access->forks[philo->right]);
	if (check_death(philo))
	{
		pthread_mutex_unlock(&philo->access->forks[philo->left]);
		pthread_mutex_unlock(&philo->access->forks[philo->right]);
		return (0);
	}
	print_status(philo, "has taken a fork");
	return (1);
}
