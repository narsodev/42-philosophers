/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:53:17 by ngonzale          #+#    #+#             */
/*   Updated: 2023/03/04 18:53:24 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_start_philo(t_list *lst_philo)
{
	t_philo	*philo;

	philo = lst_philo->content;
	philo->last_meal = ft_get_time();
	if (pthread_mutex_init(&philo->fork, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&philo->mutex_meals, NULL) != 0)
	{
		pthread_mutex_destroy(&philo->fork);
		return (0);
	}
	if (pthread_create(&philo->thread, NULL, &routine, lst_philo) != 0)
	{
		pthread_mutex_destroy(&philo->fork);
		pthread_mutex_destroy(&philo->mutex_meals);
		return (0);
	}
	return (1);
}

int	ft_start_philos(t_data *data)
{
	t_list	*tmp;
	t_list	*tmp_cleaner;

	tmp = data->philos;
	while (tmp)
	{
		((t_philo *)tmp->content)->data = data;
		if (!ft_start_philo(tmp))
		{
			tmp_cleaner = data->philos;
			while (tmp_cleaner != tmp)
			{
				pthread_detach(((t_philo *)tmp_cleaner->content)->thread);
				pthread_mutex_destroy(&((t_philo *)tmp_cleaner->content)->fork);
				pthread_mutex_destroy(
					&((t_philo *)tmp_cleaner->content)->mutex_meals);
				tmp_cleaner = tmp_cleaner->next;
			}
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
