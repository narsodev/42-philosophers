/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:52:08 by ngonzale          #+#    #+#             */
/*   Updated: 2023/03/04 18:06:48 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philosophers.h"
#include <stdlib.h>

t_philo	*ft_create_philo(int n)
{
	t_philo	*philo;

	philo = ft_calloc(1, sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->n = n + 1;
	philo->meals_eaten = 0;
	return (philo);
}

void	*ft_create_philo_wrapper(int n)
{
	return (ft_create_philo(n));
}

int	ft_init_data_mutexes(t_data *data)
{
	if (pthread_mutex_init(&data->mutex_write, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&data->mutex_eaten, NULL) != 0)
	{
		pthread_mutex_destroy(&data->mutex_write);
		return (0);
	}
	if (pthread_mutex_init(&data->mutex_dead, NULL) != 0)
	{
		pthread_mutex_destroy(&data->mutex_write);
		pthread_mutex_destroy(&data->mutex_eaten);
		return (0);
	}
	return (1);
}

int	ft_set_data_args(int argc, char *argv[], t_data *data)
{
	int	error;

	error = 0;
	if (argc != 5 && argc != 6)
	{
		ft_putstr_fd("Error: 4 or 5 arguments required\n", 2);
		return (0);
	}
	data->n_philos = ft_atoic(argv[1], &error);
	data->time_to_die = ft_atoic(argv[2], &error);
	data->time_to_eat = ft_atoic(argv[3], &error);
	data->time_to_sleep = ft_atoic(argv[4], &error);
	if (argc == 6)
		data->meals_required = ft_atoic(argv[5], &error);
	else
		data->meals_required = -1;
	if (error || data->n_philos < 1 || data->time_to_die < 0
		|| data->time_to_eat < 0 || data->time_to_sleep < 0
		|| (argc == 6 && data->meals_required < 0))
	{
		ft_putstr_fd("Error: invalid arguments\n", 2);
		return (0);
	}
	return (1);
}

t_data	*ft_create_data(int argc, char *argv[])
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (NULL);
	if (!ft_set_data_args(argc, argv, data))
	{
		free(data);
		return (NULL);
	}
	if (!ft_init_data_mutexes(data))
	{
		free(data);
		return (NULL);
	}
	data->philos = ft_lstcreate(data->n_philos,
			ft_create_philo_wrapper, ft_free_philo);
	if (!data->philos)
	{
		ft_free_data(data);
		return (NULL);
	}
	return (data);
}
