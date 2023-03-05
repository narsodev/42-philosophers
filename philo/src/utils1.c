/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:14:04 by ngonzale          #+#    #+#             */
/*   Updated: 2023/03/05 13:55:52 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_sleep(int milliseconds)
{
	int	start;

	start = ft_get_time();
	while (ft_get_time() - start < milliseconds)
		usleep(50);
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total_size;

	total_size = count * size;
	if (total_size < count && total_size < size)
		return (0);
	ptr = malloc(total_size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, total_size);
	return (ptr);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
