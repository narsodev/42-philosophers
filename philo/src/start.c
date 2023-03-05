/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:53:17 by ngonzale          #+#    #+#             */
/*   Updated: 2023/03/05 14:29:11 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_start_philo(t_list *lst_philo)
{
	t_philo	*philo;

	philo = lst_philo->content;
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

void	ft_start_philos_error(t_data *data, t_list *philo_error)
{
	t_list	*tmp;

	pthread_mutex_lock(&data->mutex_dead);
	data->dead = 1;
	pthread_mutex_unlock(&data->mutex_dead);
	tmp = data->philos;
	while (tmp != philo_error)
	{
		pthread_detach(((t_philo *)tmp->content)->thread);
		pthread_mutex_destroy(&((t_philo *)tmp->content)->fork);
		pthread_mutex_destroy(&((t_philo *)tmp->content)->mutex_meals);
		tmp = tmp->next;
	}
}

int	ft_start_philos(t_data *data)
{
	t_list	*tmp;

	tmp = data->philos;
	while (tmp)
	{
		((t_philo *)tmp->content)->data = data;
		if (!ft_start_philo(tmp))
		{
			ft_start_philos_error(data, tmp);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
