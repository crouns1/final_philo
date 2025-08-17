/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jait-chd <jait-chd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:42:16 by jait-chd          #+#    #+#             */
/*   Updated: 2025/08/11 19:48:58 by jait-chd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo	t_philo;

typedef struct s_table
{
	int					n;
	int					time_t_eat;
	int					time_t_sleep;
	int					time_t_die;
	int					max_meals;
	int					is_dead;
	long				start_time;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print;
	pthread_mutex_t		set;
	t_philo				*philos;
}						t_table;

typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	int					left;
	int					right;
	int					meals_eaten;
	long				last_meal_time;
	t_table				*access;
}						t_philo;

// Argument parsing
int						is_valid(int ac, char **av);

int	is_valid_number(char *str);
int	ft_atoi(const char *str);

// Setup
t_table	*init_shell(int c, char **v);
int setup_env(t_table *table) ;
int					setup_mutexes(t_table *args);
void					destroy_mutexes(t_table *args);
void					setup_table(t_table *args, t_philo *philos, int i);

// Thread routines
void					*philo_routine(void *ptr);
void					*monitor(void *ptr);
int						create_threads(t_table *args, t_philo *philos);

// Actions
void					print_status(t_philo *philo, char *msg);
int						check_death(t_philo *philo);
int						all_philos_full(t_table *args);
int						take_forks_even(t_philo *philo);
int						take_forks_odd(t_philo *philo);
int						take_forks(t_philo *philo);
void					put_forks(t_philo *philo);
void					eating(t_philo *philo);
void					sleeping(t_philo *philo);
void					thinking(t_philo *philo);

// Time
long					time_stamp_sch(void);

#endif
