/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcreate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:48:17 by ngonzale          #+#    #+#             */
/*   Updated: 2023/03/04 19:48:23 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcreate(int n, void *(*f)(int), void (*del)(void *))
{
	t_list	*lst;
	t_list	*tmp;
	int		i;

	i = 0;
	lst = 0;
	while (i < n)
	{
		tmp = ft_lstnew(f(i));
		if (!tmp)
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		ft_lstadd_back(&lst, tmp);
		i++;
	}
	return (lst);
}
