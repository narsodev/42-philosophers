/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:35:52 by ngonzale          #+#    #+#             */
/*   Updated: 2023/02/23 21:42:55 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "libft.h"
# include <pthread.h>

typedef struct s_data {
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_required;
	pthread_mutex_t	mutex_write;
	pthread_mutex_t	mutex_eaten;
	int				eaten;
	pthread_mutex_t	mutex_dead;
	int			dead;
	int				start_time;
	t_list *philos;
}			t_data;

typedef struct s_philo {
	pthread_t					thread;
	int								last_meal;
	int								meals_eaten;
	int								n;
	pthread_mutex_t		fork;
	pthread_mutex_t		mutex_meals;
	t_data						*data;
}			t_philo;

// Create
t_data	*ft_create_data(int argc, char *argv[]);

// Free
void	ft_free_philo(void *content);
void	ft_free_data(t_data *data);

// Routine
void	*routine(void *arg);

// Utils
int ft_get_time();
void	ft_sleep(int milliseconds);




int	ft_check_meals(t_data *data);
int	ft_check_dead(t_data *data);

void	ft_print_action(t_philo *philo, char *str);

#endif
