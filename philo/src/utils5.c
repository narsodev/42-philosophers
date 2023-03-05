/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:46:03 by ngonzale          #+#    #+#             */
/*   Updated: 2023/03/05 13:55:52 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*ft_strdup(const char *s1)
{
	size_t	s_len;
	size_t	i;
	char	*str;

	s_len = ft_strlen(s1);
	str = (char *) ft_calloc(s_len + 1, sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i < s_len)
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start > s_len)
	{
		substr = ft_calloc(1, sizeof(char));
		if (!substr)
			return (0);
		return (substr);
	}
	if (s_len - start < len)
		len = s_len;
	substr = ft_calloc(len + 1, sizeof(char));
	if (!substr)
		return (0);
	i = 0;
	while (i < len && s[i + start])
	{
		substr[i] = s[i + start];
		i++;
	}
	return (substr);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char) c;
		i++;
	}
	return (b);
}

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *) s;
	while (*p)
	{
		if (*p == (char) c)
			return (p);
		p++;
	}
	if (!c)
		return (p);
	return (0);
}

char	*ft_c_to_str(char c)
{
	char	*s;

	s = ft_calloc(2, sizeof(char));
	if (s)
		*s = c;
	return (s);
}
