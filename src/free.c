/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:55:23 by ngonzale          #+#    #+#             */
/*   Updated: 2023/02/18 16:24:18 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdlib.h>

void	ft_free_philo(void *content)
{
	t_philo	*philo;

	if (!content)
		return ;
	philo = content;
	/*
	if (philo->fork)
	{

	}
	if (philo->thread)
	{
		if (pthread_detach(philo->thread) != 0)
		{
			ft_putstr_fd("Error detaching thread\n", 2);
		}
	}
	*/
	free(philo);
}

void	ft_free_data(t_data *data)
{
	if (data->philos)
		ft_lstclear(&data->philos, ft_free_philo);
	free(data);
}

