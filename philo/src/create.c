/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:52:08 by ngonzale          #+#    #+#             */
/*   Updated: 2023/02/18 19:29:37 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>

t_philo	*ft_create_philo(int n) {
	t_philo	*philo;

	philo = ft_calloc(1, sizeof(t_philo));
	if (!philo)
		return(NULL);
	philo->n = n + 1;
	philo->meals_eaten = 0;
	return (philo);
}


void	*ft_create_philo_wrapper(int n)
{
	return (ft_create_philo(n));
}

t_data	*ft_create_data(int argc, char *argv[])
{
	t_data	*data;

	if (argc != 5 && argc != 6)
		return (NULL);
	
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	data->n_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->start_time = ft_get_time();
	if (argc == 6)
		data->meals_required = ft_atoi(argv[5]);
	else
		data->meals_required = -1;
	data->philos = ft_lstcreate(data->n_philos, ft_create_philo_wrapper, ft_free_philo);
	if (!data->philos)
	{
		ft_free_data(data);
		return (NULL);
	}

	if (pthread_mutex_init(&data->mutex_write, NULL) != 0)
	{
		ft_free_data(data);
		return (NULL);
	}

	return (data);

}
