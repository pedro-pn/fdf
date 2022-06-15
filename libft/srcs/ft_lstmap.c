/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 23:36:32 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/04/17 01:49:54 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;

	if (lst != NULL)
	{
		new_lst = ft_lstnew((*f)(lst -> content));
		new_lst -> next = ft_lstmap(lst -> next, (*f), (*del));
	}
	else
		return (NULL);
	return (new_lst);
}
