/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:56:08 by ngonzale          #+#    #+#             */
/*   Updated: 2023/02/18 16:57: by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_philo_eat(t_data *data, t_philo *philo,
	pthread_mutex_t *m1, pthread_mutex_t *m2)
{
	pthread_mutex_lock(m1);
	ft_print_action(philo, "has taken a fork");
	if (m1 == m2)
	{
		pthread_mutex_unlock(m1);
		return (1);
	}
	pthread_mutex_lock(m2);
	ft_print_action(philo, "has taken a fork");
	ft_print_action(philo, "is eating");
	pthread_mutex_lock(&philo->mutex_meals);
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(&philo->mutex_meals);
	ft_sleep(data->time_to_eat);
	philo->meals_eaten++;
	if (philo->meals_eaten == data->meals_required)
	{
		pthread_mutex_lock(&data->mutex_eaten);
		data->eaten++;
		pthread_mutex_unlock(&data->mutex_eaten);
	}
	pthread_mutex_unlock(m1);
	pthread_mutex_unlock(m2);
	return (0);
}

void	ft_philo_life(t_data *data, t_philo *philo,
	pthread_mutex_t *m1, pthread_mutex_t *m2)
{
	while (!ft_check_meals(data) && !ft_check_dead(data))
	{
		if (ft_philo_eat(data, philo, m1, m2))
			break ;
		ft_print_action(philo, "is sleeping");
		ft_sleep(data->time_to_sleep);
		ft_print_action(philo, "is thinking");
	}
}

void	*routine(void *arg)
{
	t_list	*lst_philo;
	t_philo	*philo;
	t_philo	*next_philo;
	t_data	*data;

	lst_philo = arg;
	philo = lst_philo->content;
	data = philo->data;
	if (lst_philo->next)
		next_philo = lst_philo->next->content;
	else
		next_philo = data->philos->content;
	if (philo->n % 2)
		ft_philo_life(data, philo, &philo->fork, &next_philo->fork);
	else
		ft_philo_life(data, philo, &next_philo->fork, &philo->fork);
	return (NULL);
}
