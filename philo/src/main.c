/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:36:37 by ngonzale          #+#    #+#             */
/*   Updated: 2023/02/17 18:48:3 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_wait_end_of_routine(void *content)
{
	t_philo	*philo;

	philo = content;
	pthread_join(philo->thread, NULL);
	pthread_mutex_destroy(&philo->fork);
	pthread_mutex_destroy(&philo->mutex_meals);
}

void	ft_check_philos_state(t_data *data)
{
	t_list	*tmp;
	t_philo	*philo;

	tmp = data->philos;
	while (tmp)
	{
		pthread_mutex_lock(&data->mutex_eaten);
		if (data->eaten == data->n_philos)
		{
			pthread_mutex_unlock(&data->mutex_eaten);
			break ;
		}
		pthread_mutex_unlock(&data->mutex_eaten);
		philo = tmp->content;
		pthread_mutex_lock(&philo->mutex_meals);
		if (philo->last_meal + data->time_to_die < ft_get_time())
		{
			ft_print_action(philo, "died");
			pthread_mutex_lock(&data->mutex_dead);
			data->dead = 1;
			pthread_mutex_unlock(&data->mutex_dead);
			pthread_mutex_unlock(&philo->mutex_meals);
			break ;
		}
		pthread_mutex_unlock(&philo->mutex_meals);
		if (tmp->next)
			tmp = tmp->next;
		else
			tmp = data->philos;
	}
}

void	ft_leaks()
{
	system("leaks -q philo");
}

int	main(int argc, char *argv[])
{
	atexit(ft_leaks);
	t_data		*data;

	data = ft_create_data(argc, argv);
	if (!data)
		return (1);
	data->start_time = ft_get_time();
	if (ft_start_philos(data) != 0)
	{
		ft_free_data(data);
		return (1);
	}
	ft_check_philos_state(data);
	ft_lstiter(data->philos, ft_wait_end_of_routine);
	if (data->meals_required == 0
		|| (!data->dead && data->eaten == data->n_philos))
		ft_printf("All philos have eaten %d times\n", data->meals_required);
	ft_free_data(data);
	return (0);
}
