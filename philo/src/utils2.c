/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngonzale <ngonzale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:22:14 by ngonzale          #+#    #+#             */
/*   Updated: 2023/03/05 13:55:52 by ngonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
	lst = 0;
}

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = ft_calloc(1, sizeof(t_list));
	if (!lst)
		return (0);
	lst->content = content;
	lst->next = 0;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*l;

	if (!*lst)
		*lst = new;
	else
	{
		l = *lst;
		while (l->next)
			l = l->next;
		l->next = new;
	}
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	while (*lst)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next;
	}
}

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
