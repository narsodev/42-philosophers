/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:40:27 by ngonzale          #+#    #+#             */
/*   Updated: 2023/03/05 13:55:52 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include "philo.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*s2;

	s2 = (char *) s;
	i = 0;
	while (i < n)
	{
		s2[i] = 0;
		i++;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i < s1_len)
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		str[i + s1_len] = s2[i];
		i++;
	}
	return (str);
}
