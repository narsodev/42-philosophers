/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 21:03:29 by ngonzale          #+#    #+#             */
/*   Updated: 2023/03/04 17:01:38 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_check_meals(t_data *data)
{
	pthread_mutex_lock(&data->mutex_eaten);
	if (data->meals_required == 0 || data->eaten == data->n_philos)
	{
		pthread_mutex_unlock(&data->mutex_eaten);
		return (1);
	}
	pthread_mutex_unlock(&data->mutex_eaten);
	return (0);
}

int	ft_check_dead(t_data *data)
{
	pthread_mutex_lock(&data->mutex_dead);
	if (data->dead)
	{
		pthread_mutex_unlock(&data->mutex_dead);
		return (1);
	}
	pthread_mutex_unlock(&data->mutex_dead);
	return (0);
}


void	ft_print_action(t_philo *philo, char *str)
{
	if (ft_check_meals(philo->data) || ft_check_dead(philo->data))
		return ;
	pthread_mutex_lock(&philo->data->mutex_write);
	ft_printf("%d %d %s\n", ft_get_time() - philo->data->start_time, philo->n, str);
	pthread_mutex_unlock(&philo->data->mutex_write);
}
