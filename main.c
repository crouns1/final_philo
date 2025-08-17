/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 23:25:18 by jait-chd          #+#    #+#             */
/*   Updated: 2025/08/11 14:19:15 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



int	main(int c, char **v)
{
	t_table	*table;
	if(!is_valid(c , v)) {
		printf("Eroor : you should enter a spesific arg\n");
		return 1;
	}
	table = init_shell(c ,v);
	if(!table)
		return 1;
	if(!setup_env(table))
		return 1;
	return (0);
}
