/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 01:43:42 by ngonzale          #+#    #+#             */
/*   Updated: 2023/03/05 13:55:52 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo.h"

char	*ft_flag_space(char *str)
{
	char	*s;

	if (*str == '-')
		return (str);
	s = ft_strjoin(" ", str);
	free(str);
	return (s);
}
