/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:52:58 by ngonzale          #+#    #+#             */
/*   Updated: 2023/03/05 13:55:52 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static size_t	ft_uilen_base(unsigned int n, size_t base_len)
{
	size_t	n_len;

	n_len = 0;
	if (n == 0)
		n_len = 1;
	while (n > 0)
	{
		n /= base_len;
		n_len++;
	}
	return (n_len);
}

char	*ft_uitoa_base(unsigned int n, char *base)
{
	char	*str;
	size_t	i;
	size_t	n_len;
	size_t	base_len;

	base_len = ft_strlen(base);
	n_len = ft_uilen_base(n, base_len);
	str = ft_calloc(n_len + 1, sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i < n_len)
	{
		str[n_len - 1 - i] = base[n % base_len];
		n /= base_len;
		i++;
	}
	return (str);
}

static size_t	ft_ulllen_base(unsigned long long n, size_t base_len)
{
	size_t	n_len;

	n_len = 0;
	if (n == 0)
		n_len = 1;
	while (n > 0)
	{
		n /= base_len;
		n_len++;
	}
	return (n_len);
}

char	*ft_ulltoa_base(unsigned long long n, char *base)
{
	char	*str;
	size_t	i;
	size_t	n_len;
	size_t	base_len;

	base_len = ft_strlen(base);
	n_len = ft_ulllen_base(n, base_len);
	str = ft_calloc(n_len + 1, sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i < n_len)
	{
		str[n_len - 1 - i] = base[n % base_len];
		n /= base_len;
		i++;
	}
	return (str);
}
