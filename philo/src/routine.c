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
#include <unistd.h>
#include <sys/time.h>

// sleep function without usleep, using a while loop
void	ft_sleep(int milliseconds)
{
	int	start;

	start = ft_get_time();
	while (ft_get_time() - start < milliseconds)
	{
		usleep(100);
	}
}

int	ft_get_time()
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	*routine(void *arg)
{
	t_thread_data	*thread_data;
	t_philo	*philo;
	t_philo	*next_philo;

	thread_data = arg;
	philo = thread_data->lst_philo->content;
	next_philo = thread_data->lst_philo->next->content;

	pthread_mutex_t	*m1;
	pthread_mutex_t	*m2;

	if (philo->n % 2) {
		m1 = &philo->fork;
		m2 = &next_philo->fork;
	} else {
		m1 = &next_philo->fork;
		m2 = &philo->fork;
	}

	while (1) {

		pthread_mutex_lock(m1);

		pthread_mutex_lock(&thread_data->data->mutex_write);
		ft_printf("%d %d has taken a fork\n", ft_get_time() - thread_data->data->start_time, philo->n);
		pthread_mutex_unlock(&thread_data->data->mutex_write);

		pthread_mutex_lock(m2);

		pthread_mutex_lock(&thread_data->data->mutex_write);
		ft_printf("%d %d has taken a fork\n", ft_get_time() - thread_data->data->start_time, philo->n);
		ft_printf("%d %d is eating\n", ft_get_time() - thread_data->data->start_time, philo->n);
		pthread_mutex_unlock(&thread_data->data->mutex_write);

		philo->last_meal = ft_get_time(); 

		ft_sleep(thread_data->data->time_to_eat);

		philo->meals_eaten++;

		pthread_mutex_unlock(m1);
		pthread_mutex_unlock(m2);

		pthread_mutex_lock(&thread_data->data->mutex_write);
		ft_printf("%d %d is sleeping\n", ft_get_time() - thread_data->data->start_time, philo->n);
		pthread_mutex_unlock(&thread_data->data->mutex_write);
		ft_sleep(thread_data->data->time_to_sleep);

		pthread_mutex_lock(&thread_data->data->mutex_write);
		ft_printf("%d %d is thinking\n", ft_get_time() - thread_data->data->start_time, philo->n);
		pthread_mutex_unlock(&thread_data->data->mutex_write);
	}
	return (NULL);
}

