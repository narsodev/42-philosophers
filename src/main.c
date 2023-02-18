
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

int	ft_start_philo(t_thread_data *thread_data)
{
	t_philo	*philo;

	philo = thread_data->lst_philo->content;
	philo->last_meal = ft_get_time();
	if (pthread_mutex_init(&philo->fork, NULL) != 0)
	{
		// free(philo);
		return (1);
	}
	if (pthread_create(&philo->thread, NULL, &routine, thread_data) != 0)
	{
		pthread_mutex_destroy(&philo->fork);
		// free(philo);
		return (1);
	}
	return (0);
}


void	ft_iter(void *content)
{
	t_philo	*philo;

	philo = content;
	if (pthread_join(philo->thread, NULL) != 0)
	{

	}
	ft_printf("Philo %d\n", philo->n);
}

void ft_leaks()
{
	system("leaks -q philosophers");
}

int	main(int argc, char *argv[])
{
	atexit(ft_leaks);
	// pthread_t	t1;
	// pthread_t	t2;
	t_data		*data;

	data = ft_create_data(argc, argv);
	if (!data)
		return (1);
	
	t_list	*tmp;
	t_thread_data	*thread_data;

	tmp = data->philos;
	while (1)
	{
		thread_data = ft_calloc(1, sizeof(t_thread_data));
		if (!thread_data)
		{
			ft_free_data(data);
			return (1);
		}
		thread_data->data = data;
		thread_data->lst_philo = tmp;

		if (!tmp->next)
			tmp->next = data->philos;
		if (ft_start_philo(thread_data) != 0)
			break;
		if (tmp->next == data->philos)
			break;
		tmp = tmp->next;
	}


	t_philo	*philo;
	tmp = data->philos;
	int philos_eaten = 0;
	while (1)
	{
		philo = tmp->content;
		if (philo->meals_eaten == data->meals_required)
			philos_eaten++;
		if (philos_eaten == data->n_philos)
		{
			pthread_mutex_lock(&thread_data->data->mutex_write);
			ft_printf("All philos have eaten %d times\n", philo->meals_eaten);
			exit(0);
			break;
		}
		if (philo->last_meal + data->time_to_die < ft_get_time())
		{
			pthread_mutex_lock(&thread_data->data->mutex_write);
			ft_printf("Philo %d died\n", philo->n);
			exit(0);
			break;
		}
		tmp = tmp->next;
	}

	pthread_join(((t_philo *)data->philos->content)->thread, NULL);
	pthread_join(((t_philo *)data->philos->next->content)->thread, NULL);

	return 1;
	// tmp->next = NULL;
	ft_lstiter(data->philos, ft_iter);
	ft_free_data(data);

	return (0);

/*
	pthread_mutex_init(&g_mutex, NULL);
	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		return (1);
	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
		return (1);
	if (pthread_join(t1, NULL) != 0)
		return (1);
	if (pthread_join(t2, NULL) != 0)
		return (1);
	pthread_mutex_destroy(&g_mutex);
	(void) argc;
	(void) argv;
	ft_printf("Hello world\n");
	return (1);
	*/
}
