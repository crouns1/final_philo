/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 23:25:18 by jait-chd          #+#    #+#             */
/*   Updated: 2025/08/22 14:02:12 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int c, char **v)
{
	t_table	*table;

	if (!is_valid(c, v))
	{
		printf("Eroor : you should enter a spesific arg\n");
		return (1);
	}
	table = init_env(c, v);
	if (!table)
		return (1);
	if (!setup_env(table))
		return (1);
	return (0);
}
